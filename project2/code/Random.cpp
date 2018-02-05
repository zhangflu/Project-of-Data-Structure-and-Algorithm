#include <iostream>
#include <time.h>
#include <limits.h>
#include <cmath>
#include "Random.hpp"
using namespace std;
int Random :: reseed()
/* Post: The seed is replaced by a pseudorandom successor. */
{
	seed = seed * multiplier + add_on;
	return seed;
}

Random :: Random(bool pseudo)
/* Post: The values of seed, add_on, and multiplier are initialized. The seed is
initialized randomly only if pseudo == false. */
{
	if (pseudo) seed = 1;
	else seed = time(NULL)%INT_MAX;
	multiplier = 2743;
	add_on = 5923;
}

double Random :: random_real()
/* Post: A random real number between 0 and 1 is returned. */
{
	double max = INT_MAX + 1.0;
	double temp = reseed();
	if(temp < 0){
		temp = temp + max;
	}
	return temp/max;
}

int Random :: poisson(double mean)
/* Post: A random integer, reflecting a Poisson distribution with parameter mean,
is returned. */
{
	double limit = exp(-mean);
	double product = random_real();
	int count = 0;
	while (product > limit) {
		count++;
		product *= random_real();
	}
	return count;
}