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
        g_numbers = std::vector<int>(10000, 0);
        for (int i = 0; i < iter; ++i)
        {
                int     val;
                std::cin >> val;
                ++(g_numbers.at(val - 1));
        }
}

void    output_action(void)
{
        for (int i = 0; i < 10000; ++i)
                for (int j = 0; j < g_numbers[i]; ++j)
                        std::cout << i + 1<< '\n';
}

int             main(void)
{
        pre_setting();
        input_action();
        output_action();
        return (0);
}
