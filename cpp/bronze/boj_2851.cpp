#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int>				g_scores;
int								g_answer;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	g_scores.reserve(10);
	auto get_data = [] () {
		int data;
		std::cin >> data;
		return (data);
	};
	std::generate_n(std::back_inserter(g_scores), 10, get_data);
}

void	solution(void)
{
	for (const auto& i : g_scores)
	{
		g_answer += i;
		if (g_answer > 100)
		{
			if (g_answer - 100 > 100 - (g_answer - i))
				g_answer -= i;
			break;
		}
	}
}

void	output_action(void)
{
	std::cout << g_answer;
}

int		main(void)
{
	pre_setting();
	input_action();
	solution();
	output_action();
	return (0);
}
