#include <iostream>
#define MAX 1000001
using namespace std;
bool isPrime[MAX];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    int input;
   
    for(int i = 3; i < MAX; i+=2)
    {
        isPrime[i] = true;
    }
    
    for(int i = 3; i <= 1000; i+=2){
        for(int j = 2 * i; j < MAX; j += i) {
            isPrime[j] = false;
        }
    }
    
    while(1){
        cin >> input;
        
        if(input == 0) break;
        for (int i = 3; i < input; i+=2){
             if(isPrime[i] && isPrime[input - i]){
                 cout << input << " = " << i << " + " << input - i << "\n";
                 break;
             }
        }
    }
    
    return 0;
}
