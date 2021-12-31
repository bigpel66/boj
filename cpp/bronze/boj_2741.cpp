#include <iostream>

int main()
{
    int value;

    std::cin >> value;

    for(int i = 0; i < value; i++)
    {
        std::cout << i + 1 << "\n";
    }

    return 0;
}
