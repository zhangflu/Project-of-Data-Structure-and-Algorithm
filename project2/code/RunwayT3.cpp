#include "RunwayT3.hpp"

RunwayT3::RunwayT3(int limit) : Runway(limit) {
	idle_arrival_time = 0;
	idle_departure_time = 0;
	count_runway = 0;
	runway_num = 2;
	idle_count = 0;
	urgent = false;
}

Runway_activity RunwayT3::activity(int time, Plane & moving){
	Runway_activity in_progress = idle;
	if (landing.empty()) {
		if (!takeoff.empty()) {
			takeoff.retrieve(moving);
			takeoff_wait += time - moving.started();
			num_takeoffs++;
			in_progress = takeoff_;
			takeoff.serve();
		}
		else {
			if(count_runway%runway_num == 0){
				idle_departure_time++;
				idle_count++;
			}
			else{
				idle_arrival_time++;
				if(idle_count==1){
					idle_count = 0;
					idle_time++;
				}
			}
			in_progress = idle;
		}
	}
	else if (urgent || landing.size() == queue_limit) {
		landing.retrieve(moving);
		land_wait += time - moving.started();
		num_landings++;
		in_progress = land;
		landing.serve();
		urgent = false;
	}
	else {
		if (!takeoff.empty()) {
			if (count_runway%runway_num == 0) {
				landing.retrieve(moving);
				land_wait += time - moving.started();
				num_landings++;
				in_progress = land;
				landing.serve();
			}
			if (count_runway%runway_num == 1) {
				takeoff.retrieve(moving);
				takeoff_wait += time - moving.started();
				num_takeoffs++;
				in_progress = takeoff_;
				takeoff.serve();
			}
		}
		else {
			landing.retrieve(moving);
			land_wait += time - moving.started();
			num_landings++;
			in_progress = land;
			landing.serve();
		}
	}
	count_runway++;
	return in_progress;
}

void RunwayT3::shut_down(int time) const{
	cout << "T3 situation:\n";
	Runway::shut_down(time);
	cout << "Percentage of time arrival runway idle "
		<< 100.0 * ((float)idle_arrival_time) / ((float)time) << "%" << endl;
	cout << "Percentage of time departure runway idle "
		<< 100.0 * ((float)idle_departure_time) / ((float)time) << "%" << endl;
}

int RunwayT3::get_runway_num() const{
	return runway_num;
}

Error_code RunwayT3::can_land(const Plane & current){
	Error_code result;
	if (landing.size() < queue_limit)
		result = landing.append(current);
	else if (landing.size() == queue_limit) {
		result = landing.append(current);
		urgent = true;
	}
	else
		result = overflow;
	num_land_requests++;
	if (result != success)
		num_land_refused++;
	else
		num_land_accepted++;
	return result;
}
