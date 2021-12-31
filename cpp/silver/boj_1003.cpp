#include <algorithm>
#include <iostream>
#include <vector>

int		g_no_test;
int		g_max;
std::vector<int> g_integer;
std::vector<int> g_fibo;

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
	g_max = -1;
	g_integer = std::vector<int>(g_no_test, 0);
	i = -1;
	while (++i < g_no_test)
	{
		std::cin >> g_integer[i];
		g_max = std::max(g_max, g_integer[i]);
	}
	g_fibo = std::vector<int>(g_max + 1, 0);
	g_fibo[1] = 1;
}

void	logic(void)
{
	int	i;

	i = 1;
	while (++i <= g_max)
		g_fibo[i] = g_fibo[i - 1] + g_fibo[i - 2];
}

void	output_action(void)
{
	int	i;

	i = -1;
	while (++i < g_no_test)
	{
		if (g_integer[i] == 0)
			std::cout << 1 << ' ' << g_fibo[g_integer[i]] << '\n';
		else
			std ::cout << g_fibo[g_integer[i] - 1] << ' ' << g_fibo[g_integer[i]] << '\n';
	}
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
