#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

int		g_row;
int		g_col;
int		g_map_size;
int		g_car_size;
int		g_parking_size;
int		g_time;
std::string g_map;
std::vector<int> g_car;
std::map<int, int> g_parking;
std::vector<int> g_dist;
std::vector<int> g_bipar;
std::vector<bool> g_visited;
std::vector<std::pair<int, int>> g_dir;
std::vector<std::vector<std::pair<int, int>>> g_graph;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	int	i;

	std::cin >> g_row >> g_col;
	g_map_size = g_row * g_col;
	g_time = -1;
	g_parking_size = 0;
	g_map = std::string(g_map_size, 0);
	i = -1;
	while (++i < g_map_size)
	{
		std::cin >> g_map[i];
		if (g_map[i] == 'C')
			g_car.push_back(i);
		else if (g_map[i] == 'P')
			g_parking[i] = g_parking_size++;
	}
	g_car_size = g_car.size();
	g_dir = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
	g_graph = std::vector<std::vector<std::pair<int, int>>>(g_car_size);
}

void	make_dist(int order)
{
	int	node;
	int	x;
	int	y;
	int	pos;
	int	i;
	int	n_x;
	int	n_y;
	int	n_pos;

	std::queue<int> waiting;
	waiting.push(g_car[order]);
	g_dist = std::vector<int>(g_map_size, -1);
	g_dist[g_car[order]] = 0;
	while (waiting.size())
	{
		node = waiting.front();
		waiting.pop();
		x = node / g_col;
		y = node % g_col;
		pos = x * g_col + y;
		i = -1;
		while (++i < 4)
		{
			n_x = x + g_dir[i].first;
			n_y = y + g_dir[i].second;
			n_pos = n_x * g_col + n_y;
			if (n_x < 0 || n_y < 0 || n_x >= g_row || n_y >= g_col ||
				g_dist[n_pos] != -1 || g_map[n_pos] == 'X')
				continue ;
			if (g_parking.count(n_pos) == 1)
			{
				g_graph[order].push_back({ g_parking[n_pos], g_dist[pos] + 1 });
				g_time = std::max(g_dist[pos] + 1, g_time);
			}
			g_dist[n_pos] = g_dist[pos] + 1;
			waiting.push(n_pos);
		}
	}
}

bool	depth_search(int order, int lim)
{
	if (g_visited[order])
		return (false);
	g_visited[order] = true;
	for (auto i : g_graph[order])
	{
		if (i.second <= lim &&
			(g_bipar[i.first] == -1 || depth_search(g_bipar[i.first], lim)))
		{
			g_bipar[i.first] = order;
			return (true);
		}
	}
	return (false);
}

int		make_match(int lim)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = 0;
	g_bipar = std::vector<int>(g_parking_size, -1);
	while (++i < g_car_size)
	{
		g_visited = std::vector<bool>(g_car_size, false);
		if (depth_search(i, lim))
			++cnt;
	}
	return (cnt);
}

void	binary_search(void)
{
	int	l;
	int	r;
	int	m;

	l = 1;
	r = g_time;
	while (l <= r)
	{
		m = (l + r) >> 1;
		if (make_match(m) >= g_car_size)
        {
            r = m - 1;
        }
		else
			l = m + 1;
	}
    g_time = l;
}
void	output_action(void)
{
	std::cout << g_time;
}

void	solution(void)
{
	int	i;

	input_action();
	if (g_car_size == 0)
		g_time = 0;
	else if (g_car_size > g_parking_size)
		g_time = -1;
	else
	{
		i = -1;
		while (++i < g_car_size)
			make_dist(i);
		binary_search();
		if (make_match(g_time) != g_car_size)
			g_time = -1;
	}
	output_action();
}

int		main(void)
{
	pre_setting();
	solution();
	return (0);
}
