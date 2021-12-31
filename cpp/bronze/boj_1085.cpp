#include <iostream>

int main() {
    int x, y, width, height;
    int differenceX, differenceY;
    
    std::cin >> x >> y >> width >> height;
    
    differenceX = width - x > x ? x : width - x;
    differenceY = height - y > y ? y : height - y;
    
    std::cout << (differenceY > differenceX ? differenceX : differenceY);
    
    return 0;
}
