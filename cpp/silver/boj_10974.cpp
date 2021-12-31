#include <iostream>
#include <algorithm>
#define endl "\n"

int main()
{
    int permutation[8];
    int number;
    
    std::cin >> number;
    
    for(int i = 0; i < number; i++)
    {
        permutation[i] = i + 1;
    }
    
    while(1)
    {
        int sectionIndex = -1;
        
        for(int i = 0; i < number; i++)
        {
            std::cout << permutation[i] << " ";
        }
        
        std::cout << endl;
        
        for(int i = number - 1; i >= 1; i--)
        {
            if(permutation[i] > permutation[i - 1])
            {
                sectionIndex = i - 1;
                break;
            }
        }
        
        if(sectionIndex == -1)
            break;
        
        for(int i = number - 1; i >= sectionIndex + 1; i--)
        {
            if(permutation[sectionIndex] < permutation[i])
            {
                int temp = permutation[i];
                permutation[i] = permutation[sectionIndex];
                permutation[sectionIndex] = temp;
                break;
            }
        }
        
        std::sort(permutation + sectionIndex + 1, permutation +  number);
    }
    
    return 0;
}
