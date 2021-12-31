#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

std::array<unsigned char, 4> g_gear;
int		g_no_rot;
std::vector<std::pair<int, int>> g_rot_info;
std::array<int, 8> g_score;
std::array<int, 2> g_dir;
std::array<bool, 4> g_visited;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	unsigned char	tmp;

	for (auto &i : g_gear)
	{
		for (int j = 7; j >= 0; j--)
		{
			std::cin >> tmp;
			tmp -= 48;
			tmp <<= j;
			i += tmp;
		}
	}
	std::cin >> g_no_rot;
	g_rot_info = std::vector<std::pair<int, int>>(g_no_rot, std::make_pair(0, 0));
	for (auto &i : g_rot_info)
		std::cin >> i.first >> i.second;
	g_score = { 0, 1, 0, 2, 0, 4, 0, 8 };
	g_dir = { -1, 1 };
}

void	depth_search(int num, int dir)
{
	int	next;
	int	inter;
	int	origin;
	int	predict;

	g_visited[num] = true;
	origin = g_gear[num];
	if (dir == -1)
		g_gear[num] = (g_gear[num] << 1) + (g_gear[num] >> 7);
	else if (dir == 1)
		g_gear[num] = (g_gear[num] >> 1) + (g_gear[num] << 7);
	for (auto &i : g_dir)
	{
		next = num + i;
		inter = dir == -1 ? 1 : -1;
		if ((next >= 0 && next <= 3) && !g_visited[next])
		{
			predict = g_gear[next];
			if ((i == -1 && ((origin >> 1) & 1) != ((predict >> 5) & 1)) ||
				(i == 1 && ((origin >> 5) & 1) != ((predict >> 1) & 1)))
				depth_search(next, inter);
		}
	}
}

void	logic(void)
{
	for (auto i : g_rot_info)
	{
		std::fill(g_visited.begin(), g_visited.end(), false);
		depth_search(i.first - 1, i.second);
	}
}

void	output_action(void)
{
	int	total;

	total = 0;
	for (int i = 0; i < 4; i++)
		total += g_score[i * 2 + (g_gear[i] >> 7)];
	std::cout << total;
}

void	solution(void)
{
	input_action();
	logic();
	output_action();
}

int		main(void)
{
	pre_setting();
	solution();
	return (0);
}
