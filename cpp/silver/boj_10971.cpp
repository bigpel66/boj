#include <iostream>

int number;
int sum;
int cnt;
int min = 987654321;
int tsp[10][10];
bool isChecked[10];

void depthSearch(int startPoint, int arriveNodeFromPrevPoint, int sum, int cnt)
{
    if(cnt == number && startPoint == arriveNodeFromPrevPoint)
    {
        if(min > sum) min = sum;
        return;
    }
    
    for(int i = 0; i < number; i++)
    {
        if(tsp[arriveNodeFromPrevPoint][i] == 0) continue;
        
        if(tsp[arriveNodeFromPrevPoint][i] > 0 && !isChecked[arriveNodeFromPrevPoint])
        {
            sum += tsp[arriveNodeFromPrevPoint][i];
            isChecked[arriveNodeFromPrevPoint] = true;
            if(min >= sum) depthSearch(startPoint, i, sum, cnt + 1);
            sum -= tsp[arriveNodeFromPrevPoint][i];
            isChecked[arriveNodeFromPrevPoint] = false;
        }
    }
}

void makeInput()
{
    std::cin >> number;
    
    for(int i = 0; i < number; i++)
    {
        for(int j = 0; j < number; j++)
        {
            std::cin >> tsp[i][j];
        }
        isChecked[i] = false;
    }
}

void makeOutput()
{
    std::cout << min;
}

void makeResult()
{
    for(int i = 0; i < number; i++)
    {
        cnt = 0;
        sum = 0;
        
        depthSearch(i, i, sum, cnt);
    }
}

int main()
{
    makeInput();
    makeResult();
    makeOutput();
    return 0;
}
