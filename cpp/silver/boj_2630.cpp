#include <iostream>
#define endl '\n'

int colorPaper[128][128] = {0};
int arraySize;
int whitePaperCount = 0;
int bluePaperCount = 0;

void input()
{
    std::cin >> arraySize;

    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arraySize; j++)
        {
            std::cin >> colorPaper[i][j];
        }
    }
}

bool checkSquare(int initValue, int size, int xPos, int yPos)
{
    for (int i = xPos; i < xPos + size; i++)
    {
        for (int j = yPos; j < yPos + size; j++)
        {
            if (initValue != colorPaper[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

void depthSearch(int size, int xPos, int yPos)
{
    int initValue = colorPaper[xPos][yPos];
    bool isSquare = checkSquare(initValue, size, xPos, yPos);

    if (isSquare)
    {
        initValue == 1 ? bluePaperCount++ : whitePaperCount++;
    }
    else
    {
        depthSearch(size / 2, xPos, yPos);
        depthSearch(size / 2, xPos + size / 2, yPos);
        depthSearch(size / 2, xPos, yPos + size / 2);
        depthSearch(size / 2, xPos + size / 2, yPos + size / 2);
    }
}

void output()
{
    std::cout << whitePaperCount << endl;
    std::cout << bluePaperCount << endl;
}

void solution()
{
    input();
    depthSearch(arraySize, 0, 0);
    output();
}

int main()
{
    solution();

    return 0;
}
