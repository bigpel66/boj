#include <iostream>
#include <set>
#include <string>
#include <vector>

std::vector<std::vector<std::string> >		g_tile;
std::set<std::string>						g_answer;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	g_tile = std::vector<std::vector<std::string> >(5, std::vector<std::string>(5, std::string(1, '\0')));
	for (auto&& i : g_tile)
		for (auto&& j : i)
			std::cin >> j;
}

void	depth_search(int x, int y, std::string s, int cnt)
{
	int										dx[] = {0, 0, 1, -1};
	int										dy[] = {1, -1, 0, 0};
	if (cnt == 6)
	{
		g_answer.insert(s);
		return ;
	}
	for (int i = 0 ; i < 4 ; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
			continue ;
		depth_search(nx, ny, s + g_tile[nx][ny], cnt + 1);
	}
}

void	solution(void)
{
	for (int i = 0 ; i < 5 ; ++i)
		for (int j = 0 ; j < 5 ; ++j)
			depth_search(i, j, g_tile[i][j], 1);
}

void	output_action(void)
{
	std::cout << g_answer.size();
}

int		main(void)
{
	pre_setting();
	input_action();
	solution();
	output_action();
	return (0);
}
