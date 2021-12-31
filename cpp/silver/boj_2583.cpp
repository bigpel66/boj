#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX 101
int area[MAX][MAX] = { 0 };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int numOfArea = 0;
vector <int> sum;

int M, N;

void DFS(int cy, int cx) {
   area[cy][cx] = 1;

   for (int i = 0; i < 4; i++) {
      int nx = cx + dx[i];
      int ny = cy + dy[i];

      if ((0 <= nx) && (nx < N) && (0 <= ny) && (ny < M) && !area[ny][nx]) {
         numOfArea++;
         DFS(ny, nx);
      }
   }
}

int main() {
   int K;
   cin >> M >> N >> K;

   for (int i = 0; i < K; i++) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;

      for (int y = y1; y < y2; y++) {
         for (int x = x1; x < x2; x++) {
            area[y][x] = 1;
         }
      }
   }

   for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
         if (!area[i][j]) {
            numOfArea++;
            DFS(i, j);

            sum.push_back(numOfArea);
            numOfArea = 0;
         }
      }
   }

   sort(sum.begin(), sum.end());

   cout << sum.size() << endl;

   for (int i = 0; i < sum.size(); i++) {
      cout << sum[i] << " ";
   }
   cout << endl;

}
