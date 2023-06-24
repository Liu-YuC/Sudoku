#include "CreateSD.h"
void CreateSD::createRange(int minE, int maxE, char(*suduZJ)[lenSD + 1])
	{

		int Enum = rand() % (maxE - minE + 1) + minE;

		for (int i = 0; i < Enum; i++)
		{
			randomW1(suduZJ);
		}

	}
void CreateSD::createDifficult(int gameDifficulty, char(*suduZJ)[lenSD + 1])
	{
		if (gameDifficulty == 1)
		{
			createRange(20, 31, suduZJ);
		}
		else if (gameDifficulty == 2)
		{
			createRange(32, 43, suduZJ);
		}
		else if (gameDifficulty == 3)
		{
			createRange(44, 55, suduZJ);
		}
	}
void CreateSD::createUnique(char(*suduZJ)[lenSD + 1])
	{
		int Enum = rand() % (55 - 20 + 1) + 20;
		char newSuduZJ[lenSD + 1][lenSD + 1];
		for (int i = 0; i < Enum; i++)
		{
			for (int a = 0; a < lenSD; a++)
			{
				for (int b = 0; b < lenSD; b++)
				{
					newSuduZJ[a][b] = suduZJ[a][b];
				}
			}
			randomW1(newSuduZJ);
			if (!DLX::checkOneAns(newSuduZJ))
			{
				return;
			}
			for (int a = 0; a < lenSD; a++)
			{
				for (int b = 0; b < lenSD; b++)
				{
					suduZJ[a][b] = newSuduZJ[a][b];
				}
			}

		}
	}
void CreateSD::randomW1(char(*suduZJ)[lenSD + 1])
	{
		
		while (true)
		{
			int x, y;
			x = rand() % 9;
			y = rand() % 9;
			if (suduZJ[x][y] != '$')
			{
				suduZJ[x][y] = '$';
				return;
			}
		}
	}
