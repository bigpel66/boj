#include <iostream>
#include <algorithm>

int T[16] = {0,};
int P[16] = {0,};
int DP[16] = {0,};
int number;
int max = -987654321;

int solutionDP1(int day)
{
    if(day == number + 1) return 0;

    if(day > number + 1) return -987654321;

    return DP[day] = std::max(solutionDP1(day + 1), solutionDP1(day + T[day]) + P[day]);
}

int solutionDP2()
{
    for(int i = number; i >= 1; i--)
    {
        int finishDay = i + T[i];
        if(finishDay > number + 1)
            DP[i] = DP[i + 1];
        else DP[i] = std::max(DP[i + 1], DP[finishDay] + P[i]);
    }

    return DP[1];
}

void solutionDFS(int startPoint, int sum)
{
    if(startPoint == number + 1)
    {
        max = std::max(max, sum);
        return;
    }
    
    solutionDFS(startPoint + 1, sum);
    if(startPoint + T[startPoint] <= number + 1)
        solutionDFS(startPoint + T[startPoint], sum + P[startPoint]);
}

void makeInput()
{
    std::cin >> number;
    
    for(int i = 1; i <= number; i++)
    {
        std::cin >> T[i] >> P[i];
    }
}

void initializeDPArray()
{
    for(int i = 0; i <16; i++)
    {
        DP[i] = 0;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    makeInput();
    
//    std::cout << solutionDP1(1);
    initializeDPArray();
//
//    std::cout << solutionDP2();
    initializeDPArray();

    solutionDFS(1, 0);
    initializeDPArray();
    std::cout << max;
    
    return 0;
}
