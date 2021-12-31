#include <iostream>

int		g_row;
int		g_col;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_row >> g_col;
}

void	output_action(void)
{
	std::cout << g_row * g_col - 1;
}

void	solution(void)
{
	input_action();
	output_action();
}

int		main(void)
{
	pre_setting();
	solution();
	return (0);
}
