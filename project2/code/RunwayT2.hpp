#ifndef RUNWAYT2_HPP
#define RUNWAYT2_HPP
#include <iostream>
#include "Runway.hpp"
class RunwayT2 :public Runway {
private:
	int idle_arrival_time;
	int idle_departure_time;
	int count_runway;
	int runway_num;
public:
	RunwayT2(int limit);
	virtual Runway_activity activity(int time, Plane &moving);
	virtual void shut_down(int time) const;
	int get_runway_num() const;
};
using namespace std;
#endif
