#include <algorithm>
#include <iostream>
#include <vector>

using pii = std::pair<int,int>;

std::vector<pii> g_coord;

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
        g_coord = std::vector<pii>(iter, pii(0, 0));
        for (auto& i:g_coord)
                std::cin >> i.first >> i.second;
}

bool    compare(pii a, pii b)
{
        if (a.first == b.first)
                return (a.second < b.second);
        else
                return (a.first < b.first);
}

void    solution(void)
{
        std::sort(g_coord.begin(), g_coord.end(), compare);
}

void    output_action(void)
{
        for (auto& i:g_coord)
                std::cout << i.first << ' ' << i.second << '\n';
}

int             main(void)
{
        pre_setting();
        input_action();
        solution();
        output_action();
        return (0);
}
