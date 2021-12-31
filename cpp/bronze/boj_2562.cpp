#include <iostream>
#define endl "\n"

int compareThings[9];
int max = -1;
int maxIndex = -1;

int main() {
    for(int i = 0; i < 9; i++) {
        std::cin >> compareThings[i];
        if(max < compareThings[i]) {
            max = compareThings[i];
            maxIndex = i;
        }
    }
    
    std::cout<< max << endl << maxIndex + 1;
    
    return 0;
}
