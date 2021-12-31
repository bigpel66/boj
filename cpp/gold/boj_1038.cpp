#include <iostream>
#include <queue>

typedef long long lld;

std::queue<lld> generateDesc;
int inputValue;
int descCount = 0;

void input()
{
    std::cin >> inputValue;
}

bool isInputOneDigit()
{
    if (inputValue < 10)
    {
        return true;
    }

    return false;
}

void enqueueOneDigit()
{
    for (int i = 1; i < 10; i++)
    {
        generateDesc.push(i);
        ++descCount;
    }
}

void repetitiveRestDigits()
{
    while (1)
    {
        lld pivotNumber = generateDesc.front();
        generateDesc.pop();
        int restNumber = pivotNumber % 10;

        for (int i = 0; i < restNumber; i++)
        {
            lld queueingNumber = pivotNumber * 10 + i;
            if (++descCount == inputValue)
            {
                std::cout << queueingNumber;
                return;
            }
            generateDesc.push(queueingNumber);
        }
    }
}

void solution()
{
    input();
    if (inputValue >= 1023)
    {
        std::cout << -1;
    }
    else if (isInputOneDigit())
    {
        std::cout << inputValue;
    }
    else
    {
        enqueueOneDigit();
        repetitiveRestDigits();
    }
}

int main()
{
    solution();
    return 0;
}
