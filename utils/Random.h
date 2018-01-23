//
// Created by Alexandre on 1/11/2018.
//

#ifndef R_TYPE_RANDOM_HPP
#define R_TYPE_RANDOM_HPP

#include <random>

template<typename T>
class Random
{
public:
	Random();
	~Random() = default;

	T Generate(T min, T max);

private:
	std::random_device _generator;
};

template<class T>
Random<T>::Random()
{
}

template<class T>
T Random<T>::Generate(T min, T max)
{
	std::uniform_int_distribution<T> distribution(min, max);
	return distribution(_generator);
}

#endif // R_TYPE_RANDOM_HPP