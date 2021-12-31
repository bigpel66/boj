#include <cstdio>
#include <vector>
#include <algorithm>

int			g_entry_size;
int			g_find_size;
std::vector<int>	g_binary;

void		input_action(void)
{
	int		index;
	int		temp;

	index = -1;
	scanf("%d", &g_entry_size);
	while (++index < g_entry_size)
	{
		scanf("%d", &temp);
		g_binary.push_back(temp);
	}
}

void		binary_search(int find)
{
	int		start;
	int		end;
	int		mid;

	start = 0;
	end = g_entry_size - 1;
	while ((end - start) >= 0)
	{
		mid = (start + end) / 2;

		if (g_binary[mid] == find)
		{
			printf("1\n");
			return ;
		}
		else if (g_binary[mid] > find)
			end = mid - 1;
		else
			start = mid + 1;
	}
	printf("0\n");
	return ;
}

void		output_action(void)
{
	int		index;
	int		temp;

	index = -1;
	scanf("%d", &g_find_size);
	while (++index < g_find_size)
	{
		scanf("%d", &temp);
		binary_search(temp);
	}
}

void		solution(void)
{
	input_action();
	std::sort(g_binary.begin(), g_binary.end());
	output_action();
}

int		main(void)
{
	solution();
	return (0);
}
