#include <iostream>
#include <algorithm>
using namespace std;

int findNextArr[10000];

int main()
{
    int num;
    int sectionIndex = -1;
    int temp;
    
    cin >> num;
    
    for(int i = 0; i < num; i++)
    {
        cin >> findNextArr[i];
    }
    
    for(int i = num - 1; i >= 1; i--)
    {
        if(findNextArr[i] > findNextArr[i - 1])
        {
            sectionIndex = i - 1;
            break;
        }
    }
    
    if(sectionIndex == -1)
    {
        cout << -1;
        return 0;
    }
    
    for(int i = num - 1; i >= sectionIndex + 1; i--)
    {
        if(findNextArr[sectionIndex] < findNextArr[i])
        {
            temp = findNextArr[sectionIndex];
            findNextArr[sectionIndex] = findNextArr[i];
            findNextArr[i] = temp;
            break;
        }
    }
    
    sort(findNextArr + sectionIndex + 1, findNextArr + num);
    
    for(int i = 0; i < num; i++)
    {
        cout << findNextArr[i] << " ";
    }
    return 0;
}
