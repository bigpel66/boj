#include <algorithm>
#include <iostream>
#include <vector>

size_t	g_no_card;
std::vector<size_t> g_bunch;
std::vector<size_t> g_memoi;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_no_card;
	g_bunch = std::vector<size_t>(g_no_card + 1, 0);
	g_memoi = std::vector<size_t>(g_no_card + 1, 0);
	for (size_t i = 1; i <= g_no_card; i++)
		std::cin >> g_bunch[i];
}

void	logic(void)
{
	for (size_t i = 1; i <= g_no_card; i++)
	{
		g_memoi[i] = g_memoi[0];
		for (size_t j = 1; j <= i; j++)
			g_memoi[i] = std::max(g_memoi[i], g_bunch[j] + g_memoi[i - j]);
	}
}

void	output_action(void)
{
	std::cout << g_memoi[g_no_card];
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
