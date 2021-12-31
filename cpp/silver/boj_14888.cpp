#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using lld = long long;

int number;
lld sum;
lld min = 987654321;
lld max = -987654321;
std::vector<int> problemOperand;
std::vector<int> problemOperator;

void bruteForce()
{
    std::sort(problemOperator.begin(), problemOperator.end());
    
    do{
        sum = problemOperand.at(0);
        
        for(int i = 0; i < number - 1; i++)
        {
            switch(problemOperator.at(i))
            {
                case 0:
                    sum += problemOperand.at(i + 1);
                    break;
                case 1:
                    sum -= problemOperand.at(i + 1);
                    break;
                case 2:
                    sum *= problemOperand.at(i + 1);
                    break;
                case 3:
                    sum /= problemOperand.at(i + 1);
                    break;
            }
        }
        
        if(max < sum)
        {
            max = sum;
        }
        if(min > sum)
        {
            min = sum;
        }
    } while(std::next_permutation(problemOperator.begin(), problemOperator.end()));
}

void makeInput()
{
    std::cin >> number;
    
    for(int i = 0; i < number; i++)
    {
        int temp;
        std::cin >> temp;
        problemOperand.push_back(temp);
    }
    
    for(int i = 0; i < 4; i++)
    {
        int temp;
        std::cin >> temp;
        
        for(int j = 0; j < temp; j++)
        {
            problemOperator.push_back(i);
        }
    }
}

void makeOutput()
{
    std::cout << max << endl;
    std::cout << min;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    makeInput();
    bruteForce();
    makeOutput();
    
    return 0;
}
