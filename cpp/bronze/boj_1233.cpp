#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

std::vector<size_t>					g_dices;
std::map<size_t, size_t>			g_result;
size_t								g_answer;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	g_dices = std::vector<size_t>(3, 0);
	std::cin >> g_dices.at(0) >> g_dices.at(1) >> g_dices.at(2);
}

void	solution(void)
{
	for (size_t i = 1 ; i <= g_dices.at(0) ; ++i)
		for (size_t j = 1 ; j <= g_dices.at(1) ; ++j)
			for (size_t k = 1 ; k <= g_dices.at(2) ; ++k)
				++g_result[ i + j + k ];
	auto find_data = [] (const auto& i, const auto& j) {
		return (i.second < j.second);
	};
	auto iter = std::max_element(std::begin(g_result), std::end(g_result), find_data);
	g_answer = iter->first;
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
