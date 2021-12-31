#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int number;
    int max = -9999;
    std::vector<int> ans;
    
    std::cin >> number;
     
    for(int i = 0; i < number; i++)
    {
        int temp;
        std::cin >> temp;
        ans.push_back(temp);
    }
    
    std::sort(ans.begin(), ans.end());
    
    do {
        int sum = 0;
        
        
        for(int i = 0; i < number - 1; i++)
        {
            sum += abs(ans[i] - ans[i + 1]);
        }
        
        if(sum > max) max = sum;
        
    } while(next_permutation(ans.begin(), ans.end()));
            
    std::cout << max;
    
    return 0;
}
