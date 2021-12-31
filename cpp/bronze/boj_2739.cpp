#include <iostream>

int main()
{
    int value;

    std::cin >> value;

    for(int i = 1; i <= 9; i++)
    {
        std::cout << value << " * " << i << " = " << value*i << "\n";
    }

    return 0;
}
