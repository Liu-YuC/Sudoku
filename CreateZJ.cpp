#include "CreateZJ.h"

void CreateZJ::generateN(int n)
{
    char temp[lenSD + 1][lenSD + 1];
    int shift[9] = { 0, 3, 6, 1, 4, 7, 2, 5, 8 };
    for (int i = 0; i < 6 && n; i++)
    {
        if (i)
        {
            std::next_permutation(shift + 3, shift + 6);
            shift[6] = 2, shift[7] = 5, shift[8] = 8;
        }
        for (int j = 0; j < 6 && n; j++)
        {
            if (j) std::next_permutation(shift + 6, shift + 9);
            char row[10] = "123456789";
            for (int k = 0; k < 40320 && n; k++)
            {
                if (k) std::next_permutation(row + 1, row + 9);


                for (int r = 0; r < 9; r++)
                {
                    for (int c = 0; c < 9; c++)
                        temp[r][c] = row[(c + shift[r]) % 9];
                    temp[r][lenSD] = 0;
                }
                
                putSudokuToFile(temp);

                --n;
            }
        }
    }
}
void CreateZJ::random1(char(*sudoku)[lenSD + 1])
{
    int shift[9] = { 0, 3, 6, 1, 4, 7, 2, 5, 8 };

    int maxi = rand() % 6, maxj = rand() % 6, maxk = ((rand() * rand()) % 40320 + 40320) % 40320;
    char row[10] = "123456789";
    for (int i = 0; i < maxi; i++)
    {
        if (i)
        {
            std::next_permutation(shift + 3, shift + 6);
            shift[6] = 2, shift[7] = 5, shift[8] = 8;
        }
        for (int j = 0; j < maxj; j++)
        {
            if (j) std::next_permutation(shift + 6, shift + 9);

            for (int k = 0; k < maxk; k++)
            {
                if (k) std::next_permutation(row + 1, row + 9);

            }
        }
    }
    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            sudoku[r][c] = row[(c + shift[r]) % 9];
        }
    }
}
