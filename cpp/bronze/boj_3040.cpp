#include <algorithm>
#include <iostream>
#include <vector>

int					g_cand1;
int					g_cand2;
int					g_total;
std::vector<int>	g_heights;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	g_heights = std::vector<int>(9, 0);
	for (auto& i : g_heights)
	{
		std::cin >> i;
		g_total += i;
	}
}

void	solution(void)
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = i + 1; j < 9; ++j)
		{
			if (g_total - (g_heights.at(i) + g_heights.at(j)) == 100)
			{
				g_cand1 = g_heights.at(i);
				g_cand2 = g_heights.at(j);
				return ;
			}
		}
	}

}

void	output_action(void)
{
	g_heights.erase(std::remove(g_heights.begin(), g_heights.end(), g_cand1), g_heights.end());
	g_heights.erase(std::remove(g_heights.begin(), g_heights.end(), g_cand2), g_heights.end());
	for (auto& i : g_heights)
		std::cout << i << '\n';
}

int		main(void)
{
	pre_setting();
	input_action();
	solution();
	output_action();
	return (0);
}
