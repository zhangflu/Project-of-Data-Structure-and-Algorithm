#ifndef RUNWAY4_HPP
#define RUNWAY4_HPP
#include "Runway.hpp"

class Runway4 : public Runway {
public:
	Runway4(int limit);
	Runway_activity activity(int time, Plane &moving);
private:
	int current;
	int landNum, takeoffNum;
};

#endif