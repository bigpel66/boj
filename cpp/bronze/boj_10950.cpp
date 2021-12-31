#include <iostream>
#define endl "\n"

int main() {
    int numberOfIterator;
    
    std::cin >> numberOfIterator;
    
    for(int i = 0; i < numberOfIterator; i++) {
        int A, B;
        std::cin >> A >> B;
        std::cout << A + B << endl;
    }
}
