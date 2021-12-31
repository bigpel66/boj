#include <iostream>

int main()
{
    double a, b;

    std:: cin >> a >> b;
    std::cout << std::fixed;
    std::cout.precision(9);
    std:: cout << a/b;

    return 0;
}
