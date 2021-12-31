#include <iostream>
#define endl "\n"

int iteratorNumber;
int accNumber;
int answer = 0;


int main() {
    std::cin >> iteratorNumber;
    std::string toCountString;
    
    for(int i = 0; i < iteratorNumber; i++) {
        std::cin >> toCountString;
        
        accNumber = 1;
        for(int j = 0; j < toCountString.length(); j++) {
            if(toCountString[j] == 'O') {
                answer += accNumber;
                accNumber++;
            } else {
                accNumber = 1;
            }
        }
        
        std::cout << answer << endl;
        answer = 0;
    }
    
    
    return 0;
}
