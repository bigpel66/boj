#include <iostream>
#include <cmath>

int uniqueNumber[5];
int number;

int main() {
    for(int i = 0; i < 5; i++) {
        std::cin >> uniqueNumber[i];
        
        number += (int)pow(uniqueNumber[i], 2);
    }
    
    std::cout << number % 10;
    
    return 0;
}
