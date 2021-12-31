#include <iostream>

int							g_number;
int							g_avoid;
int							g_answer;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_number >> g_avoid;
}

bool	check(int n)
{
	while (true)
	{
		if (n % 10 == g_avoid)
			return (false);
		n /= 10;
		if (!n)
			return (true);
	}
}

void	solution(void)
{
	int					n;
	int					i;

	n = 1;
	i = 0;
	while (true)
	{
		if (check(n) && ++i == g_number)
		{
			g_answer = n;
			return ;
		}
		++n;
	}
}

void	output_action(void)
{
	std::cout << g_answer;
}

int		main(void)
{
	pre_setting();
	input_action();
	solution();
	output_action();
	return (0);
}
