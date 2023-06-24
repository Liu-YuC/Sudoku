#pragma once
#include "header.h"
#include "DLX.h"
#include <algorithm>
#include <cstring>
class CreateSD
{
public:
	static void createRange(int minE, int maxE, char(*suduZJ)[lenSD + 1]);
	static void createDifficult(int gameDifficulty, char(*suduZJ)[lenSD + 1]);
	static void createUnique(char(*suduZJ)[lenSD + 1]);
private:
	static void randomW1(char(*suduZJ)[lenSD + 1]);
};

