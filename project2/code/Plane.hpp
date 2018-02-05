#ifndef PLANE_HPP
#define PLANE_HPP

enum Plane_status {null, arriving, departing};
class Plane {
public:
	Plane( );
	Plane(int flt, int time, Plane_status status, int fuel);
	void refuse( ) const;
	void land(int time) const;
	void fly(int time) const;
	int started( ) const;

	int fuelValue();
	void wait();
private:
	int flt_num;
	int clock_start;
	Plane_status state;

	int fuel;
};

#endif