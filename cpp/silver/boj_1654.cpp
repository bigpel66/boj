#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long lld;

int					g_number_of_utp;
int					g_required_utp;
lld					g_result_length;
std::vector<int>			g_utp;

void		input_action(void)
{
	int				index;
	int				temp;

	scanf("%d %d", &g_number_of_utp, &g_required_utp);
	index = -1;
	while (++index < g_number_of_utp)
	{
		scanf("%d", &temp);
		g_utp.push_back(temp);
	}
}

void		binary_search(void)
{
	lld				start;
	lld				end;
	lld				mid;
	lld				count;
	std::vector<int>::iterator	iter;

	start = 1;
	end = g_utp[g_number_of_utp - 1];
	while ((end - start) >= 0)
	{
		mid = (start + end) / 2;
		count = 0;
		iter = g_utp.begin();
		while (iter != g_utp.end())
			count += (*iter++ / mid);
		if (count < g_required_utp)
			end = mid - 1;
		else
		{
			if (g_result_length < mid)
				g_result_length = mid;
			start = mid + 1;
		}
	}
}

void		output_action(void)
{
	printf("%lld", g_result_length);
}

void		solution(void)
{
	input_action();
	std::sort(g_utp.begin(), g_utp.end());
	binary_search();
	output_action();
}

int		main(void)
{
	solution();
	return (0);
}
