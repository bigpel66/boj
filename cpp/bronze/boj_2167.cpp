#include <iostream>
#include <vector>

int		g_row;
int		g_col;
std::vector<std::vector<int>> g_matrix;
int		g_no_query;
std::vector<std::vector<int>> g_query;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_row >> g_col;
	g_matrix = std::vector<std::vector<int>>(g_row + 1, std::vector<int>(g_col + 1, 0));
	for (int i = 1; i <= g_row; i++)
		for (int j = 1; j <= g_col; j++)
			std::cin >> g_matrix[i][j];
	std::cin >> g_no_query;
	g_query = std::vector<std::vector<int>>(g_no_query, std::vector<int>(4, 0));
	for (int i = 0; i < g_no_query; i++)
		for (int j = 0; j < 4; j++)
			std::cin >> g_query[i][j];
}

void	logic(void)
{
	for (int i = 1; i <= g_row; i++)
		for (int j = 1; j <= g_col; j++)
			g_matrix[i][j] = g_matrix[i][j] + g_matrix[i - 1][j] +
				g_matrix[i][j - 1] - g_matrix[i - 1][j - 1];
}

void	output_action(void)
{
	for (int i = 0; i < g_no_query; i++)
		std::cout << g_matrix[g_query[i][2]][g_query[i][3]] -
				g_matrix[g_query[i][0] - 1][g_query[i][3]] -
				g_matrix[g_query[i][2]][g_query[i][1] - 1] +
				g_matrix[g_query[i][0] - 1][g_query[i][1] - 1]
					<< '\n';
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
