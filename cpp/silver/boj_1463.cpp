#include <algorithm>
#include <iostream>
#include <vector>

int		g_goal;
std::vector<int> g_memoization;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_goal;
	g_memoization = std::vector<int>(g_goal + 1, 0);
}

void	logic(void)
{
	int	i;

	i = 1;
	while (++i <= g_goal)
	{
		g_memoization[i] = g_memoization[i - 1] + 1;
		if (!(i % 3))
			g_memoization[i] = std::min(g_memoization[i], g_memoization[i / 3] + 1);
		if (!(i % 2))
			g_memoization[i] = std::min(g_memoization[i], g_memoization[i / 2] + 1);
	}
}

void	output_action(void)
{
	std::cout << g_memoization[g_goal];
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
