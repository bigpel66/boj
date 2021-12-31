#include <iostream>
#include <vector>

int                                                         g_number_of_island;
int                                                         g_number_of_bridge;
int                                                         g_start;
int                                                         g_end;
int                                                         g_max_weight;
std::vector<std::vector<std::pair<int, int> > >             g_bridge_graph;
std::vector<bool>                                           g_visited;

void                                                        pre_setting(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

void                                                        input_action(void)
{
    int                                                     index;
    int                                                     from;
    int                                                     to;
    int                                                     limitation;

    g_max_weight = -1;
    index = -1;
    std::cin >> g_number_of_island >> g_number_of_bridge;
    g_bridge_graph.resize(g_number_of_island + 1);
    while (++index < g_number_of_bridge)
    {
        std::cin >> from >> to >> limitation;
        if (g_max_weight < limitation)
            g_max_weight = limitation;
        g_bridge_graph[from].push_back(std::make_pair(to, limitation));
        g_bridge_graph[to].push_back(std::make_pair(from, limitation));
    }
    std::cin >> g_start >> g_end;
}

bool                                                        depth_search(int entry, int weight)
{
    std::vector<std::pair<int, int> >::iterator             iter;

    if (g_visited[entry])
        return false;
    g_visited[entry] = true;
    if (entry == g_end)
       return true;
    iter = g_bridge_graph[entry].begin();
    while (iter != g_bridge_graph[entry].end())
    {
        if (iter->second >= weight && depth_search(iter->first, weight))
                return true;
        ++iter;
    }
    return false;
}

void                                                        binary_search(void)
{
    int                                                     start;
    int                                                     end;
    int                                                     mid;

    start = 1;
    end = g_max_weight;
    g_max_weight = -1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        g_visited = std::vector<bool>(g_number_of_island + 1, false);
        if (depth_search(g_start, mid))
        {
            g_max_weight = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
}

void                                                        output_action(void)
{
    /*
    int                                                     index;
    std::vector<std::pair<int, int> >::iterator             iter;

    index = 0;
    while (++index <= g_number_of_island)
    {
        iter = g_bridge_graph[index].begin();
        while (iter != g_bridge_graph[index].end())
        {
            std::cout << "start " << index << " ";
            std::cout << "end " << iter->first << " ";
            std::cout << "limitation " << iter->second << " ";
            std::cout << std::endl;
            ++iter;
        }
        std::cout << std::endl;
    }
    */
    std::cout << g_max_weight;
}

void                                                        solution(void)
{
    input_action();
    binary_search();
    output_action();
}

int                                                         main(void)
{
    pre_setting();
    solution();
    return (0);
}
