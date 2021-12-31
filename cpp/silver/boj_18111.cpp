#include <limits>
#include <iostream>
#include <vector>

std::pair<int, int>					g_size;
int									g_pock;
std::vector<std::vector<int> >		g_tile;
int									g_height;
int									g_time;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_size.first >> g_size.second >> g_pock;
	g_tile = std::vector<std::vector<int> >(g_size.first, std::vector<int>(g_size.second, 0));
	for (auto&& i : g_tile)
		for (auto&& j : i)
			std::cin >> j;
	g_height = std::numeric_limits<int>::min();
	g_time = std::numeric_limits<int>::max();
}

void	solution(void)
{
	for (int i = 0 ; i <= 256 ; ++i)
	{
		int						func1 = 0;
		int						func2 = 0;
		for (auto&& j : g_tile)
		{
			for (auto&& k : j)
			{
				if (k >= i)
					func1 += k - i;
				else
					func2 += i - k;
			}
		}
		if (func1 + g_pock < func2)
			break ;
		if (g_time >= func1 * 2 + func2)
		{
			g_time = func1 * 2 + func2;
			g_height = i;
		}
	}
}

void	output_action(void)
{
	std::cout << g_time << " " << g_height;
}

int		main(void)
{
	pre_setting();
	input_action();
	solution();
	output_action();
	return (0);
}
