#include <vector>
#include <algorithm>
#include <cstdio>

std::vector<int>                        g_pos;
int                                     g_number_of_house;
int                                     g_number_of_wifi;
int                                     g_max_dist = -1;

void                                    input_action(void)
{
    int                                 index;
    int                                 temp;

    index = -1;
    scanf("%d %d", &g_number_of_house, &g_number_of_wifi);
    while (++index < g_number_of_house)
    {
        scanf("%d", &temp);
        g_pos.push_back(temp);
    }
    std::sort(g_pos.begin(), g_pos.end());
}

bool                                    enough_wifi(int dist)
{
    int                                 count;
    int                                 curr;
    int                                 next;

    count = 1;
    curr = 0;
    next = 1;
    while (next < g_number_of_house)
    {
        if(g_pos[next] - g_pos[curr] < dist)
            ++next;
        else
        {
            ++count;
            if (count == g_number_of_wifi)
                return true;
            curr = next;
            next = curr + 1;
        }
    }
    return false;
}

void                                    binary_search()
{
    int                                 start;
    int                                 end;
    int                                 mid;

    start = 1;
    end = g_pos[g_number_of_house - 1] - g_pos[0];
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (enough_wifi(mid))
        {
            if (g_max_dist < mid)
                g_max_dist = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
}

void                                    output_action(void)
{
    printf("%d", g_max_dist);
}

void                                    solution(void)
{
    input_action();
    binary_search();
    output_action();
}

int                                     main(void)
{
    solution();
    return (0);
}
