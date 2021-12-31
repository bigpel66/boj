#include <iostream>
#include <vector>

using	lld = long long;
int		g_pinary;
std::vector<lld> g_answer;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_pinary;
	g_answer = std::vector<lld>(g_pinary + 1, 0);
	g_answer[1] = 1;
	g_answer[2] = 1;
}

void	logic(void)
{
	int	i;

	i = 2;
	while (++i <= g_pinary)
		g_answer[i] = g_answer[i - 1] + g_answer[i - 2];
}
void	output_action(void)
{
	std::cout << g_answer[g_pinary];
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
