#include <iostream>
#define endl "\n"

typedef struct stack{
    int mem[10000];
    int topIndex = -1;
} Stack;

Stack stack;

void pushStack(int number) {
    stack.mem[++stack.topIndex] = number;
}

void popStack() {
    if(stack.topIndex <= -1) {std::cout<< -1 << endl; return;}
    
    std::cout << stack.mem[stack.topIndex] << endl;
    stack.topIndex--;
}

void topStack() {
    if(stack.topIndex <= -1) {std::cout<< -1 << endl; return;}
    std::cout << stack.mem[stack.topIndex] << endl;
}

void emptyStack() {
    if(stack.topIndex >= 0) {
        std::cout<< 0 << endl;
    } else {
        std::cout << 1 << endl;
    }
}

void sizeStack(){
    std::cout<< stack.topIndex + 1 << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    //std::cout.tie(NULL);
    
    int number;
    std::string inst;
    
    std::cin>>number;
    
    for(int i = 0; i < number; i++) {
        std::cin>>inst;
        if(inst[0] == 'p'&& inst[1] == 'u') {
            int push_number;
            std::cin>> push_number;
            pushStack(push_number);
        }
        else if(inst[0] == 'p' && inst[1] == 'o'){
            popStack();
        }
        else if(inst[0] == 't'){
            topStack();
        }
        else if(inst[0] == 'e') {
            emptyStack();
        }
        else {
            sizeStack();
        }
    }
    
    return 0;
}
