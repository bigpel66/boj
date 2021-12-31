#include <iostream>

int countOfAlphabet[26];

int main() {
    std::string inputString;
    
    std::cin >> inputString;
    
    for(int i = 0; i < 26; i++) {
        countOfAlphabet[i] = -1;
    }
    
    for(int i = 0; i < inputString.length(); i++) {
        
        if(countOfAlphabet[inputString[i] - 97] == -1) {
            countOfAlphabet[inputString[i] - 97] = i;
        }
        
    }
    
    for(int i = 0; i < 26; i++) {
        std::cout << countOfAlphabet[i] << ' ';
    }
    
    return 0;
}
