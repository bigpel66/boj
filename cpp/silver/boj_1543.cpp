#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

std::string					g_heystack;
std::string					g_needle;
int							g_answer;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::getline(std::cin, g_heystack);
	std::getline(std::cin, g_needle);
}

void	solution(void)
{
	auto					begin = std::begin(g_heystack);
	auto					end = std::end(g_heystack);

	while (true)
	{
		begin = std::search(begin, end, std::begin(g_needle), std::end(g_needle));
		if (begin != end)
		{
			++g_answer;
			std::advance(begin, g_needle.size());
		}
		else
			break;
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
