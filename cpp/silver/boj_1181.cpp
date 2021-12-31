#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

int numberOfWords;
std::vector<std::string> words;
std::vector<std::string>::iterator iter;
std::vector<std::string>::iterator uniqueIter;

void inputAction()
{
    std::cin >> numberOfWords;

    for (int i = 0; i < numberOfWords; i++)
    {
        std::string temp;
        std::cin >> temp;
        words.push_back(temp);
    }
}

bool compare(const std::string &a, const std::string &b)
{
    if (a.length() == b.length())
    {
        return a < b;
    }
    else
    {
        return a.length() < b.length();
    }
}

void outputAction()
{
    for (iter = words.begin(); iter != uniqueIter; iter++)
    {
        std::cout << *iter << endl;
    }
}

void solution()
{
    inputAction();
    std::sort(words.begin(), words.end(), compare);
    uniqueIter = std::unique(words.begin(), words.end());
    outputAction();
}

int main(void)
{
    solution();

    return 0;
}
