#include "Random.h"
#include <time.h>

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
