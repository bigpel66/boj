#include <iostream>
#include <vector>

int						g_participants;
int						g_kim;
int						g_lim;
int						g_answer;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_participants >> g_kim >> g_lim;
	g_answer = -1;
}

void	solution(void)
{
	int					count = 1;

	while (g_participants > 1)
	{
		++g_kim /= 2;
		++g_lim /= 2;
		if (g_kim == g_lim)
			break ;
		++count;
		g_participants /= 2;
	}
	if (g_participants >= 1)
		g_answer = count;
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
