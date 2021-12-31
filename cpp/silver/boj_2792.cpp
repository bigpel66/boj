#include <iostream>
#include <vector>

int                                                             g_number_of_child;
int                                                             g_kinds_of_marble;
int                                                             g_envy_level;
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
    std::cin >> g_number_of_child >> g_kinds_of_marble;
    g_envy_level = -1;
    g_marbles.resize(g_kinds_of_marble);
    while (++index < g_kinds_of_marble)
    {
        std::cin >> g_marbles[index];
        if (g_envy_level < g_marbles[index])
            g_envy_level = g_marbles[index];
    }
}

void                                                            binary_search(void)
{
    int                                                         start;
    int                                                         end;
    int                                                         mid;
    int                                                         count;
    int                                                         index;

    start = 1;
    end = g_envy_level;
    g_envy_level = -1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        count = 0;
        index = -1;
        while (++index < g_kinds_of_marble)
            count += ((g_marbles[index] - 1) / mid) + 1;
        if (count <= g_number_of_child)
        {
            g_envy_level = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
}

void                                                            output_action(void)
{
    std::cout << g_envy_level;
}

void                                                            solution(void)
{
    input_action();
    binary_search();
    output_action();
}

int                                                             main(void)
{
    pre_setting();
    solution();
    return (0);
}
