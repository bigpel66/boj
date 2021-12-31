#include <iostream>
#include <vector>

int		g_depth;
std::vector<std::vector<int>> g_stair;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	int	i;

	std::cin >> g_depth;
	g_stair = std::vector<std ::vector<int>>(g_depth + 1, std::vector<int>(11, 0));
	i = -1;
	while (++i < 10)
		g_stair[1][i] = 1;
}

void	logic(void)
{
	int	i;
	int	j;

	i = 1;
	while (++i <= g_depth)
	{
		g_stair[i][0] = g_stair[i - 1][1];
		j = 0;
		while (++j < 10)
			g_stair[i][j] = (g_stair[i - 1][j - 1] + g_stair[i - 1][j + 1]) % 1000000000;
	}
}

void	output_action(void)
{
	int	i;
	int	answer;

	i = 0;
	answer = 0;
	while (++i < 10)
		answer = (answer + g_stair[g_depth][i]) % 1000000000;
	std::cout << answer;
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
