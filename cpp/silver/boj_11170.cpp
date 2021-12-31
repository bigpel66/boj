#include <algorithm>
#include <iostream>
#include <vector>

using range = std::pair<int, int>;
size_t								g_trial;
std::vector<range>					g_case;
std::vector<size_t>					g_answer;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_trial;
	auto get_data = [] () {
		range temp;
		std::cin >> temp.first >> temp.second;
		return (temp);
	};
	g_case.reserve(g_trial);
	std::generate_n(std::back_inserter(g_case), g_trial, get_data);
	g_answer.reserve(g_trial);
}

size_t	count_zero(int number)
{
	size_t count = 0;

	while (true)
	{
		if (!(number % 10))
			++count;
		number /= 10;
		if (!number)
			break ;
	}
	return (count);
}

void	solution(void)
{
	for (auto& c : g_case)
	{
		size_t count = 0;
		for (int i = c.first ; i <= c.second; ++i)
			count += count_zero(i);
		g_answer.push_back(count);
	}
}

void	output_action(void)
{
	for (auto& a : g_answer)
		std::cout << a << "\n";
}

int		main(void)
{
	pre_setting();
	input_action();
	solution();
	output_action();
	return (0);
}
