#include <iostream>
#include <vector>
#include <map>
#include <string>
#define endl "\n"

std::map<std::string, int>                  g_ency_poke_num;
std::vector<std::string>                    g_ency_poke_name;
int                                         g_number_of_poke;
int                                         g_number_of_prob;

void                                        input_action(void)
{
    int                                     index;
    std::string                             temp;

    index = -1;
    std::cin >> g_number_of_poke >> g_number_of_prob;
    while (++index < g_number_of_poke)
    {
        std::cin >> temp;
        g_ency_poke_num.insert(std::make_pair(temp, index + 1));
        g_ency_poke_name.push_back(temp);
    }
}

bool                                        is_number(const char& input)
{
    return (input >= '0' && input <= '9');
}

void                                        find_ency(void)
{
    int                                     index;
    std::string                             input;

    index = -1;
    while (++index < g_number_of_prob)
    {
        std::cin >> input;
        if (is_number(input[0]))
            std::cout << g_ency_poke_name[std::stoi(input) - 1] << endl;
        else
            std::cout << g_ency_poke_num.find(input)->second << endl;
    }
}

void                                        solution(void)
{
    input_action();
    find_ency();
}

int                                         main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solution();
    return (0);
}
