#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define endl "\n"

int inputValue;
int apartmentArray[25][25];
bool isVisited[25][25];

int countOfGathered = 0;
int countOfGathredInside;
std::vector<int> countAnswer;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void input() {
    std::string tempString;
    std::cin >> inputValue;
    
    std::cin.ignore();
    
    for(int i = 0; i < inputValue; i++) {
        getline(std::cin, tempString);
    
        for(int j = 0; j < inputValue; j++) {
            apartmentArray[i][j] = (int)(tempString[j] - 48);
            if(!apartmentArray[i][j]) {
                isVisited[i][j] = true;
            } else {
                isVisited[i][j] = false;
            }
        }
    }
}

void depthSearch(int x, int y) {
    if(apartmentArray[x][y]) {
        countOfGathredInside++;
    } else {
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        int nX = x + dx[i];
        int nY = y + dy[i];
        
        if(nX >= inputValue || nY >= inputValue || nX < 0 || nY < 0 || isVisited[nX][nY]) {
            continue;
        }
        
        isVisited[nX][nY] = true;
        depthSearch(nX, nY);
    }
}

void solution() {
    for(int i = 0; i < inputValue; i++) {
        for(int j = 0; j < inputValue; j++) {
            if(isVisited[i][j]) {
                continue;
            }
            countOfGathredInside = 0;
            
            isVisited[i][j] = true;
            countOfGathered++;
            depthSearch(i, j);
            
            countAnswer.push_back(countOfGathredInside);
        }
    }
    
    std::sort(countAnswer.begin(), countAnswer.end());
    
    std::cout << countOfGathered << endl;
    
    for(int i = 0; i < countOfGathered; i++) {
        std::cout << countAnswer[i] << endl;
    }
}

int main() {
    input();
    solution();
}
