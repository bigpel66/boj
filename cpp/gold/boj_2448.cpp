#include <iostream>
#define endl "\n"

int inputValue;
char starBoard[3072][6144];

void input() {
    std::cin >> inputValue;
    
    
}

void initialize() {
    for(int i = 0; i < inputValue; i++) {
        for(int j = 0; j < inputValue * 2; j++) {
            if(j == 2 * inputValue - 1) {
                starBoard[i][j] = '\0';
            } else {
                starBoard[i][j] = ' ';
            }
        }
    }
}
void drawStar(int xCoordinate, int yCoordinate, int theHeightOfTower) {
    if(theHeightOfTower == 3) {
        starBoard[xCoordinate][yCoordinate] = '*';
        
        starBoard[xCoordinate + 1][yCoordinate - 1] = '*';
        starBoard[xCoordinate + 1][yCoordinate + 1] = '*';
        
        starBoard[xCoordinate + 2][yCoordinate - 2] = '*';
        starBoard[xCoordinate + 2][yCoordinate - 1] = '*';
        starBoard[xCoordinate + 2][yCoordinate] = '*';
        starBoard[xCoordinate + 2][yCoordinate + 1] = '*';
        starBoard[xCoordinate + 2][yCoordinate + 2] = '*';
        
        return;
    }
    
    drawStar(xCoordinate, yCoordinate, theHeightOfTower / 2);
    drawStar(xCoordinate + (theHeightOfTower / 2), yCoordinate - (theHeightOfTower / 2), theHeightOfTower / 2);
    drawStar(xCoordinate + (theHeightOfTower / 2), yCoordinate + (theHeightOfTower / 2), theHeightOfTower / 2);
}

void output() {
    for(int i = 0; i < inputValue; i++) {
        for(int j = 0; j < inputValue * 2 - 1; j++) {
            std::cout << starBoard[i][j];
        }
        std::cout << endl;
    }
    
}
int main() {
    
    input();
    initialize();
    drawStar(0, inputValue - 1, inputValue);
    output();
    
    return 0;
}
