#include <iostream>
#include <vector>

int		g_no_src;
int		g_answer;
std::vector<int> g_src;
std::vector<int> g_lis;
std::vector<int> g_rlis;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	int	i;

	std::cin >> g_no_src;
	g_src = std::vector<int>(g_no_src, 0);
	g_lis = std::vector<int>(g_no_src, 1);
	g_rlis = std::vector<int>(g_no_src, 1);
	i = -1;
	while (++i < g_no_src)
		std::cin >> g_src[i];
}

void	calc_lis(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_no_src)
	{
		j = -1;
		while (++j <= i)
			if (g_src[j] < g_src[i] && g_lis[i] < g_lis[j] + 1)
				g_lis[i] = g_lis[j] + 1;
	}
}

void	calc_rlis(void)
{
	int	i;
	int	j;

	i = g_no_src;
	while (--i >= 0)
	{
		j = g_no_src;
		while (--j >= i)
			if (g_src[j] < g_src[i] && g_rlis[i] < g_rlis[j] + 1)
				g_rlis[i] = g_rlis[j] + 1;
	}
}

void	make_answer(void)
{
	int	i;

	i = -1;
	while (++i < g_no_src)
		g_answer = std::max(g_answer, g_lis[i] + g_rlis[i] - 1);
}

void	logic(void)
{
	calc_lis();
	calc_rlis();
	make_answer();
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
