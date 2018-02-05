#ifndef TEST_HPP
#define TEST_HPP
#include "Random.hpp"
using namespace std;
class Test : public Random {
private:
	bool user_set;
	bool run_pause;
	bool cons;
	int count;
public:
	Test(bool isconst = false , bool set = false , bool pseudo = false , bool pause = false);
	int poisson(double mean);
};
#endif // TEST_RAMDOM_HPP

