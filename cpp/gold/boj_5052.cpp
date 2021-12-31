#include <algorithm>
#include <iostream>
#include <vector>

class Trie
{
	Trie	*next[10];
	bool	is_terminal;
	bool	is_parent;

  public:
	Trie();
	~Trie();
	bool insert(std::string::const_iterator iter);
};
Trie::Trie()
{
	std::fill(next, next + 10, nullptr);
	is_parent = is_terminal = false;
}

Trie::~Trie()
{
	int	i;

	i = -1;
	while (++i < 10)
		if (next[i])
			delete (next[i]);
}

bool Trie::insert(std::string::const_iterator iter)
{
	int		n_idx;
	bool	is_success;

	if (!*iter)
	{
		is_terminal = true;
		if (is_parent)
			return (false);
		return (true);
	}
	n_idx = *iter - '0';
	if (!next[n_idx])
		next[n_idx] = new Trie();
	is_parent = true;
	is_success = next[n_idx]->insert(iter + 1);
	return (!is_terminal && is_success);
}

int		g_no_test;
std::vector<std::vector<std::string>> g_numbers;
std::vector<std::string> g_answer;
void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	int	i;
	int	j;
	int	size;

	std::cin >> g_no_test;
	g_numbers = std::vector<std::vector<std::string>>(g_no_test);
	g_answer = std::vector<std::string>(g_no_test, std::string('\0', 3));
	i = -1;
	while (++i < g_no_test)
	{
		std::cin >> size;
		g_numbers[i] = std::vector<std::string>(size, std::string('\0', 10));
		j = -1;
		while (++j < size)
			std::cin >> g_numbers[i][j];
	}
}

void	logic()
{
	int		i;
	int		j;
	int		size;
	bool	is_possible;
	Trie	*trie;

	i = -1;
	while (++i < g_no_test)
	{
		j = -1;
		size = g_numbers[i].size();
		is_possible = true;
		trie = new Trie();
		while (++j < size)
			if (!(is_possible = trie->insert(g_numbers[i][j].begin())))
				break ;
		g_answer[i] = is_possible ? "YES" : "NO";
		delete (trie);
	}
}

void	output_action(void)
{
	int	i;

	i = -1;
	while (++i < g_no_test)
		std::cout << g_answer[i] << '\n';
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
