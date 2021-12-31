#include <iostream>
#include <vector>

std::vector<int> g_numbers;
std::vector<int> g_temp;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	int	iter;

	std::cin >> iter;
	g_numbers = std::vector<int>(iter, 0);
	g_temp = std::vector<int>(iter, 0);
	for (auto& i:g_numbers)
		std::cin >> i;
}

void	merge(int start, int mid, int end)
{
	int	i;
	int	j;
	int	k;

	i = start;
	j = mid + 1;
	k = start;
	while (i <= mid && j <= end)
	{
		if (g_numbers[i] < g_numbers[j])
			g_temp[k++] = g_numbers[i++];
		else
			g_temp[k++] = g_numbers[j++];
	}
	while (i <= mid)
		g_temp[k++] = g_numbers[i++];
	while (j <= end)
		g_temp[k++] = g_numbers[j++];
	k = start - 1;
	while (++k < end + 1)
		g_numbers[k] = g_temp[k];
}

void	solution(int start, int end)
{
	int	mid;

	mid = (start + end) / 2;
	if (start < end)
	{
		solution(start, mid);
		solution(mid + 1, end);
		merge(start, mid, end);
	}
}

void	output_action(void)
{
	for (auto& i:g_numbers)
		std::cout << i << '\n';
}

int		main(void)
{
	pre_setting();
	input_action();
	solution(0, g_numbers.size() - 1);
	output_action();
	return (0);
}
