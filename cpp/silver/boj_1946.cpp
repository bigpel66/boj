#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

int numberOfCase;
int numberOfIteration;
int hiringCount;
int compareOffset;
std::vector<std::pair<int, int>> candidates;

bool compare(std::pair<int, int> &a, std::pair<int, int> &b)
{
    return a.first < b.first;
}

int min(int &a, int &b)
{
    return a < b ? a : b;
}

void inputAction()
{
    for (int i = 0; i < numberOfIteration; i++)
    {
        int cvScore, interviewScore;

        std::cin >> cvScore >> interviewScore;

        candidates.push_back(std::make_pair(cvScore, interviewScore));
    }
}

void getHiringCount()
{
    for (int i = 1; i < numberOfIteration; i++)
    {
        if (compareOffset < candidates[i].second)
        {
            --hiringCount;
        }

        compareOffset = min(compareOffset, candidates[i].second);
    }
}

void outputAction()
{
    std::cout << hiringCount << endl;
}

void solution()
{
    std::cin >> numberOfCase;

    for (int i = 0; i < numberOfCase; i++)
    {

        std::cin >> numberOfIteration;

        candidates.clear();
        hiringCount = numberOfIteration;

        inputAction();

        sort(candidates.begin(), candidates.end(), compare);

        compareOffset = candidates[0].second;

        getHiringCount();

        outputAction();
    }
}

int main(void)
{
    solution();

    return 0;
}
