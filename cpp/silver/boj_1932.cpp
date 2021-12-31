#include <algorithm>
#include <iostream>
#include <vector>

int		g_height;
int		g_max;
std::vector<std::vector<int>> g_triangle;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	int	i;
	int	j;

	std::cin >> g_height;
	g_max = 0;
	g_triangle = std::vector<std::vector<int>>(
		g_height + 1, std::vector<int>(g_height + 1, 0));
	i = 0;
	while (++i <= g_height)
	{
		j = 0;
		while (++j <= i)
			std::cin >> g_triangle[i][j];
	}
}

void	logic(void)
{
	int	i;
	int	j;

	i = 0;
	while (++i <= g_height)
	{
		j = 0;
		while (++j <= i)
			g_triangle[i][j] += std::max(g_triangle[i - 1][j], g_triangle[i - 1][j - 1]);
	}
	i = 0;
	while (++i <= g_height)
		if (g_max < g_triangle[g_height][i])
			g_max = g_triangle[g_height][i];
}

void	output_action(void)
{
	std::cout << g_max;
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
