#include <iostream>

int							g_series;
int							g_answer;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_series;
}

void	solution(void)
{
	int						i;
	int						tmp;
	int						cnt;

	i = 0;
	cnt = 0;
	while (i != g_series)
	{
		tmp = ++cnt;
		while (tmp)
		{
			if (tmp % 1000 == 666 && ++i)
				break;
			tmp /= 10;
		}
	}
	g_answer = cnt;
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
