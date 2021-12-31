#include <iostream>
#include <queue>
#define endl "\n"

int numberOfNodes;
int numberOfEdges;
int theStartNode;
bool isVisited[1000];
bool adjMatrix[1000][1000];

void initializeModule() {
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            adjMatrix[i][j] = false;
        }
        isVisited[i] = false;
    }
}

void inputModule() {
    std::cin>> numberOfNodes >> numberOfEdges >> theStartNode;
    
    for(int i = 0; i < numberOfEdges; i++) {
        int formerNode, latterNode;
        
        std::cin >> formerNode >> latterNode;
        
        adjMatrix[formerNode - 1][latterNode - 1] = true;
        adjMatrix[latterNode - 1][formerNode - 1] = true;
    }
}

void depthSearch(int number) {
    isVisited[number] = true;
    
    std::cout << number + 1 << ' ';
    
    for(int i = 0; i < numberOfNodes; i++) {
        if(adjMatrix[number][i] && !isVisited[i]) {
            depthSearch(i);
        }
    }
}

void breadthSearch(int number) {
    std::queue<int> queueForBFS;
    
    queueForBFS.push(number);
    
    isVisited[number] = false;
    
    while (!queueForBFS.empty()) {
        number = queueForBFS.front();
        
        std::cout << number + 1 << ' ';
        
        queueForBFS.pop();
        
        for(int i = 0; i < numberOfNodes; i++) {
            if(adjMatrix[number][i] && isVisited[i]) {
                queueForBFS.push(i);
                isVisited[i] = false;
            }
        }
    }
}

int main() {
    initializeModule();
    inputModule();
    depthSearch(theStartNode - 1);
    std::cout << endl;
    breadthSearch(theStartNode - 1);
    
    return 0;
}
