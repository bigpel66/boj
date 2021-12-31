#include <iostream>
#include <vector>

std::vector<std::string>			g_tile;
int									g_row;
int									g_col;
int									g_answer;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_row >> g_col;
	g_tile = std::vector<std::string>(g_row, std::string(g_col, '0'));
	for (auto& i : g_tile)
		for (auto& j : i)
			std::cin >> j;
}

void	solution(void)
{
	int								side;

	side = std::min(g_row, g_col);
	for (int i = 0; i < g_row; ++i)
	{
		for (int j = 0; j < g_col; ++j)
		{
			for (int k = 0; k < side; ++k)
			{
				if (i + k < g_row && j + k < g_col)
					if (g_tile[i][j] == g_tile[i][j + k] && g_tile[i][j] == g_tile[i + k][j] && g_tile[i][j] == g_tile[i + k][j + k])
						g_answer = std::max(g_answer, k);
			}
		}
	}
}

void	output_action(void)
{
	std::cout << (g_answer + 1) * (g_answer + 1);
}

int		main(void)
{
	pre_setting();
	input_action();
	solution();
	output_action();
	return (0);
}
