#include <iostream>
#include <set>
#define endl "\n"

int number = 10;
std::set<int> setForSolution;

int main() {
    for(int i = 0; i < number; i++) {
        int inputValue;
        
        std::cin>> inputValue;
        
        inputValue =  inputValue % 42;
        
        setForSolution.insert(inputValue);
    }
    
    std::cout << setForSolution.size() << endl;
    
    return 0;
}
