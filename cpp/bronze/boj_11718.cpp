#include <iostream>
#include <string>

int main()
{
    std::string input;

    for(;;)
    {
        getline(std::cin, input);
        std::cout << input << std::endl;
        if(input == "")
        {
            break;
        }
    }

    return 0;
}
