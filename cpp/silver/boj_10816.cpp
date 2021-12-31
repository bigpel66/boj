#include <vector>
#include <algorithm>
#include <cstdio>

std::vector<int>                        g_deck;
int                                     g_number_of_cards;
int                                     g_number_of_validation;

void                                    solution(void)
{
    int                                 index;
    int                                 temp;

    index = -1;
    scanf("%d", &g_number_of_cards);
    while (++index < g_number_of_cards)
    {
        scanf("%d", &temp);
        g_deck.push_back(temp);
    }
    std::sort(g_deck.begin(), g_deck.end());
    index = -1;
    scanf("%d", &g_number_of_validation);
    while (++index < g_number_of_validation)
    {
        scanf("%d", &temp);
        printf("%ld ", std::upper_bound(g_deck.begin(), g_deck.end(), temp) - lower_bound(g_deck.begin(), g_deck.end(), temp));
    }
}

int                                     main(void)
{
    solution();
    return (0);
}
