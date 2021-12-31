#include <iostream>
#include <cstring>

int main() {
    int countForAlphabet[26] = {0};
    int max = -1;
    int index = -1;
    const std::string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
    std::string inputString;
    
    std::cin >> inputString;
    
    for(int i = 0; i < inputString.length(); i++) {
        inputString[i] = tolower(inputString[i]);
        
        countForAlphabet[inputString[i] - 97]++;
    }
    
    for(int i = 0; i < 26; i++) {
        if(max == countForAlphabet[i]) {
            index = 26;
        }
        
        if(max < countForAlphabet[i]) {
            max = countForAlphabet[i];
            index = i;
        }
    }
    
    std::cout << alphabets[index];
    
    return 0;
}
