#include <iostream>
#include <queue>
#define endl "\n"

int numberOfCards;
std::queue<int> cards;

void inputAction()
{
    std::cin >> numberOfCards;

    for (int i = 0; i < numberOfCards; i++)
    {
        cards.push(i + 1);
    }
}

void dropAndRotate()
{
    while (cards.size() != 1)
    {
        cards.pop();
        cards.push(cards.front());
        cards.pop();
    }
}

void outputAction()
{
    std::cout << cards.front() << endl;
}

void solution()
{
    inputAction();
    dropAndRotate();
    outputAction();
}

int main(void)
{
    solution();

    return 0;
}
