#include <iostream>
using namespace std;

bool isPrime[1001];

void makePrime()
{
    isPrime[0] = false;
    isPrime[1] = false;
    
    for(int i = 2; i < 1001; i++)
    {
        isPrime[i] = true;
    }
    
    for(int i = 2; i < 33; i++)
    {
        if(isPrime[i] == true)
        {
            for(int j = 2 * i; j < 1001; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int main() {

    int N;
    int count = 0;
    int number;

    makePrime();
    
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        cin >> number;
        if(isPrime[number])
            count++;
    }
    
    cout << count;
    
    return 0;
}
