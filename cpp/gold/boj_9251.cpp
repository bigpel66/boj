#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string g_first;
std::string g_second;
int		g_f_size;
int		g_s_size;
std::vector<std::vector<int>> g_lcs;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_first >> g_second;
	g_f_size = g_first.size() + 1;
	g_s_size = g_second.size() + 1;
	g_lcs = std::vector<std::vector<int>>(g_s_size, std::vector<int>(g_f_size, 0));
}

void	logic(void)
{
	int	i;
	int	j;

	i = 0;
	while (++i < g_s_size)
	{
		j = 0;
		while (++j < g_f_size)
		{
			if (g_first[j - 1] == g_second[i - 1])
				g_lcs[i][j] = g_lcs[i - 1][j - 1] + 1;
			else
				g_lcs[i][j] = std::max(g_lcs[i - 1][j], g_lcs[i][j - 1]);
		}
	}
}

void	output_action(void)
{
	std::cout << g_lcs[g_s_size - 1][g_f_size - 1];
}

void	solution(void)
{
	input_action();
	logic();
	output_action();
}

int		main(void)
{
	pre_setting();
	solution();
	return (0);
}
