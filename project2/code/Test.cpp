#include "Test.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;
Test :: Test(bool isconst , bool set, bool pseudo, bool pause): Random(pseudo){
	user_set = set;
	if (set)
		run_pause = false;
	else
		run_pause = pause;
	cons = isconst;
	count = 0;
}
int Test :: poisson(double mean) {
	if (cons) {
		if (run_pause)
			system("pause");
		return int(mean);
	}
	int num = 0;
	if (user_set) {
		if ((count & 1) == 0) {
			cout << "Please input the number of arrival planes in this time:";
		}
		else {
			cout << "Please input the number of departure planes in this time:";
		}
		cin >> num;
	}
	else {
		num = Random::poisson(mean);
		if ((count & 1) == 1) {
			cout << "In this time, the number of departure planes is:" << num << endl;
		}
		else {
			cout << "In this time, the number of arrival planes is:" << num << endl;
		}
		if (run_pause)
			system("pause");
	}
	count++;
	return num;
}

