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

				// by π·
				// rp μ¬μ΄μ¦λ λ―Έλ¦¬ μ μ₯ ν΄λκ³  μ¬μ©νλ κ±Έ κΆμ₯ (λ§€ λ£¨ν μ‘°κ±΄ λΉκ΅ λ§λ€ ν¨μ νΈμΆνλκΉ)
				// μ΄λ κ² λ£¨νλ₯Ό λλ¦΄ λλ int i κ° μλ size_tλ‘ λλ €μΌ ν΄
				// μκ²©νκ² μ±μ  μ μ λμκ°λ μ½λκ³ , λΉκ΅ λ²μκ° μλ‘ λ€λ₯΄λ γγ..

        for (size_t i = 1; i < rp.size(); i++)
        {

						// by π·
						// rpκ° μ°¨μ΄ - 1 ν΄μ μ‘°μ νκ² λ©μ§λ€
						// μ½λ κΉλνλ€

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
