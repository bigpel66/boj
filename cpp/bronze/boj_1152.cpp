#include <iostream>

int main() {
    int count = 0;
    std::string inputString;
    
    getline(std::cin, inputString);
    
    for(int i = 0; i < inputString.length(); i++) {
        if(inputString[i] == ' ') {
            count++;
        }
    }
    
    if(inputString[0] == ' ') {
        count--;
    }
    
    if(inputString[inputString.length() -1] == ' ') {
        count--;
    }
    
    std::cout << count + 1;
    return 0;
}
