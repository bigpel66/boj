#include <iostream>
#include <vector>

int								g_x;
int								g_y;
int								g_z;
std::vector<std::vector<int> >	g_a;
std::vector<std::vector<int> >	g_b;
std::vector<std::vector<int> >	g_answer;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_x >> g_y;
	g_a = std::vector<std::vector<int> >(g_x, std::vector<int>(g_y, 0));
	for (auto& i:g_a)
		for (auto& j:i)
			std::cin >> j;
	std::cin >> g_y >> g_z;
	g_b = std::vector<std::vector<int> >(g_y, std::vector<int>(g_z, 0));
	for (auto& i:g_b)
		for(auto& j:i)
			std::cin >> j;
	g_answer = std::vector<std::vector<int> >(g_x, std::vector<int>(g_z, 0));
}

void	solution(void)
{
	for (int i = 0; i < g_x; ++i)
		for (int j = 0; j < g_z; ++j)
			for (int k = 0; k < g_y; ++k)
				g_answer.at(i).at(j) += g_a.at(i).at(k) * g_b.at(k).at(j);
}

void	output_action(void)
{
	for (auto& i:g_answer)
	{
		for (auto& j:i)
			std::cout << j << ' ';
		std::cout << '\n';
	}
}

int		main(void)
{
	pre_setting();
	input_action();
	solution();
	output_action();
	return (0);
}
