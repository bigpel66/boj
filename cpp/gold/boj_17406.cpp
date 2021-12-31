#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

int										g_answer;
std::vector<int>						g_input;
std::vector<std::vector<int> >			g_matrix;
std::vector<std::vector<int> >			g_copied;
std::vector<std::vector<int> >			g_rotate;
std::vector<int>						g_permutation;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	g_input = std::vector<int>(3, 0);
	g_answer = std::numeric_limits<int>::max();
	std::cin >> g_input.at(0) >> g_input.at(1) >> g_input.at(2);
	g_matrix = std::vector<std::vector<int> >(g_input.at(0) + 2, std::vector<int>(g_input.at(1) + 2, 0));
	g_rotate = std::vector<std::vector<int> >(g_input.at(2), std::vector<int>(3, 0));
	g_permutation = std::vector<int>(g_input.at(2), 0);
	for (int i = 1 ; i <= g_input.at(0) ; ++i)
		for (int j = 1 ; j <= g_input.at(1) ; ++j)
			std::cin >> g_matrix.at(i).at(j);
	for (auto& i : g_rotate)
		std::cin >> i.at(0) >> i.at(1) >> i.at(2);
	std::iota(std::begin(g_permutation), std::end(g_permutation), 0);
}

int		min_sum(const std::vector<std::vector<int> >& v)
{
	int									temp;

	temp = std::numeric_limits<int>::max();
	for (int i = 1 ; i <= g_input.at(0) ; ++i)
	{
		int sum = 0;
		for (int j = 1 ; j <= g_input.at(1) ; ++j)
			sum += v.at(i).at(j);
		temp = std::min(temp, sum);
	}
	return (temp);
}

void	rotate(std::vector<std::vector<int> >& v, const int& r, const int& c, const int& d)
{
	int									x, y;
	int									temp1, temp2;

	for (int i = d ; i > 0 ; --i)
	{
		temp1 = v.at(r - i + 1).at(c - i);
		x = r - i;
		y = c + i;
		temp2 = v.at(x).at(y++);
		while (--y > c - i)
			v.at(x).at(y) = v.at(x).at(y - 1);
		v.at(x).at(y) = temp1;
		x = r + i;
		y = c + i;
		temp1 = v.at(x++).at(y);
		while (--x > r - i + 1)
			v.at(x).at(y) = v.at(x - 1).at(y);
		v.at(x).at(y) = temp2;
		x = r + i;
		y = c - i;
		temp2 = v.at(x).at(y--);
		while(++y < c + i - 1)
			v.at(x).at(y) = v.at(x).at(y + 1);
		v.at(x).at(y) = temp1;
		x = r - i;
		y = c - i;
		while (++x < r + i - 1)
			v.at(x).at(y) = v.at(x + 1).at(y);
		v.at(x).at(y) = temp2;
	}
}

void	solution(void)
{
	std::vector<int>					origin = g_permutation;

	do
	{
		g_copied = g_matrix;
		for (auto&& i : g_permutation)
			rotate(g_copied, g_rotate[i].at(0), g_rotate[i].at(1), g_rotate[i].at(2));
		g_answer = std::min(g_answer, min_sum(g_copied));
		std::next_permutation(std::begin(g_permutation), std::end(g_permutation));
	} while (origin != g_permutation);
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
