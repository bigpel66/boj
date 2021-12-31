#include <algorithm>
#include <iostream>
#include <vector>

int		g_n;
int		g_ans;
std::vector<std::vector<int>> g_cost;
std::vector<std::vector<int>> g_dp;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_n;
	g_cost = std::vector<std::vector<int>>(g_n, std::vector<int>(g_n, 0));
	g_dp = std::vector<std::vector<int>>(g_n, std::vector<int>(1 << g_n, 0));
	for (int i = 0; i < g_n; i++)
		for (int j = 0; j < g_n; j++)
			std::cin >> g_cost[i][j];
}

int		tsp(int n, int m)
{
	if ((m == (1 << g_n) - 1) && g_cost[n][0])
		return (g_cost[n][0]);
	if (g_dp[n][m])
		return (g_dp[n][m]);
	g_dp[n][m] = 1000000000;
	for (int i = 0; i < g_n; i++)
		if (!(m & (1 << i)) && g_cost[n][i])
			g_dp[n][m] = std::min(g_dp[n][m], g_cost[n][i] + tsp(i, m | 1 << i));
	return (g_dp[n][m]);
}

void	logic(void)
{
	g_ans = tsp(0, 1);
}

void	output_action(void)
{
	std::cout << g_ans;
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
