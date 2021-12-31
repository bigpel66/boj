#include<iostream>
#include<vector>
#define MAX 2000

std::vector<int> isFriend[MAX];
bool isVisitied[MAX];
int N, M;

bool dfs(int aPerson, int cnt) {
    if(cnt == 4)
        return true;
    
    isVisitied[aPerson] = true;
    for(int i = 0; i < isFriend[aPerson].size(); i++)
    {
        if(isVisitied[isFriend[aPerson].at(i)]) continue;
        if(dfs(isFriend[aPerson].at(i), cnt + 1)) return true;
    }
    isVisitied[aPerson] = false;
    
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::cin >> N;
    std::cin >> M;
    
    for(int i = 0; i < MAX; i++)
    {
        isVisitied[i] = false;
    }
    
    for(int i = 0; i < M; i++)
    {
        int temp1, temp2;
        std::cin >> temp1;
        std::cin >> temp2;
        isFriend[temp1].push_back(temp2);
        isFriend[temp2].push_back(temp1);
    }
    
    for(int i = 0; i < N; i++)
    {
        if(dfs(i, 0))
        {
            std::cout << 1;
            return 0;
        }
    }
    
    std::cout << 0;
    
    return 0;
}
