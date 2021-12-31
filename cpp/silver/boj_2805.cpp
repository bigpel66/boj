#include <cstdio>
#include <vector>

typedef long long lld;

lld			g_number_of_trees;
lld			g_required_heights;
lld			g_max_height;
lld			g_result;
std::vector<lld>	g_forest;

void			input_action(void)
{
	lld		index;
	lld		temp;

	index = -1;
	g_max_height = -1;
	g_result = 0;
	scanf("%lld %lld", &g_number_of_trees, &g_required_heights);
	while (++index < g_number_of_trees)
	{
		scanf("%lld", &temp);
		g_forest.push_back(temp);
		if (g_max_height < temp)
			g_max_height = temp;
	}
}

void			binary_search(void)
{
	lld				acc;
	lld				start;
	lld				end;
	lld				mid;
	std::vector<lld>::iterator	iter;

	start = 0;
	end = g_max_height;
	while ((end - start) >= 0)
	{
		mid = (start + end) / 2;
		acc = 0;
		iter = g_forest.begin();
		while (iter != g_forest.end())
		{
			if (mid < *iter)
				acc += (*iter - mid);
			++iter;
		}
		if (acc == g_required_heights)
		{
			g_result = mid;
			break ;
		}
		else if (acc < g_required_heights)
			end = mid - 1;
		else
		{
			if (g_result <  mid)
				g_result = mid;
			start = mid + 1;
		}
	}
}

void			output_action(void)
{
	printf("%lld", g_result);
}

void			solution(void)
{
	input_action();
	binary_search();
	output_action();
}

int			main(void)
{
	solution();
	return (0);
}
