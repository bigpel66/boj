#include <cstdio>
#include <vector>

typedef long long lld;

int	    			            	g_number_of_cities;
int	    		    	        	g_max_range;
lld	    		    	        	g_limitation;
lld		    	    	        	g_total_acc;
std::vector<int>	        		g_request_budget;

void		input_action(void)
{
	int     			        	index;
	int		        	        	temp;

	g_max_range = 0;
	g_total_acc = 0;
	index = -1;
	scanf("%d", &g_number_of_cities);
	while (++index < g_number_of_cities)
	{
		scanf("%d", &temp);
		if (g_max_range < temp)
			g_max_range = temp;
		g_total_acc += temp;
		g_request_budget.push_back(temp);
	}
	scanf("%lld", &g_limitation);
}

bool		pre_search(void)
{
	if(g_total_acc <= g_limitation)
		return (0);
	return (1);
}

void		binary_search(void)
{
	lld 		         	    	start;
	lld                             end;
	lld	    		             	mid;
	lld		        	        	acc;
	std::vector<int>::iterator  	iter;

	start = 1;
	end = g_max_range;
	g_max_range = 0;
	while ((end - start) >= 0)
	{
		mid = (start + end) / 2;
		acc = 0;
		iter = g_request_budget.begin();
		while (iter != g_request_budget.end())
		{
			if (*iter <= mid)
				acc += *iter;
			else
				acc += mid;
			++iter;
		}
		if (acc > g_limitation)
			end = mid - 1;
		else
		{
			if (g_max_range < mid)
				g_max_range = mid;
			start = mid + 1;
		}
	}
}

void		output_action(void)
{
	printf("%d", g_max_range);
}

void		solution(void)
{
	input_action();
	if (pre_search())
		binary_search();
	output_action();
}

int	    	main(void)
{
	solution();
	return (0);
}
