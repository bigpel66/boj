#include <iostream>
using namespace std;

int main(){
    int E, S, M;
    int count = 0;
    cin >> E >> S >> M;
    
    while(1){
        count++;
        if(!((count - E) % 15 || (count - S) % 28 || (count - M) % 19))
            break;
    }
    
    cout << count << "\n";
    
    return 0;
}
