#include <iostream>
#include <vector>

int                                                             g_number_of_marble;
int                                                             g_number_of_group;
int                                                             g_check_sum;
int                                                             g_check_max;
int                                                             g_answer_val;
std::vector<int>                                                g_answer_group;
std::vector<int>                                                g_marbles;

void                                                            pre_setting(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

void                                                            input_action(void)
{
    int                                                         index;

    index = -1;
    std::cin >> g_number_of_marble >> g_number_of_group;
    g_answer_group.reserve(g_number_of_group);
    g_marbles = std::vector<int>(g_number_of_marble, 0);
    g_check_sum = 0;
    g_check_max = 0;
    while (++index < g_number_of_marble)
    {
        std::cin >> g_marbles[index];
        g_check_sum += g_marbles[index];
        g_check_max = std::max(g_check_max, g_marbles[index]);
    }
}

bool                                                            decrease_end(int limit)
{
    int                                                         count;
    int                                                         sum;
    std::vector<int>::iterator                                  iter;

    count = 1;
    sum = 0;
    iter = g_marbles.begin();
    while (iter != g_marbles.end())
    {
        if (sum + *iter > limit)
        {
            ++count;
            sum = 0;
        }
        sum += *iter++;
    }
    return (count <= g_number_of_group);
}

void                                                            binary_search(void)
{
    int                                                         start;
    int                                                         end;
    int                                                         mid;

    start = g_check_max;
    end = g_check_sum;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (decrease_end(mid))
        {
            g_answer_val = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
}

void                                                            make_answer(void)
{
    int                                                         marble_count;
    int                                                         group_count;
    int                                                         sum;
    int                                                         index;

    group_count = g_number_of_group;
    marble_count = 0;
    sum = 0;
    index = -1;
    while (++index < g_number_of_marble)
    {
        if (sum + g_marbles[index] > g_answer_val)
        {
            g_answer_group.push_back(marble_count);
            marble_count = 0;
            sum = 0;
            --group_count;
        }
        sum += g_marbles[index];
        ++marble_count;
        if (g_number_of_marble - index == group_count)
            break;
    }
    index = -1;
    while (++index < group_count)
    {
        g_answer_group.push_back(marble_count);
        marble_count = 1;
    }
}

void                                                            output_action(void)
{
    std::vector<int>::iterator                                  iter;

    iter = g_answer_group.begin();
    std::cout << g_answer_val << '\n';
    while (iter != g_answer_group.end())
        std::cout << *iter++ << ' ';
}

void                                                            solution(void)
{
    input_action();
    binary_search();
    make_answer();
    output_action();
}

int                                                             main(void)
{
    pre_setting();
    solution();
    return (0);
}
