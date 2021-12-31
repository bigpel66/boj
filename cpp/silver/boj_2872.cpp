#include <iostream>
#include <vector>

int		g_number_of_book;
int		g_answer;
std::vector<int> g_books;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	int	i;

	std::cin >> g_number_of_book;
	g_books = std::vector<int>(g_number_of_book, 0);
	i = -1;
	while (++i < g_number_of_book)
		std::cin >> g_books[i];
}

void	greedy_logic(void)
{
	int	i;

	i = g_number_of_book;
	g_answer = g_number_of_book;
	while (i--)
		if (g_books[i] == g_answer)
			--g_answer;
}

void	output_action(void)
{
	std::cout << g_answer;
}

void	solution(void)
{
	input_action();
	greedy_logic();
	output_action();
}

int		main(void)
{
	pre_setting();
	solution();
	return (0);
}
