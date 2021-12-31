#include <iostream>
#include <set>
#include <string>
#include <vector>

using	pii = std::pair<int, int>;

int		g_no_word;
int		g_no_boggle;
std::vector<pii> g_displacement;
std::vector<int> g_score;
std::vector<bool> g_visited;
std::vector<std::string> g_dict;
std::vector<std::vector<std::string>> g_boggle;
std::vector<int> g_point;
std::vector<std::string> g_word;
std::vector<int> g_cnt;
std::string g_cmp;
std::set<std::string> g_candidate;

class Trie
{
	Trie	*next[26];
	bool	is_terminal;

  public:
	Trie();
	~Trie();
	void insert(std::string word);
	void find(int x, int y, std::string word, int idx);
};
Trie::Trie()
{
	std::fill(next, next + 26, nullptr);
	is_terminal = false;
}

Trie::~Trie()
{
	int	i;

	i = -1;
	while (++i < 26)
		if (next[i])
			delete (next[i]);
}

Trie	*g_trie;

void Trie::insert(std::string word)
{
	Trie	*tmp;
	size_t	i;
	size_t	len;
	size_t	n_idx;

	tmp = this;
	i = -1;
	len = word.size();
	while (++i < len)
	{
		n_idx = word[i] - 'A';
		if (!(tmp->next[n_idx]))
			tmp->next[n_idx] = new Trie();
		tmp = tmp->next[n_idx];
	}
	tmp->is_terminal = true;
}

void Trie::find(int x, int y, std::string word, int idx)
{
	Trie	*tmp;

	if (x < 0 || y < 0 || x >= 4 || y >= 4 || g_visited[x * 4 + y] || word.length() >= 8)
		return ;
	g_visited[x * 4 + y] = true;
	word += g_boggle[idx][x][y];
	tmp = this->next[g_boggle[idx][x][y] - 'A'];
	if (!tmp)
	{
		g_visited[x * 4 + y] = false;
		return ;
	}
	if (tmp->is_terminal)
		g_candidate.insert(word);
	for (auto item : g_displacement)
		tmp->find(x + item.first, y + item.second, word, idx);
	g_visited[x * 4 + y] = false;
}

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

	g_trie = new Trie();
	std::cin >> g_no_word;
	g_displacement = { { 0, 1 },  { 1, 1 },   { 1, 0 },  { 1, -1 },
						{ 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 } };
	g_score = { 0, 0, 1, 1, 2, 3, 5, 11 };
	g_visited = std::vector<bool>(16, false);
	g_dict = std::vector<std::string>(g_no_word, std::string('\0', 8));
	i = -1;
	while (++i < g_no_word)
		std::cin >> g_dict[i];
	std::cin >> g_no_boggle;
	g_boggle = std::vector<std::vector<std::string>>(
		g_no_boggle, std::vector<std::string>(4, std::string('\0', 4)));
	g_point = std::vector<int>(g_no_boggle, 0);
	g_word = std::vector<std::string>(g_no_boggle);
	g_cnt = std::vector<int>(g_no_boggle, 0);
	i = -1;
	while (++i < g_no_boggle)
	{
		j = -1;
		while (++j < 4)
			std::cin >> g_boggle[i][j];
	}
}

void	make_trie_tree(void)
{
	int	i;

	i = -1;
	while (++i < g_no_word)
		g_trie->insert(g_dict[i]);
}

void	logic(void)
{
	int	i;
	int	j;

	make_trie_tree();
	i = -1;
	while (++i < g_no_boggle)
	{
		j = -1;
		g_candidate.clear();
		while (++j < 16)
			g_trie->find(j / 4, j % 4, "", i);
		g_cmp = *(g_candidate.begin());
		for (auto item : g_candidate)
		{
			g_point[i] += g_score[item.length() - 1];
			if (g_cmp.length() < item.length())
				g_cmp = item;
		}
		g_word[i] = g_cmp;
		g_cnt[i] = g_candidate.size();
	}
}

void	output_action(void)
{
	int	i;

	i = -1;
	while (++i < g_no_boggle)
		std::cout << g_point[i] << ' ' << g_word[i] << ' ' << g_cnt[i] << '\n';
	delete (g_trie);
	g_trie = nullptr;
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
