#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int>                            g_obstacle_b;
std::vector<int>                            g_obstacle_t;
int                                         g_cave_width;
int                                         g_cave_height;
int                                         g_number_of_destruction = 200001;
int                                         g_number_of_case;

void                                        pre_setting(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

void                                        input_action(void)
{
    int                                     index;

    index = -1;
    std::cin >> g_cave_width >> g_cave_height;
    g_obstacle_b.resize(g_cave_width / 2);
    g_obstacle_t.resize(g_cave_width / 2);
    while (++index < (g_cave_width / 2))
        std::cin >> g_obstacle_b[index] >> g_obstacle_t[index];
    std::sort(g_obstacle_b.begin(), g_obstacle_b.end());
    std::sort(g_obstacle_t.begin(), g_obstacle_t.end());
}

void                                        binary_search(void)
{
    int                                     index;
    int                                     count;
    int                                     lower;
    int                                     upper;

    index = 0;
    while (++index <= g_cave_height)
    {
        count = 0;
        lower = std::lower_bound(g_obstacle_b.begin(), g_obstacle_b.end(), index) - g_obstacle_b.begin();
        count += ((g_cave_width / 2) - lower);
        upper = std::upper_bound(g_obstacle_t.begin(), g_obstacle_t.end(), g_cave_height - index) - g_obstacle_t.begin();
        count += ((g_cave_width / 2) - upper);
        if (g_number_of_destruction > count)
        {
            g_number_of_destruction = count;
            g_number_of_case = 1;
        }
        else if (g_number_of_destruction == count)
            ++g_number_of_case;
    }
}

void                                        output_action(void)
{
    std::cout << g_number_of_destruction << ' ' << g_number_of_case;
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
