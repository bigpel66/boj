#include <iostream>
#include <vector>

int		g_no_case;
int		g_answer;
int		g_tmp;
std::vector<int> g_serial;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	int	i;

	std::cin >> g_no_case;
	g_serial = std::vector<int>(g_no_case + 1, 0);
	i = -1;
	while (++i < g_no_case)
		std::cin >> g_serial[i];
	g_answer = g_serial[0];
	g_tmp = g_serial[0];
}

void	logic(void)
{
	int	i;

	i = 0;
	while (++i < g_no_case)
	{
		g_tmp += g_serial[i];
		if (g_tmp < g_serial[i])
			g_tmp = g_serial[i];
		g_answer = std::max(g_answer, g_tmp);
	}
}

void	output_action(void)
{
	std::cout << g_answer;
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
