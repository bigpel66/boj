#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

const std::string							g_proxy = "ATGC";
std::pair<size_t, size_t>					g_size;
std::vector<std::string>					g_dna;
std::map<char, size_t>						g_stat;
std::pair<std::string, size_t>				g_answer;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_size.first >> g_size.second;
	g_dna.reserve(g_size.first);
	auto get_data = [] () {
		std::string						temp;
		temp.reserve(g_size.second);
		std::cin >> temp;
		return (temp);
	};
	std::generate_n(std::back_inserter(g_dna), g_size.first, get_data);
	for (int i = 0 ; i < 4 ; ++i)
		g_stat.insert(std::make_pair(g_proxy[i], 0));
}

void	solution(void)
{
	std::string							candidate(g_size.second, '0');
	size_t								count = 0;

	auto less_data = [] (const auto& a, const auto& b) {
		return (a.second < b.second);
	};
	for (size_t i = 0 ; i < g_size.second ; ++i)
	{
		for (auto& str : g_dna)
			++g_stat[str[i]];
		auto iter = std::max_element(std::begin(g_stat), std::end(g_stat), less_data);
		candidate[i] = iter->first;
		for (auto& str : g_dna)
			if (str[i] != candidate[i])
				++count;
		std::for_each(std::begin(g_stat), std::end(g_stat), [] (auto& data) { data.second = 0; } );
	}
	g_answer = make_pair(candidate, count);
}

void	output_action(void)
{
	std::cout << g_answer.first << "\n" << g_answer.second;
}

int		main(void)
{
	pre_setting();
	input_action();
	solution();
	output_action();
	return (0);
}
