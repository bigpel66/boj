#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

std::vector<std::pair<int, std::string>> members;
int numberOfMembers;

bool compare(const std::pair<int, std::string> &a, const std::pair<int, std::string> &b)
{
    // if (a.first == b.first)
    // {
    //     return false;
    // }

    return a.first < b.first;
}

void inputAction()
{
    std::cin >> numberOfMembers;

    for (int i = 0; i < numberOfMembers; i++)
    {
        int tempInt;
        std::string tempString;

        std::cin >> tempInt >> tempString;
        members.push_back(std::make_pair(tempInt, tempString));
    }
}

void outputAction()
{
    for (auto iter = members.begin(); iter != members.end(); iter++)
    {
        std::cout << iter->first << ' ' << iter->second << endl;
    }
}

void solution()
{
    inputAction();
    std::stable_sort(members.begin(), members.end(), compare);
    outputAction();
}

int main(void)
{
    solution();

    return 0;
}
