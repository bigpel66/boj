#include <iostream>
#include <iterator>
#include <vector>

int								g_seed;
std::vector<int>				g_answer;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_seed;
}

void	solution(void)
{
	for (int i = g_seed - g_seed / 2; i < g_seed - g_seed / 4 + 1; ++i)
	{
		std::vector<int>		temp{g_seed, i};

		while (true)
		{
			int					val;

			val = *(std::rbegin(temp) + 1) - *std::rbegin(temp);
			if (val < 0)
				break ;
			temp.push_back(val);
		}
		if (g_answer.size() < temp.size())
			g_answer = std::move(temp);
	}
}

void	output_action(void)
{
	std::cout << g_answer.size() << "\n";
	std::copy(std::begin(g_answer), std::end(g_answer), std::ostream_iterator<int>(std::cout, " "));
}

int		main(void)
{
	pre_setting();
	input_action();
	solution();
	output_action();
	return (0);
}
