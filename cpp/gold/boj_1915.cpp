#include <algorithm>
#include <iostream>
#include <vector>

int		g_row;
int		g_col;
int		g_max;
std::vector<std::vector<int>> g_map;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_row >> g_col;
	g_map = std::vector<std::vector<int>>(g_row + 1, std::vector<int>(g_col + 1, 0));
	for (int i = 1; i <= g_row; i++)
	{
		std::string tmp(g_col, '\0');
		std::cin >> tmp;
		for (int j = 0; j < g_col; j++)
			g_map[i][j + 1] = tmp[j] - '0';
	}
}

void	logic(void)
{
	for (int i = 1; i <= g_row; i++)
	{
		for (int j = 1; j <= g_col; j++)
		{
			if (g_map[i][j])
			{
				g_map[i][j] =
					std::min({ g_map[i - 1][j], g_map[i][j - 1], g_map[i - 1][j - 1] }) + 1;
				g_max = std::max(g_max, g_map[i][j]);
			}
		}
	}
}

void	output_action(void)
{
	std::cout << g_max * g_max;
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
