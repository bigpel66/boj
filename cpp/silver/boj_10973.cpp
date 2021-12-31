#include <iostream>
#include <algorithm>
using namespace std;

int findPreviousArr[10000];

bool desc(int a, int b)
{
    return a>b;
}

int main()
{
    int sectionIndex = -1;
    int number;
    int temp;
    
    cin >> number;
    
    for(int i = 0; i < number; i++)
    {
        cin >> findPreviousArr[i];
    }
    
    for(int i = number - 1; i >= 0; i--)
    {
        if(findPreviousArr[i - 1] > findPreviousArr[i])
        {
            sectionIndex = i- 1;
            break;
        }
    }
    
    if(sectionIndex == -1)
    {
        cout << sectionIndex;
        return 0;
    }
    
    sort(findPreviousArr + sectionIndex + 1, findPreviousArr + number, desc);
    
    for(int i = sectionIndex + 1; i < number; i++)
    {
        if(findPreviousArr[sectionIndex] > findPreviousArr[i])
        {
            temp = findPreviousArr[i];
            findPreviousArr[i] = findPreviousArr[sectionIndex];
            findPreviousArr[sectionIndex] = temp;
            break;
        }
    }
    
    for(int i = 0; i < number; i++)
    {
        cout << findPreviousArr[i] << " ";
    }
    
    return 0;
}
