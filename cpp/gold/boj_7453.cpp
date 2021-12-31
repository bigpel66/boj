#include <iostream>
#include <vector>
#include <unordered_map>

typedef long long lld;

std::vector<int>                            g_input[4];
std::unordered_map<int, int>                g_binary;
int                                         g_array_size;
lld                                         g_count;

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
    std::cin >> g_array_size;
    g_count = 0;
    while (++index < 4)
        g_input[index].reserve(g_array_size);
    g_binary.reserve(g_array_size * g_array_size);
    index = -1;
    while (++index < g_array_size)
        std::cin >> g_input[0][index] >> g_input[1][index] >> g_input[2][index] >> g_input[3][index];
}

void                                        allocate_binary(void)
{
    int                                     outer_i;
    int                                     inner_i;
    int                                     sum;

    outer_i = -1;
    while (++outer_i < g_array_size)
    {
        inner_i = -1;
        while (++inner_i < g_array_size)
        {
            sum = g_input[2][outer_i] + g_input[3][inner_i];
            if (g_binary.find(sum) == g_binary.end())
                g_binary.insert(std::make_pair(sum, 1));
            else
                ++g_binary[sum];
        }
    }
}

void                                        find_binary(void)
{
    int                                     outer_i;
    int                                     inner_i;
    int                                     sum;

    outer_i = -1;
    while (++outer_i < g_array_size)
    {
        inner_i = -1;
        while (++inner_i < g_array_size)
        {
            sum = -(g_input[0][outer_i] + g_input[1][inner_i]);
            if (g_binary.find(sum) != g_binary.end())
                g_count += g_binary[sum];
        }
    }
}

void                                        output_action(void)
{
    std::cout << g_count;
}

void                                        solution(void)
{
    input_action();
    allocate_binary();
    find_binary();
    output_action();
}

int                                         main(void)
{
    pre_setting();
    solution();
    return (0);
}
