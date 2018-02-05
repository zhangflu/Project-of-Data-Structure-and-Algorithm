#include "Runway5.hpp"
Runway5::Runway5(int limit):Runway(limit) {

}

Runway_activity Runway5::activity(int time, Plane &moving) {
	Runway_activity in_progress;
	if (landing.empty() && takeoff.empty()) {
		idle_time++;
		in_progress = idle;
	}
	else if (landing.empty()) {
		takeoff.retrieve(moving);
		takeoff_wait += time - moving.started();
		num_takeoffs++;
		in_progress = takeoff_;
		takeoff.serve();
	}
	else {
		in_progress = land;
		num_landings++;
		vector<Plane*> whole = landing.whole();
		for (int i = 0; i < whole.size(); ++i)
			whole[i]->wait();
		int save = 0;

		vector<int> index;
		for (int i = 0; i < whole.size(); ++i)
			if (i - whole[i]->fuelValue() > 1 || whole[i]->fuelValue() == -1)
				index.push_back(i);
		bool already = false;
		if (index.size()) {
			int min = whole[index[0]]->fuelValue();
			save = index[0];
			if (min == -1)
				already = true;
			for (int i = 1; i < index.size(); ++i) {
				int tem = whole[index[i]]->fuelValue();
				if (tem == -1) {
					if (already) {
						in_progress = crash;
						break;
					}
					already = true;
				}
				if (tem < min) {
					min = tem;
					save = index[i];
				}
			}
		}

		moving = *whole[save];
		land_wait += time - moving.started();
		landing.erease(save);
	}
	return in_progress;
}