#include <algorithm>
#include <iostream>
#include <vector>

int		g_no_wine;
std::vector<int> g_quantity;
std::vector<int> g_memoization;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	int	i;

	std::cin >> g_no_wine;
	g_quantity = std::vector<int>(g_no_wine + 1, 0);
	g_memoization = std::vector<int>(g_no_wine + 1, 0);
	i = 0;
	while (++i <= g_no_wine)
		std::cin >> g_quantity[i];
	g_memoization[1] = g_quantity[1];
	g_memoization[2] = g_quantity[1] + g_quantity[2];
}

void	logic(void)
{
	int	i;

	i = 2;
	while (++i <= g_no_wine)
	{
		g_memoization[i] = g_quantity[i] +
			std::max(g_memoization[i - 2], g_memoization[i - 3] + g_quantity[i - 1]);
		g_memoization[i] = std::max(g_memoization[i - 1], g_memoization[i]);
	}
}

void	output_action(void)
{
	std::cout << g_memoization[g_no_wine];
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
