#include <iostream>
#include <vector>

int							g_number;
std::vector<int>			g_check;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_number;
	g_check = std::vector<int>(g_number, 0);
}

void	solution(void)
{
	int						i;
	int						sum;
	int						tmp;

	i = -1;
	while (++i < g_number)
	{
		sum = i;
		tmp = i;
		while (tmp)
		{
			sum += tmp % 10;
			tmp /= 10;
		}
		if (sum == g_number)
			g_check.at(i) = sum;
	}
}

void	output_action(void)
{
	int						i;

	i = -1;
	while (++i < g_number)
		if (g_check.at(i) && std::cout << i)
			return ;
	i = 0;
	std::cout << i;
}

int		main(void)
{
	pre_setting();
	input_action();
	solution();
	output_action();
	return (0);
}
