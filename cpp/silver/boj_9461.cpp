#include <algorithm>
#include <iostream>
#include <vector>

int		g_no_test;
int		g_max;
std::vector<int> g_test;
std::vector<size_t> g_tri;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_no_test;
	g_test = std::vector<int>(g_no_test, 0);
	for (auto &i : g_test)
	{
		std::cin >> i;
		g_max = std::max(g_max, i);
	}
	g_tri = std::vector<size_t>(g_max + 1, 0);
	g_tri[1] = 1;
	g_tri[2] = 1;
}

void	logic(void)
{
	for (int i = 3; i <= g_max; i++)
		g_tri[i] = g_tri[i - 3] + g_tri[i - 2];
}

void	output_action(void)
{
	for (auto &i : g_test)
		std::cout << g_tri[i] << "\n";
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
