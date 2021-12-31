#include <cstdio>
#include <cstring>
#include <vector>

std::vector<int>                g_chain[10001];
bool                            g_visited[10001];
int                             g_result[10001];
int                             g_count = 0;
int                             g_max_count = -1;
int                             g_number_of_com;
int                             g_number_of_relation;

void                            input_action(void)
{
    int                         index;
    int                         input1;
    int                         input2;

    index = -1;
    scanf("%d %d", &g_number_of_com, &g_number_of_relation);
    while (++index < g_number_of_relation)
    {
        scanf("%d %d", &input1, &input2);
        g_chain[input2].push_back(input1);
    }
}

void                            dfs(int start)
{
    int                         index;
    int                         size;
    int                         next;

    index = -1;
    size = static_cast<int>(g_chain[start].size());
    g_visited[start] = true;
    while (++index < size)
    {
        next = g_chain[start][index];
        if (!g_visited[next])
        {
            ++g_count;
            dfs(next);
        }
    }
}

void                            output_action(void)
{
    int                         index;

    index = -1;
    while (++index <= g_number_of_com)
        if(g_result[index] == g_max_count)
            printf("%d ", index);
}

void                            solution(void)
{
    int                         index;

    index = -1;
    input_action();
    memset(g_result, -1, sizeof(g_result));
    while (++index <= g_number_of_com)
    {
        if (g_chain[index].size() != 0)
        {
            memset(g_visited, false, sizeof(g_visited));
            g_count = 0;
            dfs(index);
            if (g_count > g_max_count)
                g_max_count = g_count;
            g_result[index] = g_count;
        }
    }
    output_action();
}

int                             main(void)
{
    solution();
    return (0);
}
