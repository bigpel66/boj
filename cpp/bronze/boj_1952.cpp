#include <iostream>
#define MAX_SIZE 100

int numberOfX;
int numberOfY;
int snailArray[MAX_SIZE][MAX_SIZE] = { 0 };
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int answer = 0;

void input() {
    std::cin >> numberOfX >> numberOfY;
}

bool rangeCheck(int xPos, int yPos) {
    if(xPos >= numberOfX || yPos >= numberOfY || xPos < 0 || yPos < 0 || snailArray[xPos][yPos] == 1) {
        return true;
    } else {
        return false;
    }
}

void solution() {
    int xPos = 0;
    int yPos = 0;
    int direction = 0;
    
    while(1) {
        if(snailArray[xPos][yPos] == 1) {
            break;
        }
        
        snailArray[xPos][yPos] = 1;
        
        int nx = xPos + dx[direction];
        int ny = yPos + dy[direction];
        
        if(rangeCheck(nx, ny)) {
            answer++;
            direction = (direction + 1) % 4;
            nx = xPos + dx[direction];
            ny = yPos + dy[direction];
        }
        
        xPos = nx;
        yPos = ny;
    }
}

int main() {
    input();
    solution();
    
    std::cout << answer - 1;
    
    return 0;
}
