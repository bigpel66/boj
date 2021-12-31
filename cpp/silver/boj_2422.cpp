#include <iostream>
#include <vector>

int									g_cream;
int									g_limits;
int									g_answer;
std::vector<std::vector<bool> >		g_check;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_cream >> g_limits;
	g_check = std::vector<std::vector<bool> >(g_cream, std::vector<bool>(g_cream, false));
	for (int i = 0; i < g_limits; ++i)
	{
		int						first, second;

		std::cin >> first >> second;
		g_check[first - 1][second - 1] = true;
		g_check[second - 1][first - 1] = true;
	}
}

void	solution(void)
{
	for (int i = 0; i < g_cream - 2; ++i)
	{
		for (int j = i + 1; j < g_cream - 1; ++j)
		{
			if (g_check[i][j])
				continue ;
			for (int k = j + 1; k < g_cream; ++k)
			{
				if (g_check[i][k] || g_check[j][k])
					continue ;
				++g_answer;
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
