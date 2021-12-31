#include <iostream>
#include <cmath>
#define endl "\n"

int main() {
    while(1) {
        int side1, side2, side3;
        
        std::cin >> side1 >> side2 >> side3;
        
        if(!(side1 || side2 || side3)) {
            return 0;
        }

        side1 = (int)pow(side1, 2);
        side2 = (int)pow(side2, 2);
        side3 = (int)pow(side3, 2);

        if(side1 + side2 == side3 || side1 + side3 == side2 || side2 + side3 == side1) {
            std::cout << "right" << endl;
        } else {
            std::cout << "wrong" << endl;
        }
    }
    
    return 0;
}
