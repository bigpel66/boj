#include <iostream>
#define lld long long
#define endl '\n'

lld tableRow;
lld tableCol;
lld tempRow;
lld tempCol;

lld diffCount;

lld curveCount;
lld xCoord;
lld yCoord;

int innerCurveCount;
int direction;

void input()
{
    std::cin >> tableRow >> tableCol;
    diffCount = 0;
    curveCount = 0;
    direction = 0;
    xCoord = 0;
    yCoord = 0;
    tempRow = tableRow;
    tempCol = tableCol;
}

lld calcCurveCount(lld &row, lld &col)
{
    if (row > col)
    {
        return col * 2 - 1;
    }
    else
    {
        return row * 2 - 2;
    }
}

void calcDiffCount()
{
    lld smallEdge = tableRow > tableCol ? tableCol : tableRow;

    diffCount = (smallEdge - 1) / 2;

    tempRow -= (diffCount * 2);
    tempCol -= (diffCount * 2);

    innerCurveCount = static_cast<int>(calcCurveCount(tempRow, tempCol));

    --tempRow;
    --tempCol;
}

void calcEndCoord()
{
    lld tempX = 1;
    lld tempY = 1;

    for (int i = 0; i < innerCurveCount + 1; i++)
    {
        switch (direction)
        {
        case 0:
            tempY += tempCol;
            break;
        case 1:
            tempX += tempRow;
            --tempRow;
            break;
        case 2:
            tempY -= tempCol;
            --tempCol;
            break;
        case 3:
            tempX -= tempRow;
            --tempRow;
            break;
        }
        direction = (++direction % 4);
    }

    xCoord += (diffCount + tempX);
    yCoord += (diffCount + tempY);
}

void output()
{
    std::cout << curveCount << endl;
    std::cout << xCoord << ' ' << yCoord;
}

void solution()
{
    input();
    curveCount = calcCurveCount(tableRow, tableCol);
    calcDiffCount();
    calcEndCoord();
    output();
}

int main()
{
    solution();
    return 0;
}
