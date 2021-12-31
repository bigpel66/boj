#include <iostream>
#include <stack>
#define endl "\n"

std::string inputValue;
std::stack<char> operatorStack;

void input() {
    std::cin >> inputValue;
}

void solution() {
    for(int i = 0; i < inputValue.length(); i++) {
        if(inputValue[i] >= 'A' && inputValue[i] <= 'Z') {
            std::cout << inputValue[i];
            continue;
        }
        
        switch(inputValue[i]) {
            case '+':
            case '-':
                while((!operatorStack.empty()) && (operatorStack.top() != '(')) {
                    std::cout << operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(inputValue[i]);
                break;
            case '*':
            case '/':
                while((!operatorStack.empty()) && (operatorStack.top() == '*' || operatorStack.top() == '/')) {
                    std::cout << operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(inputValue[i]);
                break;
            case '(':
                operatorStack.push(inputValue[i]);
                break;
            case ')':
                while((!operatorStack.empty()) && operatorStack.top() != '(') {
                    std::cout << operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.pop();
                break;
        }
    }
    
    while(!operatorStack.empty()) {
        std::cout << operatorStack.top();
        operatorStack.pop();
    }
}

int main() {
    
    input();
    solution();
    
    return 0;
}
