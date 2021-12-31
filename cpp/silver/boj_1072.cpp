#include <iostream>

typedef long long lld;

int                                         g_total_games;
int                                         g_win_games;
int                                         g_additional_games;
int                                         g_win_rate;

void                                        pre_setting(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

void                                        input_action(void)
{
    std::cin >> g_total_games >> g_win_games;
    g_win_rate = static_cast<lld>(g_win_games) * 100 / g_total_games;
    g_additional_games = 0;
}

void                                        binary_search(void)
{
    int                                     start;
    int                                     end;
    int                                     mid;
    int                                     val;

    start = 1;
    end = g_total_games;
    while (start <= end)
    {
        mid = (start + end) / 2;
        val = static_cast<lld>((g_win_games + mid)) * 100 / (g_total_games + mid);
        if (g_win_rate < val)
        {
            end = mid - 1;
            g_additional_games = mid;
        }
        else
            start = mid + 1;
    }
}

void                                        output_action(void)
{
    if (g_win_rate >= 99)
        std::cout << -1;
    else
        std::cout << g_additional_games;
}

void                                        solution(void)
{
    input_action();
    binary_search();
    output_action();
}

int                                         main(void)
{
    pre_setting();
    solution();
    return (0);
}
