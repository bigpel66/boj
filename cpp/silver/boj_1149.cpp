#include <algorithm>
#include <iostream>
#include <vector>

int		g_no_test;
std::vector<int> g_cost;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	int	i;

	std::cin >> g_no_test;
	g_cost = std::vector<int>((g_no_test + 2) * 3, 0);
	i = 0;
	while (++i <= g_no_test)
		std::cin >> g_cost[i * 3] >> g_cost[i * 3 + 1] >> g_cost[i * 3 + 2];
}

void	logic(void)
{
	int	i;

	i = 0;
	while (++i <= g_no_test + 1)
	{
		g_cost[i * 3] += std::min(g_cost[(i - 1) * 3 + 1], g_cost[(i - 1) * 3 + 2]);
		g_cost[i * 3 + 1] += std::min(g_cost[(i - 1) * 3], g_cost[(i - 1) * 3 + 2]);
		g_cost[i * 3 + 2] += std::min(g_cost[(i - 1) * 3], g_cost[(i - 1) * 3 + 1]);
	}
}

void	output_action(void)
{
	std::cout << std::min(
		g_cost[(g_no_test + 1) * 3],
		std::min(g_cost[(g_no_test + 1) * 3 + 1], g_cost[(g_no_test + 1) * 3 + 2]));
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
