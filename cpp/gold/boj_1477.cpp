#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> rp;

int main()
{
    int N, M, L;
    int i;
    int left, right, mid;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> L;
    rp.resize(N + 2);
    rp[0] = 0;

    for (i = 1; i <= N; i++)
    {
        cin >> rp[i];
    }

    rp[N + 1] = L;
    sort(rp.begin(), rp.end());

    left = 1;
    right = L;

    while (left <= right)
    {
        mid = (left + right) / 2;
        int total = 0;

				// by 🐷
				// rp 사이즈는 미리 저장 해두고 사용하는 걸 권장 (매 루프 조건 비교 마다 함수 호출하니까)
				// 이렇게 루프를 돌릴 때는 int i 가 아닌 size_t로 돌려야 해
				// 엄격하게 채점 시 안 돌아가는 코드고, 비교 범위가 서로 다르니 ㅇㅇ..

        for (size_t i = 1; i < rp.size(); i++)
        {

						// by 🐷
						// rp간 차이 - 1 해서 조정한게 멋지네
						// 코드 깔끔하네

            int d = rp[i] - rp[i - 1] - 1;
            total += (d / mid);
        }
        if (total > M)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << left;
    return (0);
}
