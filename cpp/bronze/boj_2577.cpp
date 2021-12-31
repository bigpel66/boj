#include <iostream>
#include <cstring>
#define endl "\n"

int main() {
    int answer[10];
    int numbers[3];
    int accNumber = 1;
    std::string toStringedNumber;
    
    for(int i = 0; i < 3; i++) {
        std::cin >> numbers[i];
        accNumber *= numbers[i];
    }
    
    for(int i = 0; i < 10; i++) {
        answer[i] = 0;
    }
        
    toStringedNumber = std::to_string(accNumber);
    
    for(int i = 0; i < toStringedNumber.length(); i++) {
        answer[toStringedNumber[i] - 48]++;
    }
    
    for(int i = 0; i < 10; i++) {
        std::cout << answer[i] << endl;
    }
    
    
    return 0;
}
