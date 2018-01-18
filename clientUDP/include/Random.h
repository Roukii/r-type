#pragma once

#include <random>

namespace Gomoku
{
	class Random
	{
	public:
		Random();
		~Random();

		int GenerateRandomNumber(int min, int max);

	private:
		std::random_device _random;
	};
}