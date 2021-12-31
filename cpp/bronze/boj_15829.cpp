#include <iostream>

int hashingValue;
int lengthOfString;
std::string word;

void inputAction()
{
    std::cin >> lengthOfString >> word;
}

void hashingWord()
{
    long long sum = 0;
    long long exp = 1;

    for (int i = 0; i < lengthOfString; i++)
    {
        sum += (word[i] - 96) * exp;
        sum %= 1234567891;

        exp *= 31;
        exp %= 1234567891;
    }

    hashingValue = sum;
}

void outputAction()
{
    std::cout << hashingValue;
}

void solution()
{
    inputAction();
    hashingWord();
    outputAction();
}

int main(void)
{

    solution();

    return 0;
}
