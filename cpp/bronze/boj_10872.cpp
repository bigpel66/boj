#include <iostream>
#include <vector>

int			g_number;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_number;
}

int		solution(int n)
{
	if (n < 2)
		return (1);
	return (n * solution(n - 1));
}

void	output_action(int& n)
{
	std::cout << n;
}

int		main(void)
{
	int		answer;

	pre_setting();
	input_action();
	answer = solution(g_number);
	output_action(answer);
	return (0);
}
