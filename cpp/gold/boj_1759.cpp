#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"

int theLengthOfAns;
int theLengthOfCandi;
std::vector<std::string> characters;

void dfs(int startPoint, int cnt, int vowels, int consonants, std::vector<std::string> &temp)
{
    if(cnt == theLengthOfAns)
    {
        if(vowels >= 1 && consonants >= 2)
        {
            for(int i = 0; i < theLengthOfAns; i++)
            {
                std::cout << temp.at(i);
            }
            std::cout << endl;
            return;
        }
        else return;
    }
    
    for(int i = startPoint; i < theLengthOfCandi; i++)
    {
        temp.push_back(characters.at(i));
        if(characters.at(i) == "a" ||
           characters.at(i) == "e" ||
           characters.at(i) == "i" ||
           characters.at(i) == "o" ||
           characters.at(i) == "u")
            dfs(i + 1, cnt + 1, vowels + 1, consonants, temp);
        else dfs(i + 1, cnt + 1, vowels, consonants + 1, temp);
        temp.pop_back();
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::cin >> theLengthOfAns >> theLengthOfCandi;
    
    for(int i = 0; i < theLengthOfCandi; i++)
    {
        std::string temp;
        std::cin >> temp;
        characters.push_back(temp);
    }
    
    std::sort(characters.begin(), characters.end());
    
    std::vector<std::string> temp;
    dfs(0, 0, 0, 0, temp);
    
    return 0;
}
