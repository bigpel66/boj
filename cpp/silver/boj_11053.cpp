#include <algorithm>
#include <iostream>
#include <vector>

size_t	g_no_seq;
std::vector<int> g_seq;
std::vector<int> g_memoi;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_no_seq;
	g_seq = std::vector<int>(g_no_seq + 1, 0);
	g_memoi = std::vector<int>(g_no_seq + 1, 1);
	g_memoi[0] = 0;
	for (size_t i = 1; i <= g_no_seq; i++)
		std::cin >> g_seq[i];
}

void	logic(void)
{
	int	tmp;

	for (size_t i = 1; i <= g_no_seq; i++)
	{
		tmp = g_memoi[0];
		for (size_t j = 1; j < i; j++)
			if (g_seq[j] < g_seq[i])
				tmp = std::max(tmp, g_memoi[j]);
		g_memoi[i] += tmp;
	}
}

void	output_action(void)
{
	int	ans;

	ans = g_memoi[1];
	for (size_t i = 2; i <= g_no_seq; i++)
		ans = std::max(ans, g_memoi[i]);
	std::cout << ans;
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
