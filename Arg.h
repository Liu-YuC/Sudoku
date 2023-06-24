#pragma once
#include <cstring>
#include <iostream>
#include <sstream>
class Arg
{
public:
    int sudokuCount = 0;
    std::string sudokuFilePath;
    int gameCount = 0;
    int gameDifficulty = 0;
    int emptyCellsMin = 0;
    int emptyCellsMax = 0;
    bool uniqueSolution = false;

    Arg(){}
    bool getArgs(int argc, char** argv);
};

