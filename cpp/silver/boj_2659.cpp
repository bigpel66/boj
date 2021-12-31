#include <iostream>
#include <vector>
#include <deque>

std::deque<int> dq(4);
bool isVisited[10000] = {0};
int inputClockNumber;
std::vector<int> totalClockNumbers;

void input()
{

    for (int i = 0; i < 4; i++)
    {
        std::cin >> dq[i];
    }
}

int clockNumber(bool checkVisited)
{
    int findMinNumber = 10000;

    for (int i = 0; i < 4; i++)
    {
        int dqValue = 0;

        for (int j = 0; j < 4; j++)
        {
            dqValue = dqValue * 10 + dq[j];
        }

        if (checkVisited)
        {
            isVisited[dqValue] = true;
        }

        if (findMinNumber > dqValue)
        {
            findMinNumber = dqValue;
        }

        int frontNumber = dq.front();
        dq.pop_front();
        dq.push_back(frontNumber);
    }

    return findMinNumber;
}

bool checkContainZero(int checkValue)
{
    std::string convertedNumber = std::to_string(checkValue);

    for (int i = 0; i < 4; i++)
    {
        if (convertedNumber[i] == '0')
        {
            return true;
        }

        dq.push_back(convertedNumber[i] - '0');
    }

    return false;
}

void findAnswerIndex()
{
    for (int i = 1111; i < 10000; i++)
    {
        if (isVisited[i])
        {
            continue;
        }

        dq.clear();

        if (checkContainZero(i))
        {
            continue;
        }

        totalClockNumbers.push_back(clockNumber(true));
    }
}

void output()
{
    int count = 1;

    for (int i = 0; i < totalClockNumbers.size(); i++)
    {
        if (totalClockNumbers[i] == inputClockNumber)
        {
            std::cout << count;
            return;
        }
        count++;
    }
}

void solution()
{
    input();
    inputClockNumber = clockNumber(false);
    findAnswerIndex();
    output();
}

int main()
{
    solution();
    return 0;
}
