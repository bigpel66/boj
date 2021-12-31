#include <iostream>
#include <vector>

std::vector<int> g_numbers;
int                             g_min;
int                             g_max;

void    pre_setting(void)
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
}

void    input_action(void)
{
        int     iter;

        std::cin >> iter;
        g_numbers = std::vector<int>(iter, 0);
        for (auto& i:g_numbers)
                std::cin >> i;
        g_min = 2147483647;
        g_max = -2147483648;
}

void    solution(void)
{
        for (auto& i:g_numbers)
        {
                if (g_min > i)
                        g_min = i;
                if (g_max < i)
                        g_max = i;
        }
}

void    output_action(void)
{
        std::cout << g_min << ' ' << g_max;
}

int             main(void)
{
        pre_setting();
        input_action();
        solution();
        output_action();
        return (0);
}
