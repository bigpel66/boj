#include <iostream>
#define endl "\n"

int snailArray[1000][1000] = { 0 };
int snailSize;
int numberToPosValue;

int xPosStart = 0;
int yPosStart = 0;
int xPosLimit;
int yPosLimit;

void input() {
    std::cin >> snailSize >> numberToPosValue;
}

void makeSnail() {
    xPosLimit = snailSize - 1;
    yPosLimit = snailSize - 1;
    int startNumber = snailSize * snailSize;
    
    for(int x = 0, y = 0, k = startNumber; k >= 1; k--) {
        if(y == yPosStart && x < xPosLimit) {
            snailArray[x++][y] = k;
        } else if(x == xPosLimit && y < yPosLimit) {
            snailArray[x][y++] = k;
        } else if(y == yPosLimit && x > xPosStart) {
            snailArray[x--][y] = k;
        } else if(x == xPosStart && y > yPosStart) {
            snailArray[x][y--] = k;
            if(y == yPosStart + 1) {
                xPosStart++;
                yPosStart++;
                xPosLimit--;
                yPosLimit--;
            }
            
        } else if(xPosLimit == xPosStart) {
            snailArray[x][y] = k;
        }
    }
}

void findPosition() {
    for(int i = 0; i < snailSize; i++) {
        for(int j = 0; j < snailSize; j++) {
            if(snailArray[i][j] == numberToPosValue) {
                std:: cout << i + 1 << ' ' << j + 1;
                return;
            }
        }
    }
}

void printArray() {
    for(int i = 0; i < snailSize; i++) {
        for(int j = 0; j < snailSize; j++) {
            std::cout << snailArray[i][j] << ' ';
        }
        std::cout << endl;
    }
}

int main() {
    input();
    makeSnail();
    printArray();
    findPosition();
    
    return 0;
}
