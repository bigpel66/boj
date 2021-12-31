#include <cstdio>

int		up;
int		down;
int		goal;

void		solution(void)
{
		scanf("%d %d %d", &up, &down, &goal);
		printf("%d", (goal - down - 1) / (up - down)  +1);
}

int		main(void)
{
	solution();
	return (0);
}
