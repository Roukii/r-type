#include "stdafx.h"
#include "Random.h"
#include <time.h>

namespace Gomoku
{
	Random::Random()
	{
		srand((unsigned int)time(NULL));
	}

	Random::~Random()
	{

	}

	int Random::GenerateRandomNumber(int min, int max)
	{
		return rand() % max + min;
	}
}