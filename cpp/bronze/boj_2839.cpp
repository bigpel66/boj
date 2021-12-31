#include <iostream>

int main() {
    int value;
    int rest, quo_5, quo_3;
    int temp;

    std::cin >> value;

    quo_5 = value / 5;
    rest = value % 5;

    while(quo_5 >= 0)
    {
        if (rest % 3 == 0)
        {
            quo_3 = rest / 3;
            break;
        }

        else {
            quo_5--;
            rest += 5;
        }
    }

    if(quo_5 >= 0)
        std::cout << quo_5 + quo_3;
    else
        std::cout << - 1;

    return 0;
}
