#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using	pii = std::pair<int, int>;

int		g_no_dwarf;
int		g_no_color;
int		g_no_picture;
std::vector<int> g_hat;
std::vector<std::vector<int>> g_idx_cnt;
std::vector<int> g_segment;
std::vector<pii> g_ran;
std::vector<std::string> g_ans;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	int	i;
	int	seg_size;

	std::cin >> g_no_dwarf >> g_no_color;
	seg_size = static_cast<int>(ceil(log2(g_no_dwarf)));
	g_hat = std::vector<int>(g_no_dwarf, 0);
	g_idx_cnt = std::vector<std::vector<int>>(g_no_color);
	g_segment = std::vector<int>((1 << (seg_size + 1)), -1);
	i = -1;
	while (++i < g_no_dwarf)
	{
		std::cin >> g_hat[i];
		g_idx_cnt[g_hat[i] - 1].push_back(i);
	}
	std::cin >> g_no_picture;
	g_ran = std::vector<pii>(g_no_picture, std::make_pair(0, 0));
	g_ans.reserve(g_no_picture);
	i = -1;
	while (++i < g_no_picture)
		std::cin >> g_ran[i].first >> g_ran[i].second;
}

int		count_hat(int n, int s, int e)
{
	int	lower;
	int	upper;

	upper = std::upper_bound(g_idx_cnt[n - 1].begin(), g_idx_cnt[n - 1].end(), e) -
		g_idx_cnt[n - 1].begin();
	lower = std::lower_bound(g_idx_cnt[n - 1].begin(), g_idx_cnt[n - 1].end(), s) -
		g_idx_cnt[n - 1].begin();
	return (upper - lower);
}

void	update_tree(int n, int s, int e, int i, int val)
{
	int	l_child;
	int	r_child;

	l_child = -1;
	r_child = -1;
	if (i < s || e < i)
		return ;
	if (s == e)
	{
		g_segment[n] = val;
		return ;
	}
	update_tree(n * 2 + 1, s, (s + e) / 2, i, val);
	update_tree(n * 2 + 2, (s + e) / 2 + 1, e, i, val);
	l_child = g_segment[n * 2 + 1];
	r_child = g_segment[n * 2 + 2];
	if (l_child != -1 && r_child != -1)
	{
		if (count_hat(l_child, s, e) > (e - s + 1) / 2)
			g_segment[n] = l_child;
		else if (count_hat(r_child, s, e) > (e - s + 1) / 2)
			g_segment[n] = r_child;
		else
			g_segment[n] = -1;
	}
	else if (l_child != -1 && r_child == -1)
	{
		if (count_hat(l_child, s, e) > (e - s + 1) / 2)
			g_segment[n] = l_child;
		else
			g_segment[n] = -1;
	}
	else if (l_child == -1 && r_child != -1)
	{
		if (count_hat(r_child, s, e) > (e - s + 1) / 2)
			g_segment[n] = r_child;
		else
			g_segment[n] = -1;
	}
	else
		g_segment[n] = -1;
}
int		make_answer(int n, int s, int e, int l, int r)
{
	int	l_child;
	int	r_child;

	l_child = -1;
	r_child = -1;
	if (s > r || e < l)
		return (-1);
	if (l <= s && e <= r)
		return (g_segment[n]);
	l_child = make_answer(n * 2 + 1, s, (s + e) / 2, l, r);
	r_child = make_answer(n * 2 + 2, (s + e) / 2 + 1, e, l, r);
	if (l_child != -1 && r_child != -1)
	{
		if (count_hat(l_child, l, r) > (r - l + 1) / 2)
			return (l_child);
		else if (count_hat(r_child, l, r) > (r - l + 1) / 2)
			return (r_child);
		return (-1);
	}
	else if (l_child != -1 && r_child == -1)
	{
		if (count_hat(l_child, l, r) > (r - l + 1) / 2)
			return (l_child);
		return (-1);
	}
	else if (l_child == -1 && r_child != -1)
	{
		if (count_hat(r_child, l, r) > (r - l + 1) / 2)
			return (r_child);
		return (-1);
	}
	return (-1);
}

void	logic()
{
	int	i;
	int	x;

	i = -1;
	while (++i < g_no_dwarf)
		update_tree(0, 0, g_no_dwarf - 1, i, g_hat[i]);
	i = -1;
	while (++i < g_no_picture)
	{
		x = make_answer(0, 0, g_no_dwarf - 1, g_ran[i].first - 1, g_ran[i].second - 1);
		if (x == -1)
			g_ans.push_back("no");
		else
			g_ans.push_back("yes " + std::to_string(x));
	}
}

void	output_action(void)
{
	int	i;

	i = -1;
	while (++i < g_no_picture)
		std::cout << g_ans[i] << '\n';
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
