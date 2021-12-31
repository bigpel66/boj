#include <iostream>
#include <vector>

using	pii = std::pair<int, int>;

int		g_row;
int		g_col;
std::vector<std::vector<int>> g_map;
std::vector<std::vector<int>> g_memoi;
std::vector<pii> g_dir;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_row >> g_col;
	g_map = std::vector<std::vector<int>>(g_row, std::vector<int>(g_col, 0));
	g_memoi = std::vector<std::vector<int>>(g_row, std::vector<int>(g_col, -1));
	g_dir = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
	for (auto &i : g_map)
		for (auto &j : i)
			std::cin >> j;
}

int		logic(int row, int col)
{
	int	n_row;
	int	n_col;

	if (row == 0 && col == 0)
		return (1);
	if (g_memoi[row][col] == -1)
	{
		g_memoi[row][col] = 0;
		for (auto &i : g_dir)
		{
			n_row = row + i.first;
			n_col = col + i.second;
			if (n_row < g_row && n_row >= 0 && n_col < g_col && n_col >= 0 &&
				g_map[row][col] < g_map[n_row][n_col])
				g_memoi[row][col] += logic(n_row, n_col);
		}
	}
	return (g_memoi[row][col]);
}

void	output_action(void)
{
	std::cout << logic(g_row - 1, g_col - 1);
}

void	solution(void)
{
	input_action();
	output_action();
}

int		main(void)
{
	pre_setting();
	solution();
	return (0);
}
