#include <iostream>
#include <vector>

int                                                             g_number_of_lecture;
int                                                             g_number_of_disk;
int                                                             g_min_record;
int                                                             g_total_record;
std::vector<int>                                                g_record_of_lecture;

void                                                            pre_setting(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

void                                                            input_action(void)
{
    int                                                         index;

    g_min_record = -1;
    g_total_record = 0;
    index = -1;
    std::cin >> g_number_of_lecture >> g_number_of_disk;
    g_record_of_lecture.resize(g_number_of_lecture);
    while (++index < g_number_of_lecture)
    {
        std::cin >> g_record_of_lecture[index];
        g_total_record += g_record_of_lecture[index];
        if (g_min_record < g_record_of_lecture[index])
            g_min_record = g_record_of_lecture[index];
    }
}

void                                                            binary_search(void)
{
    int                                                         start;
    int                                                         end;
    int                                                         mid;
    int                                                         sum;
    int                                                         count;
    std::vector<int>::iterator                                  iter;

    start = g_min_record;
    end = g_total_record;
    g_min_record = -1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        sum = 0;
        count = 1;
        iter = g_record_of_lecture.begin();
        while (iter != g_record_of_lecture.end())
        {
            if (sum + *iter > mid)
            {
                ++count;
                sum = 0;
            }
            sum += *iter;
            ++iter;
        }
        if (count <= g_number_of_disk)
        {
            g_min_record = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
}

void                                                            output_action(void)
{
    std::cout << g_min_record;
}

void                                                            solution(void)
{
    input_action();
    binary_search();
    output_action();
}

int                                                             main(void)
{
    pre_setting();
    solution();
    return (0);
}
