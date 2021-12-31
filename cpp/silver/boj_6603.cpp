#include <iostream>

int number;
int candiLotto[12];
int combiLotto[12];

void makeInput(int number)
{
    for(int i = 0; i < number; i++)
    {
        std::cin >> candiLotto[i];
    }
}

void makeCombination(int startPoint, int currentDepth)
{
    if(currentDepth == 6)
    {
        for(int i = 0; i < 6; i++)
        {
            std::cout << combiLotto[i] << " ";
        }
        std::cout << "\n";
        
        return;
    }
    
    for(int i = startPoint; i < number; i++)
    {
        combiLotto[currentDepth] = candiLotto[i];
        makeCombination(i + 1, currentDepth + 1);
    }
}

int main()
{
    while(1)
    {
        std::cin >> number;
        
        if(number == 0)
            return 0;
        
        makeInput(number);
        makeCombination(0, 0);
        std::cout << "\n";
    }
    return 0;
}
