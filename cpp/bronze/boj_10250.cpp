#include <iostream>
#define endl "\n"

int inputValue;
int height, width, order;

void input() {
    std:: cin >> height >> width >> order;
}

void solution() {
    
    for(int i = 0; i < inputValue; i++) {
        int floor;
        int roomNumber;
        
        input();
        
        roomNumber = order % height == 0? order / height : order / height + 1;
        floor = order % height == 0 ? height : order % height;
        
        std::cout << roomNumber + floor * 100 << endl;
    }
}

int main() {
    std::cin >> inputValue;
    
    solution();
    
    return 0;
}
