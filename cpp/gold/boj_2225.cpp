#include <iostream>
#include <vector>

int		g_n;
int		g_k;
std::vector<std::vector<int>> g_memoi;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_n >> g_k;
	g_memoi = std::vector<std::vector<int>>(g_k + 1, std::vector<int>(g_n + 1, 0));
	for (int i = 0; i <= g_n; i++)
		g_memoi[1][i] = 1;
	for (int i = 0; i <= g_k; i++)
		g_memoi[i][0] = 1;
}

void	logic(void)
{
	for (int i = 2; i <= g_k; i++)
		for (int j = 1; j <= g_n; j++)
			g_memoi[i][j] = (g_memoi[i - 1][j] + g_memoi[i][j - 1]) % 1000000000;
}

void	output_action(void)
{
	std::cout << g_memoi[g_k][g_n];
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
