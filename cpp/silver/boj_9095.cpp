#include <iostream>
#include <vector>

int		g_no_test;
std::vector<int> g_integer;
std::vector<std::vector<int>> g_answer;

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
	g_integer = std::vector<int>(g_no_test, 0);
	i = -1;
	while (++i < g_no_test)
		std::cin >> g_integer[i];
	g_answer = std::vector<std::vector<int>>(g_no_test);
	i = -1;
	while (++i < g_no_test)
		g_answer[i].resize(g_integer[i] + 1, 0);
}

void	logic(void)
{
	int i;
	int j;

	i = -1;
	while (++i < g_no_test)
	{
		g_answer[i][1] = 1;
		g_answer[i][2] = 2;
		g_answer[i][3] = 4;
		j = 3;
		while (++j <= g_integer[i])
			g_answer[i][j] = g_answer[i][j - 1] + g_answer[i][j - 2] + g_answer[i][j - 3];
	}
}

void	output_action(void)
{
	int	i;

	i = -1;
	while (++i < g_no_test)
		std::cout << g_answer[i][g_integer[i]] << '\n';
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
