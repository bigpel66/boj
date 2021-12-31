#include <iostream>
#include <vector>

int arrSize;
int maxHeight = -1;
std::vector<std::vector<int>> landVector;
std::vector<std::vector<int>> copyVector;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int areaCount;
int maxCount = -1;

void input()
{
    std::cin >> arrSize;

    for (int i = 0; i < arrSize; i++)
    {
        std::vector<int> temp;

        for (int j = 0; j < arrSize; j++)
        {
            int inputValue;
            std::cin >> inputValue;

            temp.push_back(inputValue);

            if (inputValue > maxHeight)
            {
                maxHeight = inputValue;
            }
        }

        landVector.push_back(temp);
    }
}
void depthSearch(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < arrSize && ny < arrSize && copyVector[nx][ny])
        {
            copyVector[nx][ny] = 0;
            depthSearch(nx, ny);
        }
    }
}

void makeSinkLevel()
{
    for (int level = 1; level < maxHeight; level++)
    {
        copyVector = landVector;
        areaCount = 0;

        for (int i = 0; i < arrSize; i++)
        {
            for (int j = 0; j < arrSize; j++)
            {
                if (copyVector[i][j] <= level)
                {
                    copyVector[i][j] = 0;
                }
                else
                {
                    copyVector[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < arrSize; i++)
        {
            for (int j = 0; j < arrSize; j++)
            {
                if (copyVector[i][j])
                {
                    copyVector[i][j] = 0;
                    depthSearch(i, j);
                    areaCount++;
                }
            }
        }

        if (areaCount > maxCount)
        {
            maxCount = areaCount;
        }
    }
}

void solution()
{
    input();
    makeSinkLevel();

    std::cout << ((maxCount == -1) ? 1 : maxCount);
}

int main()
{
    solution();
    return 0;
}
