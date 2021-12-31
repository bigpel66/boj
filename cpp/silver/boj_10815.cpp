#include <set>
#include <vector>
#include <cstdio>

std::set<int>                           g_deck;
std::vector<int>                        g_validation;
int                                     g_number_of_cards;
int                                     g_number_of_validation;

void                                    input_action(void)
{
    int                                 index;
    int                                 temp;

    index = -1;
    scanf("%d", &g_number_of_cards);
    while (++index < g_number_of_cards)
    {
        scanf("%d", &temp);
        g_deck.insert(temp);
    }
    index = -1;
    scanf("%d", &g_number_of_validation);
    while (++index < g_number_of_validation)
    {
        scanf("%d", &temp);
        g_validation.push_back(temp);
    }
}

void                                    find_number(void)
{
    std::vector<int>::iterator          iter;

    iter = g_validation.begin();
    while (iter != g_validation.end())
    {
        if (g_deck.find(*iter) == g_deck.end())
            printf("0 ");
        else
            printf("1 ");
        ++iter;
    }
}

void                                    solution(void)
{
    input_action();
    find_number();
}

int                                     main(void)
{
    solution();
    return (0);
}
