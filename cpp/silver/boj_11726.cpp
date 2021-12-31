#include <iostream>
#include <vector>

int		g_n_size;
std::vector<int> g_memoization;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_n_size;
	g_memoization = std::vector<int>(g_n_size + 1, 0);
	g_memoization[1] = 1;
	g_memoization[2] = 2;
}

void	logic(void)
{
	int	i;

	i = 2;
	while (++i <= g_n_size)
	{
		g_memoization[i] = g_memoization[i - 2] + g_memoization[i - 1];
		if (g_memoization[i] >= 10007)
			g_memoization[i] %= 10007;
	}
}

void	output_action(void)
{
	std::cout << g_memoization[g_n_size];
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
