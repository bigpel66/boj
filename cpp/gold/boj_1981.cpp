#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> MAP;
vector<bool> visit;
vector<int> dx;
vector<int> dy;
int N;

bool bfs(int min, int max)
{
    if (MAP[0] < min || MAP[0] > max)
        return false;
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    visit[0] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visit[nx * N + ny]
                && MAP[nx * N + ny] <= max && MAP[nx * N + ny] >= min)
            {
                q.push(make_pair(nx, ny));
                visit[nx * N + ny] = true;
            }
        }
    }
    return visit[(N - 1) * N + (N - 1)];
}

int main()
{
    int i, j, v_max, v_min;
    int left, right, res;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    v_max = 0;
    v_min = 200;
    
    MAP = vector<int>(N * N, 0);
    visit = vector<bool>(N * N, false);
    dx = vector<int>(4);
    dy = vector<int>(4);
    
    dx = {0, 0, 1, -1};
    dy = {1, -1, 0, 0};

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            cin >> MAP[i * N + j];
            v_min = min(v_min, MAP[i * N + j]);
            v_max = max(v_max, MAP[i * N + j]);
        }
    }

    left = v_min;
    right = v_min;
    res = v_max;
    
    while (left <= v_max && right <= v_max) 
    {
        if (res > right - left)
        {
            for (int i = 0; i < N * N; i++)
                visit[i] = false;
            if (!bfs(left, right))
            {
                ++right;
                continue;
            }
            res = right - left;
        }
        ++left;
    }
    
    cout << res;
    return (0);
}
