#include <iostream>

int main() {
    int formerInput;
    int latterInput;
    
    std::cin >> formerInput >> latterInput;
    
    if(formerInput < latterInput) {
        std::cout << '<';
    } else if(formerInput == latterInput) {
        std::cout << "==";
    } else {
        std::cout << '>';
    }
    
    return 0;
}
