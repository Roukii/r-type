//
// Created by Alexandre on 1/11/2018.
//

#ifndef R_TYPE_RANDOM_HPP
#define R_TYPE_RANDOM_HPP

#include <random>

class Random
{
public:
	Random();
	~Random();

	int GenerateRandomNumber(int min, int max);

private:
	std::random_device _random;
};

#endif // R_TYPE_RANDOM_HPP