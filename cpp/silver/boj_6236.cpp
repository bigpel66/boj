#include <iostream>
#include <vector>

int                                                                 g_number_of_day;
int                                                                 g_number_of_count;
int                                                                 g_total_money;
int                                                                 g_min_withdrawl;
std::vector<int>                                                    g_expenditure;

void                                                                pre_setting(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

void                                                                input_action(void)
{
    int                                                             index;

    index = -1;
    g_total_money = 0;
    g_min_withdrawl = -1;
    std::cin >> g_number_of_day >> g_number_of_count;
    g_expenditure.resize(g_number_of_day);
    while (++index < g_number_of_day)
    {
        std::cin >> g_expenditure[index];
        g_total_money += g_expenditure[index];
        if (g_min_withdrawl < g_expenditure[index])
            g_min_withdrawl = g_expenditure[index];
    }
}

void                                                                binary_search(void)
{
    int                                                             start;
    int                                                             end;
    int                                                             mid;
    int                                                             index;
    int                                                             sum;
    int                                                             count;

    start = g_min_withdrawl;
    end = g_total_money;
    g_min_withdrawl = -1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        index = -1;
        sum = 0;
        count = 1;
        while (++index < g_number_of_day)
        {
            if (sum + g_expenditure[index] > mid)
            {
                ++count;
                sum = 0;
            }
            sum += g_expenditure[index];
        }
        if (count <= g_number_of_count)
        {
            g_min_withdrawl = mid;
            end = mid -1;
        }
        else
            start = mid + 1;
    }
}

void                                                                output_action(void)
{
    std::cout << g_min_withdrawl;
}

void                                                                solution(void)
{
    input_action();
    binary_search();
    output_action();
}

int                                                                 main(void)
{
    pre_setting();
    solution();
    return (0);
}
