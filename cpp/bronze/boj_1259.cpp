#include <iostream>
#define endl "\n"

void solution()
{
    while (true)
    {
        std::string temp;
        std::cin >> temp;
        bool palindrome = true;

        if (temp == "0")
        {
            return;
        }

        for (size_t i = 0; i < temp.size() / 2; i++)
        {
            if (temp[i] != temp[temp.size() - 1 - i])
            {
                palindrome = false;
            }
        }

        palindrome ? std::cout << "yes" : std::cout << "no";
        std::cout << endl;
    }
}

int main(void)
{
    solution();

    return 0;
}
