#ifndef RUNWAYT4_HPP
#define RUNWAYT4_HPP
#include <iostream>
#include "Runway.hpp"
class RunwayT4 :public Runway {
private:
	int idle_arrival_time;
	int idle_departure1_time;
	int idle_departure2_time;
	int count_runway;
	int runway_num;
public:
	RunwayT4(int limit);
	virtual Runway_activity activity(int time, Plane &moving);
	virtual void shut_down(int time) const;
	int get_runway_num() const;
};
using namespace std;
#endif
