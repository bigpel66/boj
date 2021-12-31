#include <algorithm>
#include <iostream>
#include <vector>

int		g_no_stair;
std::vector<int> g_score;
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

	std::cin >> g_no_stair;
	g_score = std::vector<int>(g_no_stair + 1, 0);
	g_memoization = std::vector<int>(g_no_stair + 1, 0);
	i = 0;
	while (++i <= g_no_stair)
		std::cin >> g_score[i];
	g_memoization[1] = g_score[1];
	g_memoization[2] = g_score[1] + g_score[2];
}

void	logic(void)
{
	int	i;

	i = 2;
	while (++i <= g_no_stair)
		g_memoization[i] = std::max(g_memoization[i - 2] + g_score[i],
									g_memoization[i - 3] + g_score[i - 1] + g_score[i]);
}

void	output_action(void)
{
	std::cout << g_memoization[g_no_stair];
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
