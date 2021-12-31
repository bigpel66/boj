#include <cmath>
#include <iostream>
#include <vector>

using	lld = long long;

int		g_v_size;
int		g_t_size;
int		g_q_size;
int		g_u_size;
int		g_s_size;
std::vector<lld> g_v;
std::vector<lld> g_t;
std::vector<lld> g_answer;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	int	i;
	int	h;

	std::cin >> g_v_size >> g_u_size >> g_s_size;
	g_q_size = 0;
	g_q_size += g_u_size;
	g_q_size += g_s_size;
	g_answer.reserve(g_s_size);
	h = static_cast<int>(ceil(log2(g_v_size)));
	g_t_size = (1 << (h + 1));
	g_v = std::vector<lld>(g_v_size);
	g_t = std::vector<lld>(g_t_size);
	i = -1;
	while (++i < g_v_size)
		std::cin >> g_v[i];
}

lld		tree(std::vector<lld> &v, std::vector<lld> &t, int n, int s, int e)
{
	if (s == e)
		t[n] = v[s];
	else
		t[n] = tree(v, t, n * 2 + 1, s, (s + e) / 2) +
			tree(v, t, n * 2 + 2, (s + e) / 2 + 1, e);
	return (t[n]);
}

lld		sum(std::vector<lld> &t, int n, int s, int e, int l, int r)
{
	if (s > r || e < l)
		return (0);
	if (s >= l && e <= r)
		return (t[n]);
	return (sum(t, n * 2 + 1, s, (s + e) / 2, l, r) +
			sum(t, n * 2 + 2, (s + e) / 2 + 1, e, l, r));
}

void	update(std::vector<lld> &t, int n, int s, int e, int i, lld diff)
{
	if (i < s || e < i)
		return ;
	t[n] = t[n] + diff;
	if (s != e)
	{
		update(t, n * 2 + 1, s, (s + e) / 2, i, diff);
		update(t, n * 2 + 2, (s + e) / 2 + 1, e, i, diff);
	}
}

void	logic(void)
{
	int	i;
	int	t;
	lld	v1;
	lld	v2;

	i = -1;
	tree(g_v, g_t, 0, 0, g_v_size - 1);
	while (++i < g_q_size)
	{
		std::cin >> t;
		if (t == 1)
		{
			std::cin >> v1 >> v2;
			--v1;
			update(g_t, 0, 0, g_v_size - 1, v1, v2 - g_v[v1]);
			g_v[v1] = v2;
		}
		else if (t == 2)
		{
			std::cin >> v1 >> v2;
			g_answer.push_back(sum(g_t, 0, 0, g_v_size - 1, v1 - 1, v2 - 1));
		}
	}
}

void	output_action(void)
{
	int	i;

	i = -1;
	while (++i < g_s_size)
		std::cout << g_answer[i] << '\n';
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
