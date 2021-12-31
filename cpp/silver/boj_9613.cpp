#include <iostream>
using namespace std;

int arr[100];

int gcd(int a, int b)
{
    return (a%b == 0 ? b : gcd(b, a%b));
}

int main() {
    int trial;
    
    cin >> trial;
    
    for(int i = 0; i < trial; i++)
    {
        long long sum = 0;
        int testcase;
        
        cin >> testcase;
        
        for(int j = 0; j < testcase; j++)
        {
            cin >> arr[j];
        }
        
        for(int j = 0; j < testcase - 1; j++)
        {
            for(int k = j + 1; k < testcase; k++)
            {
                sum += gcd(arr[j], arr[k]);
            }
        }
        
        cout << sum << "\n";
    }
    
    return 0;
}
