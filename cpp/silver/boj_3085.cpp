#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::string>				g_mat;
int										g_answer;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	int									size;
	std::cin >> size;
	auto get_data = [size] () {
		std::string						temp;
		temp.reserve(size);
		std::cin >> temp;
		return (temp);
	};
	std::generate_n(std::back_inserter(g_mat), size, get_data);
}

void	check_val(int size)
{
	for (int i = 0 ; i < size ; ++i)
	{
		int								count = 1;
		for (int j = 0 ; j < size - 1 ; ++j)
		{
			if (g_mat[i][j] == g_mat[i][j + 1])
			{
				++count;
				g_answer = std::max(g_answer, count);
			}
			else
				count = 1;
		}
		count = 1;
		for (int j = 0 ; j < size - 1 ; ++j)
		{
			if (g_mat[j][i] == g_mat[j + 1][i])
			{
				++count;
				g_answer = std::max(g_answer, count);
			}
			else
				count = 1;
		}
	}
}

void	adjacent_swap(int size, bool for_row)
{
	for (int i = 0 ; i < size ; ++i)
	{
		for (int j = 0 ; j < size - 1; ++j)
		{
			if (for_row)
				std::swap(g_mat[j][i], g_mat[j + 1][i]);
			else
				std::swap(g_mat[i][j], g_mat[i][j + 1]);
			check_val(size);
			if (for_row)
				std::swap(g_mat[j][i], g_mat[j + 1][i]);
			else
				std::swap(g_mat[i][j], g_mat[i][j + 1]);
		}
	}
}

void	solution(void)
{
	adjacent_swap(g_mat.size(), true);
	adjacent_swap(g_mat.size(), false);
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
