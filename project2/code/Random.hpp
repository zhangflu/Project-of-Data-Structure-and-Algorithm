#ifndef RANDOM_HPP
#define RANDOM_HPP
class Random {
public:
	Random(bool pseudo = true);
	double random_real();
	int poisson(double mean);
	// Declare random-number generation methods here.
private:
	int reseed(); // Re-randomize the seed.
	int seed, multiplier, add_on; // constants for use in arithmetic operations
};

#endif