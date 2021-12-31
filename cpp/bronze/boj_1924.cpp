#include <iostream>

int main()
{
    int month, day;
    int count_day;
    int mul_day;
    std::cin >> month >> day;

    count_day = 0;

    if(month == 1)
    {
        count_day = day;
    }

    else
    {
        for (int i = 2; i < month; i++)
        {
            if (i == 2)
                mul_day = 28;
            for (int j = 1; j <= 12; j += 2)
            {
                if (j == i)
                {
                    mul_day = 31;
                    break;
                }
                if (j == 7)
                    j--;
            }
            for (int j = 4; j <= 11; j += 2)
            {
                if (j == i)
                {
                    mul_day = 30;
                    break;
                }
                if (j == 6)
                    j++;
            }
            count_day += mul_day;
        }

        count_day += 31;
        count_day += day;
    }

    count_day %= 7;

    switch(count_day)
    {
        case 0:
            std::cout << "SUN";
            break;
        case 1:
            std::cout << "MON";
            break;
        case 2:
            std::cout << "TUE";
            break;
        case 3:
            std::cout << "WED";
            break;
        case 4:
            std::cout << "THU";
            break;
        case 5:
            std::cout << "FRI";
            break;
        case 6:
            std::cout << "SAT";
            break;
    }

    return 0;
}
