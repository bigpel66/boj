#include <iostream>
#include <queue>
#define endl "\n"
#define MAX 8

int width, height;
int roomMatrix[MAX][MAX];
int virusMatrix[MAX][MAX];
int answer = -1;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
std::queue<std::pair<int, int>> queueCheck;

void init() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++){
            roomMatrix[i][j] = 0;
            virusMatrix[i][j] = 0;
        }
    }
}

void copyMatrix(int (*former)[MAX], int (*latter)[MAX]) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            latter[i][j] = former[i][j];
        }
    }
}

void input() {
    std::cin >> height >> width;
    
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            std::cin >> roomMatrix[i][j];
        }
    }
    
    copyMatrix(roomMatrix, virusMatrix);
}

bool isErrorOnWall(int xCoordinate, int yCoordinate) {
    if(roomMatrix[xCoordinate][yCoordinate] != 0) {
        return true;
    } else {
        return false;
    }
}

bool isErrorOnRange(int xCoordinate, int yCoordinate) {
    if(xCoordinate < 0 || xCoordinate >= height || yCoordinate < 0 || yCoordinate >= width) {
        return true;
    } else {
        return false;
        
    }
}

bool isErrorOnVirus(int xCoordinate, int yCoordinate) {
    if(virusMatrix[xCoordinate][yCoordinate] == 0) {
        return false;
    } else {
        return true;
    }
}

int countCapabilities() {
    int count = 0;
    
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(virusMatrix[i][j] == 0) {
                count += 1;
            }
        }
    }
    return count;
}

void virusCheck() {
    copyMatrix(roomMatrix, virusMatrix);
    
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(virusMatrix[i][j] == 2) {
                queueCheck.push(std::make_pair(i, j));
            }
        }
    }
}

void virusSpread() {
    virusCheck();
    
    while(!queueCheck.empty()) {
        int xCoord = queueCheck.front().first;
        int yCoord = queueCheck.front().second;
        
        queueCheck.pop();
        
        virusMatrix[xCoord][yCoord] = 2;
        
        for(int i = 0; i < 4; i++) {
            int nX = xCoord + dx[i];
            int nY = yCoord + dy[i];
            
            if(isErrorOnVirus(nX, nY) || isErrorOnRange(nX, nY)) {
                continue;
            }
            
            queueCheck.push(std::make_pair(nX, nY));
        }
    }
}

void depthSearchForWall(int xCoordinate, int yCoordinate, int countOfWall) {
    if(countOfWall == 3) {
        virusSpread();
        int count = countCapabilities();
        if(answer < count) {
            answer = count;
        }
        return;
    }
    
    //    for(int i = 0; i < 4; i++) {
    //        int nX = xCoordinate + dx[i];
    //        int nY = yCoordinate + dy[i];
    //
    //        if(isErrorOnWall(nX, nY) || isErrorOnRange(nX, nY)) {
    //            continue;
    //        }
    //
    //        roomMatrix[nX][nY] = 1;
    //        depthSearchForWall(nX, nY, countOfWall + 1);
    //        roomMatrix[nX][nY] = 0;
    //    }
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(roomMatrix[i][j] == 0) {
                roomMatrix[i][j] = 1;
                depthSearchForWall(i, j, countOfWall + 1);
                roomMatrix[i][j] = 0;
            }
        }
    }
}

void solution() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(roomMatrix[i][j] == 0) {
                roomMatrix[i][j] = 1;
                depthSearchForWall(i, j, 1);
                roomMatrix[i][j] = 0;
            }
        }
    }
}

int main() {
    init();
    input();
    solution();
    
    std::cout << answer;
    
    return 0;
}
