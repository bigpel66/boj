#include <iostream>
#define MAX 500
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N,M;
int ANSWER = 0;
bool check_visit[MAX][MAX];
int tetro[MAX][MAX];

void Input()
{
    cin >> N >> M;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> tetro[i][j];
            check_visit[i][j] = false;
        }
    }
}

void DFS(int x, int y, int sum, int cnt)
{
    if(cnt == 3)
    {
        if(sum > ANSWER) ANSWER = sum;
        return;
    }
    else{
        for(int i = 0; i < 4; i++)
        {
            int nX = x + dx[i];
            int nY = y + dy[i];
            if(nX < 0 || nX >= N || nY < 0 || nY >= M || check_visit[nX][nY] == true) continue;
            check_visit[nX][nY] = true;
            DFS(nX, nY, sum + tetro[nX][nY], cnt + 1);
            check_visit[nX][nY] = false;
        }
    }
}

//ㅗ
void middleFin1(int x, int y){
    int temp_Sum = tetro[x][y] + tetro[x][y + 1] + tetro[x][y - 1] + tetro[x - 1][y];
    if(temp_Sum > ANSWER) ANSWER = temp_Sum;
}

//ㅜ
void middleFin2(int x, int y){
    int temp_Sum = tetro[x][y] + tetro[x][y + 1] + tetro[x][y - 1] + tetro[x + 1][y];
    if(temp_Sum > ANSWER) ANSWER = temp_Sum;
}

//ㅓ
void middleFin3(int x, int y){
    int temp_Sum = tetro[x][y] + tetro[x - 1][y] + tetro[x + 1][y] + tetro[x][y + 1];
    if(temp_Sum > ANSWER) ANSWER = temp_Sum;
}

//ㅏ
void middleFin4(int x, int y){
    int temp_Sum = tetro[x][y] + tetro[x - 1][y] + tetro[x + 1][y] + tetro[x][y - 1];
    if(temp_Sum > ANSWER) ANSWER = temp_Sum;
}

void Solve()
{
    Input();
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            check_visit[i][j] = true;
            DFS(i, j, tetro[i][j], 0);
            if(j + 1 < M && j - 1 >= 0 && i - 1 >= 0) middleFin1(i, j);
            if(j + 1 < M && j - 1 >= 0 && i + 1 < N) middleFin2(i, j);
            if(i - 1 >= 0 && i + 1 < N && j + 1 < M) middleFin3(i, j);
            if(i - 1 >= 0 && i + 1 < N && j - 1 >= 0) middleFin4(i, j);
            check_visit[i][j] = false;
        }
    }
    
}

int main(){
    Solve();
    cout << ANSWER << "\n";
    
    return 0;
}
