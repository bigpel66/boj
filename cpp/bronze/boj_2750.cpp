#include <iostream>
#include <vector>

std::vector<int> g_numbers;

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
}

void    swap(int& v1, int& v2)
{
        int     temp;

        if (v1 > v2)
        {
                temp = v1;
                v1 = v2;
                v2 = temp;
        }
}

void    solution(void)
{
        int     size;

        size = g_numbers.size();
        for (int i = 0; i < size - 1; ++i)
                for (int j = i + 1; j < size; ++j)
                        swap(g_numbers[i], g_numbers[j]);
}

void    output_action(void)
{
        for (auto& i:g_numbers)
                std::cout << i << '\n';
}

int             main(void)
{
        pre_setting();
        input_action();
        solution();
        output_action();
        return (0);
}
