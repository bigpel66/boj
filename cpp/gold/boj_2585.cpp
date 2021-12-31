#include <iostream>
#include <vector>

int		g_number_of_station;
int		g_number_of_through;
int		g_fuel;
std::vector<std::pair<int, int>> g_pos;
std::vector<bool> g_visited;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	int	i;
	int	x;
	int	y;

	std::cin >> g_number_of_station >> g_number_of_through;
	g_pos.reserve(g_number_of_station + 1);
	g_visited.reserve(g_number_of_station + 1);
	g_pos.push_back(std::make_pair(0, 0));
	i = -1;
	while (++i < g_number_of_station)
	{
		std::cin >> x >> y;
		g_pos.push_back(std::make_pair(x, y));
	}
}

int		get_dist(int x1, int y1, int x2, int y2)
{
	return ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

bool	depth_search(int cur, int cnt, int lim)
{
	int	i;
	int	c_to_n;
	int	n_to_e;

	if (cnt > g_number_of_through)
		return (false);
	g_visited[cur] = true;
	i = -1;
	while (++i < g_number_of_station)
	{
		c_to_n = get_dist(g_pos[cur].first, g_pos[cur].second, g_pos[i].first, g_pos[i].second);
		n_to_e = get_dist(g_pos[i].first, g_pos[i].second, 10000, 10000);
		if ((!g_visited[i] && c_to_n <= lim) &&
			(n_to_e <= lim || depth_search(i, cnt + 1, lim)))
			return (true);
	}
	return (false);
}

void	binary_search(void)
{
	int	start;
	int	mid;
	int	end;
	int	dist;

	start = 1;
	end = 1415;
	while (start <= end)
	{
		mid = (start + end) / 2;
		dist = mid * mid * 100;
		g_visited = std::vector<bool>(g_number_of_station + 1, false);
		if (depth_search(0, 0, dist))
			end = mid - 1;
		else
			start = mid + 1;
	}
	g_fuel = start;
}

void	output_action(void)
{
	std::cout << g_fuel;
}

void	solution(void)
{
	input_action();
	binary_search();
	output_action();
}

int		main(void)
{
	pre_setting();
	solution();
	return (0);
}
