#include <iostream>

int repeat;
int trackNumber = 1;
int cup1, cup2;

void input()
{
    std::cin >> repeat;
}

void tracking()
{
    for (int i = 0; i < repeat; i++)
    {
        std::cin >> cup1 >> cup2;

        if (cup1 == trackNumber)
        {
            trackNumber = cup2;
        }
        else if (cup2 == trackNumber)
        {
            trackNumber = cup1;
        }
    }
}

void solution()
{
    input();
    tracking();
    std::cout << trackNumber;
}

int main()
{
    solution();
    return 0;
}
