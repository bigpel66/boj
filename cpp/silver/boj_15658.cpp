#include <iostream>
#include <vector>
#define endl "\n"
using ll = long long;

int N;
ll max = -987654321;
ll min = 987654321;
std::vector<int> operands;
std::vector<int> operators;

void makeInput()
{
    std::cin >> N;
    for(int i = 0; i < N; i++)
    {
        int temp;
        std::cin >> temp;
        operands.push_back(temp);
    }
    for(int i = 0; i <  4; i++)
    {
        int temp;
        std::cin >> temp;
        operators.push_back(temp);
    }
}

void dfs(int add, int sub, int mul, int div, int index, ll sum)
{
    if(index == N - 1)
    {
        if(max < sum){
            max = sum;
        }
        if(min > sum)
        {
            min = sum;
        }
        
        return;
    }
    
    if(add < operators.at(0))
        {dfs(add + 1, sub, mul, div, index + 1, sum + operands.at(index + 1));}
    
    if(sub < operators.at(1))
        {dfs(add, sub + 1, mul, div, index + 1, sum - operands.at(index  + 1));}
    
    if(mul < operators.at(2))
        {dfs(add, sub, mul + 1, div, index + 1, sum * operands.at(index + 1));}
    
    if(div < operators.at(3))
         {dfs(add, sub, mul, div + 1, index + 1, sum / operands.at(index + 1));}
}

void makeOutput()
{
    std::cout << max;
    std::cout << endl;
    std::cout << min;
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    makeInput();
    dfs(0, 0, 0, 0, 0, operands.at(0));
    makeOutput();

    return 0;
}
