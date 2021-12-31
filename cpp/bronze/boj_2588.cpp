#include <iostream>

int             g_v1;
int             g_v2;

void    pre_setting(void)
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
}

void    input_action(void)
{
        std::cin >> g_v1 >> g_v2;
}

void    output_action(void)
{
        std::cout << g_v1 * (g_v2 % 10) << '\n';
        std::cout << g_v1 * (g_v2 % 100 / 10) << '\n';
        std::cout << g_v1 * (g_v2 / 100) << '\n';
        std::cout << g_v1 * g_v2;
}

int             main(void)
{
        pre_setting();
        input_action();
        output_action();
        return (0);
}
