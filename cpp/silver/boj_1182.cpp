#include <iostream>
#include <vector>

int number;
int sum;
int resultValue;
int ans = 0;
std::vector<int> countings;

void dfs(int level, int startPoint, int cnt, int sum)
{
    if(cnt == level)
    {
        if(sum == resultValue)
            ans++;
        return;
    }
    
    for(int i = startPoint; i < number; i++)
    {
        sum += countings.at(i);
        dfs(level, i + 1, cnt + 1, sum);
        sum -= countings.at(i);
    }
}

int main()
{
    std::cin >> number >> resultValue;
    
    for(int i = 0; i < number; i++)
    {
        int temp;
        std::cin >> temp;
        countings.push_back(temp);
    }
    
    for(int i = 0; i < number; i++)
    {
        sum = 0;
        dfs(i + 1, 0, 0, sum);
    }
    
    std::cout << ans;
    
    return 0;
}
