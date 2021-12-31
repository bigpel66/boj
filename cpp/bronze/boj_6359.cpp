#include <cmath>
#include <iostream>
#include <vector>

int		g_no_test;
std::vector<int> g_room;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	int	i;

	std::cin >> g_no_test;
	g_room = std::vector<int>(g_no_test, 0);
	i = -1;
	while (++i < g_no_test)
		std::cin >> g_room[i];
}
void	output_action(void)
{
	int	i;

	i = -1;
	while (++i < g_no_test)
		std::cout << std::floor(std::sqrt(g_room[i])) << '\n';
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
