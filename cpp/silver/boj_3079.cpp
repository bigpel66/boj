#include <iostream>
#include <vector>

typedef long long lld;

int                                                         g_number_of_pc;
int                                                         g_number_of_friend;
lld                                                         g_time_acc;
std::vector<int>                                            g_time_consume;

void                                                        pre_setting(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

void                                                        input_action(void)
{
    int                                                     index;

    g_time_acc = -1;
    index = -1;
    std::cin >> g_number_of_pc >> g_number_of_friend;
    g_time_consume.resize(g_number_of_pc);
    while (++index < g_number_of_pc)
    {
        std::cin >> g_time_consume[index];
        if (g_time_acc < g_time_consume[index])
            g_time_acc = g_time_consume[index];
    }
    g_time_acc = g_time_acc * g_number_of_friend;
}

void                                                        binary_search(void)
{
    lld                                                     start;
    lld                                                     end;
    lld                                                     mid;
    lld                                                     number_of_person;
    int                                                     index;

    start = 1;
    end = g_time_acc;
    while (start <= end)
    {
        mid = (start + end) / 2;
        number_of_person = 0;
        index = -1;
        while (++index < g_number_of_pc)
            number_of_person += (mid / g_time_consume[index]);
        if (number_of_person < g_number_of_friend)
            start = mid + 1;
        else
        {
            if (g_time_acc > mid)
                g_time_acc = mid;
            end = mid - 1;
        }
    }
}

void                                                        output_action(void)
{
    std::cout << g_time_acc;
}

void                                                        solution(void)
{
    input_action();
    binary_search();
    output_action();
}

int                                                         main(void)
{
    pre_setting();
    solution();
    return (0);
}
