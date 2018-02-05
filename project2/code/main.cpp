#include <iostream>
#include <cstdlib>
#include "Test.hpp"
#include "Plane.hpp"
#include "Random.hpp"
#include "Runway5.hpp"
#include "Extended_queue.hpp"
#include "Runway.hpp"
#include "RunwayT2.hpp"
#include "RunwayT3.hpp"
#include "RunwayT4.hpp"

using namespace std;

void initialize(int &end_time, int &queue_limit, double &arrival_rate, double &departure_rate, double &fuel);
void run_idle(int time);

int main( ) // Airport simulation program
/* Pre: The user must supply the number of time intervals the simulation is to run,
the expected number of planes arriving, the expected number of planes
departing per time interval, and the maximum allowed size for runway
queues.
Post: The program performs a random simulation of the airport, showing the
status of the runway at each time interval, and prints out a summary of
airport operation at the conclusion.
Uses: Classes Runway, Plane, Random and functions run_idle, initialize. */
{
	int end_time; // time to run simulation
	int queue_limit; // size of Runway queues
	int flight_number = 0;
	double arrival_rate, departure_rate, fuel;
	initialize(end_time, queue_limit, arrival_rate, departure_rate, fuel);

	bool mode1 = false;
	bool mode2 = false;
	bool mode3 = true;
	bool mode4 = false;
	char op = 0;

	cout << "Please choose the mode you want to test:" << endl;
	cout << "1:All of the random number is const"<<endl;
	cout << "2:Input all of the number instead of using random number"<<endl;
	cout << "3:Use pseudo random number"<<endl;
	cout << "4:Use true random number"<<endl;
	cin >> op;
	
	if(op == '1'){
		mode1 = true;
		mode2 = false;
		mode3 = false;
		mode4 = false;
	}
	else if(op == '2'){
		mode1 = false;
		mode2 = true;
		mode3 = false;
		mode4 = false;
	}
	else if(op == '3'){
		mode1 = false;
		mode2 = false;
		mode3 = true;
		mode4 = false;
	}
	else{
		mode1 = false;
		mode2 = false;
		mode3 = false;
		mode4 = false;
	}
	Test variable = Test(mode1,mode2,mode3,mode4);

	//Runway small_airport(queue_limit);
	//Runway4 small_airport(queue_limit);
	int test_number=1;
	cout << "choose the number of the test(1-5)" << endl;
	cin >> test_number;
	int RunwayNum;
	Runway* small_airport = new Runway();
	if(test_number == 1){
		RunwayNum = 1;
		Runway* temp = new Runway(queue_limit);
		small_airport=temp;
	}
	else if(test_number == 2){
		RunwayNum = 2;
		RunwayT2* temp = new RunwayT2(queue_limit);
		small_airport=temp;
	}
	else if(test_number == 3){
		RunwayNum = 2;
		RunwayT3* temp = new RunwayT3(queue_limit);
		small_airport=temp;
	}
	else if(test_number == 4){
		RunwayNum =3;
		RunwayT4* temp = new RunwayT4(queue_limit);
		small_airport=temp;
	}
	else if(test_number == 5){
		RunwayNum = 1;
		Runway5* temp = new Runway5(queue_limit);
		small_airport=temp;
	}
	else{
		RunwayNum = 1;
		Runway* temp = new Runway(queue_limit);
		small_airport=temp;
	}

	int current_time;
	for (current_time = 0; current_time < end_time; current_time++) {
	// loop over time intervals
		int number_arrivals = variable.poisson(arrival_rate);
	// current arrival requests
		for (int i = 0; i < number_arrivals; i++) {
			Plane current_plane;
			if (fuel < 0)
				current_plane = Plane(flight_number++, current_time, arriving, -1);
			else
				current_plane = Plane(flight_number++, current_time, arriving, variable.poisson(fuel));
			if (small_airport->can_land(current_plane) != success)
				current_plane.refuse( );
		}
		int number_departures = variable.poisson(departure_rate);
	// current departure requests
		for (int j = 0; j < number_departures; j++) {
			Plane current_plane(flight_number++, current_time, departing, -1);
			if (small_airport->can_depart(current_plane) != success)
				current_plane.refuse( );
		}
		bool exit = false;
		for (int i = 0; i < RunwayNum; i++) {
			Plane moving_plane;
			switch (small_airport->activity(current_time, moving_plane)) {
				// Let at most one Plane onto the Runway at current_time.
				case land:
					moving_plane.land(current_time);
					break;
				case takeoff_:
					moving_plane.fly(current_time);
					break;
				case idle:
					run_idle(current_time);
					break;
				case crash:
					moving_plane.land(current_time);
					exit = true;
					break;
			}
		}
		if (exit) {
			cout << "A plane crashes, simulation terminates!" << endl;
			break;
		}
	}
	small_airport->shut_down(current_time);
	system("pause");
	return 0;
}

void initialize(int &end_time, int &queue_limit, double &arrival_rate, double &departure_rate, double &fuel)
/* Pre: The user specifies the number of time units in the simulation, the maximal
queue sizes permitted, and the expected arrival and departure rates for
the airport.
Post: The program prints instructions and initializes the parameters end_time,
queue_limit, arrival_rate, and departure_rate to the specified values.
Uses: utility function user_says_yes */
{
/*	cout << "This program simulates an airport with only one runway." << endl
		<< "One plane can land or depart in each unit of time." << endl;*/
	cout << "Up to what number of planes can be waiting to land "
		<< "or take off at any time? " << flush;
	cin >> queue_limit;
	cout << "How many units of time will the simulation run?" << flush;
	cin >> end_time;
	bool acceptable;
	do {
		cout << "Expected number of arrivals per unit time?" << flush;
		cin >> arrival_rate;
		cout << "Expected number of departures per unit time?" << flush;
		cin >> departure_rate;
		cout << "Expected fuel level of arrivals per unit time?(Negative number to ignore the fuel)" << flush;
		cin >> fuel;
		if (arrival_rate < 0.0 || departure_rate < 0.0)
			cerr << "These rates must be nonnegative." << endl;
		else
			acceptable = true;
		if (acceptable && arrival_rate + departure_rate > 1.0)
			cerr << "Safety Warning: This airport will become saturated. " << endl;
	} while (!acceptable);
}

void run_idle(int time)
/* Post: The specified time is printed with a message that the runway is idle. */
{
	cout << time << ": Runway is idle." << endl;
}
