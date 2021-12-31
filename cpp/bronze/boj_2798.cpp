#include <iostream>
#include <vector>
#define endl "\n"

std::vector<int> cards;
int numberOfCards;
int answerNumber;
int nearNumber = 0;

int max(int &a, int &b)
{
    return a > b ? a : b;
}

void inputAction()
{
    std::cin >> numberOfCards >> answerNumber;

    for (int i = 0; i < numberOfCards; i++)
    {
        int temp;

        std::cin >> temp;
        cards.push_back(temp);
    }
}

void calcNumber(int count, int sum, int index)
{
    if (count == 3)
    {
        if (sum <= answerNumber)
        {
            nearNumber = max(nearNumber, sum);
        }

        return;
    }

    if (sum > answerNumber || index >= numberOfCards)
    {
        return;
    }

    calcNumber(count + 1, sum + cards[index], index + 1);
    calcNumber(count, sum, index + 1);
}

void outputAction()
{
    std::cout << nearNumber << endl;
}

void solution()
{
    inputAction();
    calcNumber(0, 0, 0);
    outputAction();
}

int main(void)
{
    solution();

    return 0;
}
