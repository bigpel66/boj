#include <iostream>
#include <algorithm>
#include <cmath>

double                                                          g_ladder_x;
double                                                          g_ladder_y;
double                                                          g_diff_c;
double                                                          g_result;

void                                                            pre_setting(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

void                                                            input_action(void)
{
    std::cin >> g_ladder_x >> g_ladder_y >> g_diff_c;
}

void                                                            binary_search(void)
{
    double                                                      start;
    double                                                      end;
    double                                                      mid;
    double                                                      x_height;
    double                                                      y_height;
    double                                                      diff_approx;

    start = 0.0;
    end = std::min(g_ladder_x, g_ladder_y);
    while (start <= end)
    {
        mid = (start + end) / 2;
        x_height = std::sqrt(g_ladder_x * g_ladder_x - mid * mid);
        y_height = std::sqrt(g_ladder_y * g_ladder_y - mid * mid);
        diff_approx = (x_height * y_height) / (x_height + y_height);
        if (diff_approx >= g_diff_c)
        {
            g_result = mid;;
            start = mid + 0.000001;
        }
        else
            end = mid - 0.000001;
    }
}

void                                                            output_action(void)
{
    std::cout.setf(std::ios::fixed);
    std::cout.precision(3);
    std::cout << g_result;
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
