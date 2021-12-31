#include <iostream>
#define endl "\n"

std::string formerNumber;
std::string latterNumber;
bool isFormer;

int main() {
    std::cin >> formerNumber >> latterNumber;
    
    for(int i = 0; i < 3; i++) {
        if(formerNumber[i] > latterNumber[i]) {
            isFormer = true;
        } else if(formerNumber[i] < latterNumber[i]){
            isFormer = false;
        } else {
            continue;
        }
    }
    
    if(isFormer) {
        for(int i = 2; i >= 0; i--) {
            std::cout << formerNumber[i];
        }
    } else {
        for(int i = 2; i >= 0; i--) {
            std::cout << latterNumber[i];
        }
    }
    
    
    return 0;
    
}
