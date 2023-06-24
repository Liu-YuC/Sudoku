#include <iostream>
#include <fstream>
#include <cstdlib> // 鍖呭惈atoi鍑芥暟锛岀敤浜庡皢瀛楃涓茶浆鎹负鏁存暟
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime> 
#include <vector>
#include "Arg.h"
#include "DLX.h"
#include "CreateZJ.h"
#include "CreateSD.h"

using namespace std;
char g[lenSD + 1][lenSD + 1];

int main(int argc, char* argv[]) {

    srand(static_cast<unsigned int>(time(NULL)));
    std::ofstream file(OUTFILENAME, ios::trunc);

    Arg arg;
    if (!arg.getArgs(argc, argv))
        return 1;
    if (arg.sudokuFilePath != "")
    {

        if (readSudokuFromFile(arg.sudokuFilePath, g))
        {
            if (DLX::solve(g))
            {
                
                DLX::getAns(g);
                putSudokuToFile(g);
            }
        }
        else
        {
            std::cout << "无法打开：" << arg.sudokuFilePath << std::endl;

        }
    }
    else if (arg.sudokuCount)
    {
        CreateZJ::generateN(arg.sudokuCount);
    }
    else if (arg.gameCount)
    {
        if (arg.gameDifficulty)
        {
            for (int i = 0; i < arg.gameCount; i++)
            {
                CreateZJ::random1(g);
                CreateSD::createDifficult(arg.gameDifficulty, g);
                putSudokuToFile(g);
            }
        }
        else if (arg.uniqueSolution)
        {
            for (int i = 0; i < arg.gameCount; i++)
            {
                CreateZJ::random1(g);
                CreateSD::createUnique(g);
                putSudokuToFile(g);
            }
        }
        else if (arg.emptyCellsMin)
        {
            for (int i = 0; i < arg.gameCount; i++)
            {
                CreateZJ::random1(g);
                CreateSD::createRange(arg.emptyCellsMin, arg.emptyCellsMax, g);
                putSudokuToFile(g);
            }
        }
        else
        {
            for (int i = 0; i < arg.gameCount; i++)
            {
                CreateZJ::random1(g);
                CreateSD::createRange(20,55, g);
                putSudokuToFile(g);
            }

        }
    }
}

