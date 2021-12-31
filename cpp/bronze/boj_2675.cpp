#include <iostream>
#define endl "\n"

int main() {
    int iteratorNumber;
    
    std::cin >> iteratorNumber;
    
    for(int i = 0; i < iteratorNumber; i++) {
        int iteratorCountForWord;
        std::string iteratedWord;
        
        std::cin >> iteratorCountForWord >> iteratedWord;
        
        for(int j = 0; j < iteratedWord.length(); j++) {
            for(int k = 0; k < iteratorCountForWord; k++) {
                std::cout << iteratedWord[j];
            }
        }
        std::cout << endl;
    }
    
    return 0;
}
