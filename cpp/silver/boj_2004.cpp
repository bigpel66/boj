#include <iostream>
#define lld long long
#define endl "\n"

lld nValue;
lld mValue;
lld subValue;
std::pair<lld, lld> nValueCounter;
std::pair<lld, lld> mValueCounter;
std::pair<lld, lld> subValueCounter;

void input() {
    std:: cin >> nValue >> mValue;
    
    subValue = nValue - mValue;
}

lld countNumber(lld number, int multiplier) {
    lld count = 0;
    for(lld i = multiplier; i <= number; i *= multiplier){
        count += number / i;
    }
    
    return count;
}

void getPairValue() {
    nValueCounter.first = countNumber(nValue, 2);
    nValueCounter.second = countNumber(nValue, 5);
    
    mValueCounter.first = countNumber(mValue, 2);
    mValueCounter.second = countNumber(mValue, 5);
    
    subValueCounter.first = countNumber(subValue, 2);
    subValueCounter.second = countNumber(subValue, 5);
}

void solution() {
    lld totalCountOfTwo = nValueCounter.first - mValueCounter.first - subValueCounter.first;
    lld totalCountOfFive = nValueCounter.second - mValueCounter.second - subValueCounter.second;
    
    totalCountOfTwo > totalCountOfFive ? std::cout << totalCountOfFive : std::cout << totalCountOfTwo;
}

int main() {
    input();
    getPairValue();
    solution();
    
    return 0;
}
