#include <iostream>
#define endl '\n'

int arraySize;
int negativeCount = 0;
int zeroCount = 0;
int positiveCount = 0;
int paperData[2187][2187];

void input()
{
    std::cin >> arraySize;

    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arraySize; j++)
        {
            std::cin >> paperData[i][j];
        }
    }
}

bool checkSquare(int size, int xPos, int yPos)
{
    for (int i = xPos; i < xPos + size; i++)
    {
        for (int j = yPos; j < yPos + size; j++)
        {
            if (paperData[xPos][yPos] != paperData[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

void depthSearch(int size, int xPos, int yPos)
{
    bool isSquare = checkSquare(size, xPos, yPos);

    if (isSquare)
    {
        switch (paperData[xPos][yPos] + 1)
        {
        case 0:
            negativeCount++;
            break;
        case 1:
            zeroCount++;
            break;
        case 2:
            positiveCount++;
            break;
        }
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                depthSearch(size / 3, (size / 3) * i + xPos, (size / 3) * j + yPos);
            }
        }
    }
}

void output()
{
    std::cout << negativeCount << endl;
    std::cout << zeroCount << endl;
    std::cout << positiveCount << endl;
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
