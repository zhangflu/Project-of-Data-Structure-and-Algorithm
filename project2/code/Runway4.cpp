#include "Runway4.hpp"
#include <iostream>
using namespace std;
Runway4::Runway4(int limit):Runway(limit)
/* Post: The Runway data members are initialized to record no prior Runway use
and to record the limit on queue sizes. */
{
	current = -1;
	landNum = takeoffNum = 2;
}

Runway_activity Runway4::activity(int time, Plane &moving)
/* Post: If the landing Queue has entries, its front Plane is copied to the parameter
moving and a result land is returned. Otherwise, if the takeoff Queue has
entries, its front Plane is copied to the parameter moving and a result
takeoff is returned. Otherwise, idle is returned. Runway statistics are
updated.
Uses: class Extended_queue. */
{
	if (current != time) {
		current = time;
		landNum = takeoffNum = 2;
	}
	Runway_activity in_progress;
	if (!landing.empty() && landNum) {
		landing.retrieve(moving);
		land_wait += time - moving.started();
		num_landings++;
		in_progress = land;
		landing.serve();
		landNum--;
	}
	else if (!takeoff.empty() && takeoffNum) {
		takeoff.retrieve(moving);
		takeoff_wait += time - moving.started();
		num_takeoffs++;
		in_progress = takeoff_;
		takeoff.serve();
		takeoffNum--;
	}
	else {
		idle_time++;
		in_progress = idle;
	}
	return in_progress;
}