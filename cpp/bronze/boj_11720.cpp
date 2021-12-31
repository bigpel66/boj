#include <iostream>

int main()
{
    int val;
    char temp;
    int sum = 0;

    std::cin >> val;


    for(int i = 0; i < val; i++)
    {
        std::cin >> temp;
        sum += (int)(temp - 48);
    }

    std::cout << sum;

    return 0;
}
