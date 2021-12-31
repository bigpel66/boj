#include <cmath>
#include <iostream>
#include <vector>

using	pdd = std::pair<double, double>;

int		g_no_rat;
int		g_no_hole;
int		g_time_s;
int		g_dist_v;
int		g_answer;
std::vector<bool> g_visited;
std::vector<int> g_hole;
std::vector<pdd> g_pos_rat;
std::vector<pdd> g_pos_hole;
std::vector<std::vector<int>> g_graph;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	int	i;

	std::cin >> g_no_rat >> g_no_hole >> g_time_s >> g_dist_v;
	g_answer = g_no_rat;
	g_hole = std::vector<int>(g_no_hole, -1);
	g_pos_rat = std::vector<pdd>(g_no_rat, std::make_pair(0.0, 0.0));
	g_pos_hole = std::vector<pdd>(g_no_hole, std::make_pair(0.0, 0.0));
	g_graph = std::vector<std::vector<int>>(g_no_rat);
	i = -1;
	while (++i < g_no_rat)
		std::cin >> g_pos_rat[i].first >> g_pos_rat[i].second;
	i = -1;
	while (++i < g_no_hole)
		std::cin >> g_pos_hole[i].first >> g_pos_hole[i].second;
}

double	get_dist(pdd p1, pdd p2)
{
	double	x_diff;
	double	y_diff;

	x_diff = std::pow(p2.first - p1.first, 2);
	y_diff = std::pow(p2.second - p1.second, 2);
	return (std::sqrt(x_diff + y_diff));
}

void	calc_each_rat_to_hole(void)
{
	double	lim;
	int		i;
	int		j;

	lim = static_cast<double>(g_time_s * g_dist_v);
	i = -1;
	while (++i < g_no_rat)
	{
		j = -1;
		while (++j < g_no_hole)
			if (get_dist(g_pos_rat[i], g_pos_hole[j]) <= lim)
				g_graph[i].push_back(j);
	}
}

bool	depth_search(int rat)
{
	int	i;
	int	size;

	if (g_visited[rat])
		return (false);
	g_visited[rat] = true;
	i = -1;
	size = g_graph[rat].size();
	while (++i < size)
	{
		if (g_hole[g_graph[rat][i]] == -1 || depth_search(g_hole[g_graph[rat][i]]))
		{
			g_hole[g_graph[rat][i]] = rat;
			return (true);
		}
	}
	return (false);
}

void	logic()
{
	int	i;

	calc_each_rat_to_hole();
	i = -1;
	while (++i < g_no_rat)
	{
		g_visited = std::vector<bool>(g_no_rat, false);
		if (depth_search(i))
			--g_answer;
	}
}

void	output_action(void)
{
	std::cout << g_answer;
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
