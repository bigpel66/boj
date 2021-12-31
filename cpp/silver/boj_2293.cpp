#include <iostream>

int dp[10001];
int coin[101];
int numberOfCoin;
int combinationNumber;

int main(void)
{
    dp[0] = 1;

    std::cin >> numberOfCoin >> combinationNumber;

    for (int i = 1; i <= numberOfCoin; i++)
    {
        std::cin >> coin[i];
    }

    for (int i = 1; i <= numberOfCoin; i++)
    {
        for (int j = coin[i]; j <= combinationNumber; j++)
        {
            dp[j] += dp[j - coin[i]];
        }
    }

    std::cout << dp[combinationNumber];

    return 0;
}
