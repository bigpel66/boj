#include <iostream>
#include <string>

int main()
{
    std::string input;

    while(getline(std::cin, input))
    {
        std::cout << input << std::endl;
    }

    return 0;
}
