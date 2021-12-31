#include <iostream>
#define endl "\n"

int main() {
    int A, B;
    
    while(1){
        std::cin >> A >> B;
        if(A == 0 && B == 0) break;
        std::cout << A + B << endl;
    }
    
    return 0;
}
