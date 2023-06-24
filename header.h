#pragma once
#define lenSD 9
#define K 3
#define inf 0x3f3f3f3f
#define mod 1000000000 + 7
#define OUTFILENAME "out.txt"
#include <string>
bool readSudokuFromFile(const std::string& filename, char(*sudoku)[lenSD + 1]);
bool putSudokuToFile(char(*sudoku)[lenSD + 1]);