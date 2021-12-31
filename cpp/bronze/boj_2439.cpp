#include <iostream>

int main()
{
    int value;

    std::cin >> value;

    for(int i = 0; i < value; i++)
    {
        for(int j = 0; j < value - i - 1; j++)
        {
            std::cout << " ";
        }

        for(int j = 0; j <= i; j++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    return 0;
}
