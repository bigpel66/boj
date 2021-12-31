#include <iostream>
#include <vector>

typedef long long lld;

lld                                                             g_number_of_node;
int                                                             g_child_for_each_node;
int                                                             g_number_of_request;
std::vector<lld>                                                g_answer;
std::vector<std::pair<lld, lld> >                               g_node_pair;

void                                                            pre_setting(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

void                                                            input_action(void)
{
    int                                                         index;

    std::cin >> g_number_of_node >> g_child_for_each_node >> g_number_of_request;
    index = -1;
    g_answer.resize(g_number_of_request);
    g_node_pair.resize(g_number_of_request);
    while (++index < g_number_of_request)
        std::cin >> g_node_pair[index].first >> g_node_pair[index].second;
}

void                                                            calc_dist(void)
{
    int                                                         index;

    index = -1;
    while (++index < g_number_of_request)
    {
        if (g_child_for_each_node == 1)
             g_answer[index] = std::abs(g_node_pair[index].first - g_node_pair[index].second);
        else
            while (g_node_pair[index].first != g_node_pair[index].second)
            {
                if (g_node_pair[index].first < g_node_pair[index].second)
                    g_node_pair[index].second = (g_node_pair[index].second - 2) / g_child_for_each_node + 1;
                else
                    g_node_pair[index].first = (g_node_pair[index].first - 2) / g_child_for_each_node + 1;
                ++(g_answer[index]);
            }
    }
}

void                                                            output_action(void)
{
    int                                                         index;

    index = -1;
    while (++index < g_number_of_request)
        std::cout << g_answer[index] << "\n";
}

void                                                            solution(void)
{
    input_action();
    calc_dist();
    output_action();
}

int                                                             main(void)
{
    pre_setting();
    solution();
    return (0);
}
