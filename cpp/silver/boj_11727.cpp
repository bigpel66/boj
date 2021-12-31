#include <iostream>
#include <vector>

int		g_size;
std::vector<int> g_memoi;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_size;
	g_memoi = std::vector<int>(g_size + 1, 0);
	g_memoi[0] = 1;
	g_memoi[1] = 1;
}

void	logic(void)
{
	for (int i = 2; i <= g_size; i++)
	{
		g_memoi[i] = (g_memoi[i - 1] + g_memoi[i - 2] * 2) % 10007;
	}
}

void	output_action(void)
{
	std::cout << g_memoi[g_size];
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
