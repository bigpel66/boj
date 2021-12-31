#include <iostream>
#define endl "\n"
#define MAX 100

int inputValue;
int matrix[MAX][MAX];
bool isVisited[MAX];

void initMatrix() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            matrix[i][j] = 0;
        }
    }
}

void initTraverse() {
    for(int i = 0; i < MAX; i++) {
        isVisited[i] = false;
    }
}

void input() {
    for(int i = 0; i < inputValue; i++) {
        for(int j = 0; j < inputValue; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

void depthSearch(int topPosition) {
    for(int i = 0; i < inputValue; i++) {
        if(matrix[topPosition][i] & !isVisited[i]) {
            isVisited[i] = true;
            depthSearch(i);
        }
    }
}

void solution() {
    for(int i = 0; i < inputValue; i++) {
        initTraverse();
        depthSearch(i);
        for(int j = 0; j < inputValue; j++) {
            if(isVisited[j]) {
                matrix[i][j] = 1;
            }
        }
    }
}

void output() {
    for(int i = 0; i < inputValue; i++) {
        for(int j = 0; j < inputValue; j++) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << endl;
    }
}

int main() {
    std::cin >> inputValue;
    
    initMatrix();
    input();
    solution();
    output();
    
    return 0;
}
