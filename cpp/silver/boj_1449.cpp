#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

int numberOfHoles;
int numberOfTapes;
int lengthOfTape;
std::vector<int> posOfHoles;

void inputAction()
{
    std::cin >> numberOfHoles >> lengthOfTape;

    for (int i = 0; i < numberOfHoles; i++)
    {
        int temp;
        std::cin >> temp;
        posOfHoles.push_back(temp);
    }

    std::sort(posOfHoles.begin(), posOfHoles.end());
}

void calcTapes()
{
    int offset = posOfHoles[0];
    numberOfTapes = 1;

    for (int i = 1; i < numberOfHoles; i++)
    {
        if (posOfHoles[i] - offset > lengthOfTape - 1)
        {
            offset = posOfHoles[i];
            ++numberOfTapes;
        }
    }
}

void outputAction()
{
    std::cout << numberOfTapes << endl;
}

void solution()
{
    inputAction();
    calcTapes();
    outputAction();
}

int main(void)
{
    solution();

    return 0;
}
