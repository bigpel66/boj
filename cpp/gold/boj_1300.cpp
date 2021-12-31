#include <iostream>
#include <algorithm>

typedef long long lld;

int                                         matrix_size;
int                                         find_where;
int                                         answer;

void                                        pre_setting(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

void                                        input_action(void)
{
    std::cin >> matrix_size >> find_where;
}

void                                        binary_search(void)
{
    int                                     start;
    int                                     end;
    int                                     mid;
    int                                     index;
    lld                                     count;

    start = 1;
    end = find_where;
    while (start <= end)
    {
        mid = (start + end) / 2;
        index = 0;
        count = 0;
        while (++index <= matrix_size)
            count += static_cast<lld>(std::min(mid / index, matrix_size));
        if (count < static_cast<lld>(find_where))
            start = mid + 1;
        else
        {
            answer = mid;
            end = mid - 1;
        }
    }
}

void                                        output_action(void)
{
    std::cout << answer;
}

void                                        solution(void)
{
    input_action();
    binary_search();
    output_action();
}

int                                         main(void)
{
    pre_setting();
    solution();
    return (0);
}
