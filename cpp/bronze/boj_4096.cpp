#include <iostream>
#include <iterator>
#include <vector>
#include <string>

std::vector<std::string>				g_palin;
std::vector<int>						g_diff;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::string							temp;

	while (true)
	{
		std::cin >> temp;
		if (temp.compare("0"))
			g_palin.push_back(temp);
		else
			break;
	}
	g_diff = std::vector<int>(g_palin.size(), 0);
}

bool	palin(std::string& str)
{
	int									size = str.size() / 2;
	std::string::reverse_iterator		iter = str.rbegin();

	for (auto i = str.begin(); i < str.begin() + size; ++i)
	{
		if (*i != *iter)
			return (false);
		++iter;
	}
	return (true);
}

void	increment(std::string& str, int& cnt)
{
	std::string::reverse_iterator		iter = str.rbegin();

	++cnt;
	while (true)
	{
		*iter += 1;
		if (!std::isdigit(*iter))
		{
			*iter = '0';
			++iter;
		}
		else
			return ;
	}
}

void	solution(void)
{
	int							cnt;

	for (auto& i : g_palin)
	{
		cnt = 0;
		while (true)
		{
			if (palin(i))
			{
				g_diff.at(&i - &g_palin.at(0)) = cnt;
				break ;
			}
			else
				increment(i, cnt);
		}
	}
}

void	output_action(void)
{
	for (auto& i : g_diff)
		std::cout << i << '\n';
}

int		main(void)
{
	pre_setting();
	input_action();
	solution();
	output_action();
	return (0);
}
