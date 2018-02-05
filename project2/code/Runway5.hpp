#ifndef RUNWAY5_HPP
#define RUNWAY5_HPP
#include "Runway.hpp"
#include <vector>
using namespace std;

class Runway5 : public Runway {
public:
	Runway5(int limit);
	virtual Runway_activity activity(int time, Plane &moving);
};

#endif