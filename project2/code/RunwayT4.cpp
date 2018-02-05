#include "RunwayT4.hpp"
using namespace std;

RunwayT4::RunwayT4(int limit) : Runway(limit) {
	idle_arrival_time = 0;
	idle_departure1_time = 0;
	idle_departure2_time = 0;
	count_runway = 0;
	runway_num = 3;
}

Runway_activity RunwayT4::activity(int time, Plane & moving) {
	Runway_activity in_progress = idle;
	if (landing.empty() && takeoff.empty()) {
		if (count_runway%runway_num == 0) {
			idle_time++;
			idle_departure1_time++;
			idle_departure2_time++;
			idle_arrival_time++;
		}
		in_progress = idle;
	}
	else {
		if (count_runway%runway_num == 0) {
			if (!landing.empty()) {
				landing.retrieve(moving);
				land_wait += time - moving.started();
				num_landings++;
				in_progress = land;
				landing.serve();
			}
			else {
				idle_arrival_time++;
			}
		}
		else if (count_runway%runway_num == 1) {
			if (!takeoff.empty()) {
				takeoff.retrieve(moving);
				takeoff_wait += time - moving.started();
				num_takeoffs++;
				in_progress = takeoff_;
				takeoff.serve();
			}
			else {
				idle_departure1_time++;
			}
		}
		else {
			if (!landing.empty()) {
				landing.retrieve(moving);
				land_wait += time - moving.started();
				num_landings++;
				in_progress = land;
				landing.serve();
			}
			else if (!takeoff.empty()) {
				takeoff.retrieve(moving);
				takeoff_wait += time - moving.started();
				num_takeoffs++;
				in_progress = takeoff_;
				takeoff.serve();
			}
			else {
				idle_departure2_time++;
			}
		}
	}
	count_runway++;
	return in_progress;
}

void RunwayT4::shut_down(int time) const {
	cout << "T4 situation:\n";
	Runway::shut_down(time);
	cout << "Percentage of time arrival runway idle "
		<< 100.0 * ((float)idle_arrival_time) / ((float)time) << "%" << endl;
	cout << "Percentage of time departure runway1 idle "
		<< 100.0 * ((float)idle_departure1_time) / ((float)time) << "%" << endl;
	cout << "Percentage of time departure runway2 idle "
		<< 100.0 * ((float)idle_departure2_time) / ((float)time) << "%" << endl;
}

int RunwayT4::get_runway_num() const {
	return runway_num;
}
