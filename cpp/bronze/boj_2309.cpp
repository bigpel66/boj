#include <iostream>
#include <algorithm>
#define LITTLE 9
#define HEIGHT 100
using namespace std;

int dwarf[LITTLE];
int getSumOfHeight(int dwarf[]);
void getSolution(int sum);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i = 0; i < LITTLE; i++){
        cin >> dwarf[i];
    }
    
    getSolution(getSumOfHeight(dwarf));
    sort(dwarf, dwarf + LITTLE);
    
    for(int i = 2; i < LITTLE; i++)
    {
        cout << dwarf[i] << "\n";
    }
    
    return 0;
}

int getSumOfHeight(int dwarf[]){
    int sum = 0;
    
    for(int i = 0; i < LITTLE; i++)
    {
        sum += dwarf[i];
    }
    
    return sum;
}

void getSolution(int sum)
{
    for(int i = 0; i < LITTLE - 1; i++)
    {
        for(int j = i + 1; j < LITTLE; j++)
        {
            if(sum - dwarf[i] - dwarf[j] == HEIGHT)
            {
                dwarf[i] = -1;
                dwarf[j] = -1;
                return;
            }
        }
    }
}
