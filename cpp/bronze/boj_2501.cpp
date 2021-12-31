#include <iostream>

int							g_val;
int							g_order;
int							g_answer;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_val >> g_order;
}

void	solution(void)
{
	int						cnt = 0;

	for (int i = 1; i <= g_val; ++i)
	{
		if (!(g_val % i))
		{
			++cnt;
			if (g_order == cnt)
			{
				g_answer = i;
				return ;
			}
		}
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
