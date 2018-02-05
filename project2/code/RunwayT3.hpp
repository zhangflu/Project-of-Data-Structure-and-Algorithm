#ifndef RUNWAYT3_HPP
#define RUNWAYT3_HPP
#include <iostream>
#include "Runway.hpp"
class RunwayT3 :public Runway {
private:
	int idle_arrival_time;
	int idle_departure_time;
	int count_runway;
	int runway_num;
	int idle_count;
	bool urgent;
public:
	RunwayT3(int limit);
	virtual Runway_activity activity(int time, Plane &moving);
	virtual void shut_down(int time) const;
	int get_runway_num() const;
	virtual Error_code can_land(const Plane &current);
};
using namespace std;
#endif
