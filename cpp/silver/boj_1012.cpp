#include <iostream>
#define endl "\n"

int numberOfIteration;
int width, height;
int numberOfVegetable;
int numberOfLarva;
bool isVegetable[50][50];
bool isTraverse[50][50];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void init() {
    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 50; j++) {
            isVegetable[i][j] = false;
            isTraverse[i][j] = true;
        }
    }
}

void input() {
    std::cin >> width >> height >> numberOfVegetable;
    
    for(int i = 0; i < numberOfVegetable; i++) {
        int rowCoord, colCoord;
        
        std::cin >> rowCoord >> colCoord;
        
        isVegetable[rowCoord][colCoord] = true;
        
        if(isVegetable[rowCoord][colCoord]) {
            isTraverse[rowCoord][colCoord] = false;
        } else {
            isTraverse[rowCoord][colCoord] = true;
        }
    }
}

bool checkErrorOnRange(int xCoord, int yCoord) {
    if(xCoord < 0 || xCoord >= width || yCoord < 0 || yCoord >= height) {
        return true;
    } else {
        return false;
    }
}

void depthSearch(int xCoord, int yCoord) {
    if(!isVegetable[xCoord][yCoord]){
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        int nX = xCoord + dx[i];
        int nY = yCoord + dy[i];
        
        if(checkErrorOnRange(nX, nY) || isTraverse[nX][nY]) {
            continue;
        }
        
        isTraverse[nX][nY] = true;
        depthSearch(nX, nY);
    }
    
}

int main() {
    std::cin >> numberOfIteration;
    
    for(int i = 0; i < numberOfIteration; i++) {
        numberOfLarva = 0;
        init();
        input();
        for(int i = 0; i < width; i++) {
            for(int j = 0; j < height; j ++) {
                if(isTraverse[i][j]) {
                    continue;
                }
                numberOfLarva++;
                isTraverse[i][j] = true;
                depthSearch(i, j);
            }
        }
        
        std::cout << numberOfLarva << endl;
    }
    
    return 0;
}
