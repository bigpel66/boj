#include <algorithm>
#include <iostream>
#include <string>

long long		g_base10;
std::string		g_base2;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_base10;
}

void	solution(void)
{
	if (g_base10 < 2)
	{
		g_base2.push_back(g_base10 + '0');
		return ;
	}
	g_base2.push_back(g_base10 % 2 + '0');
	g_base10 /= 2;
	solution();
}

void	output_action(void)
{
	std::reverse(g_base2.begin(), g_base2.end());
	std::cout << g_base2;
}

int		main(void)
{
	pre_setting();
	input_action();
	solution();
	output_action();
	return (0);
}
