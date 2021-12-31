#include <iostream>

int main() {
    int inputValue;
    
    std::cin >> inputValue;
    
    if((inputValue % 4 == 0 && inputValue % 100 != 0) || inputValue % 400 == 0) {
        std::cout << 1;
    } else {
        std::cout << 0;
    }
    return 0;
}
