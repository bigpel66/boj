#include <iostream>

int main()
{
    int value;

    std::cin >> value;

    for(int i = value; i >= 1; i--)
    {
        std::cout << i << "\n";
    }

    return 0;
}
