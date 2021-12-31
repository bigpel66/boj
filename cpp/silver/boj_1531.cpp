#include <iostream>

int paintTile[101][101];
int numberOfIteration;
int overlapLimitation;
int x1Pos;
int y1Pos;
int x2Pos;
int y2Pos;

int answer = 0;

void init() {
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) {
            paintTile[i][j] = 0;
        }
    }
}

void tilePainting() {
    for(int i = x1Pos; i <= x2Pos; i++) {
        for(int j = y1Pos; j <= y2Pos; j++) {
            paintTile[i][j]++;
        }
    }
}

void checkOverlap() {
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) {
            if(paintTile[i][j] > overlapLimitation) {
                answer++;
            }
        }
    }
}

void solution() {
    std::cin >> numberOfIteration >> overlapLimitation;
    
    for(int i = 0; i < numberOfIteration; i++) {
        std::cin >> x1Pos >> y1Pos >> x2Pos >> y2Pos;
        
        tilePainting();
    }
    
    checkOverlap();
}

int main() {
    init();
    solution();
    
    std::cout << answer;
    
    return 0;
}
