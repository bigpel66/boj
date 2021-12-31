#include <iostream>
#include <cmath>
#define lld long long
#define endl "\n"

int getLengthOfNumber(lld number) {
    int count  = 0;
    
    while(number >0) {
        number = number >> 1;
        count++;
    }
    
    return count;
}

lld solution(lld number) {
    if(number == 0){
        return 0;
    }
    
    int lengthOfNumber = getLengthOfNumber(number);
    
    lld subtractNumber = (lld)pow(2,lengthOfNumber - 1);
    lld countOfHighestPlaceOnes= number - subtractNumber + 1;
    lld countOfZeroToSubtractNumber = (lengthOfNumber- 1) * (lld)pow(2, lengthOfNumber - 2);
    lld remainNumber = solution(number - subtractNumber);
    
    
    return countOfHighestPlaceOnes + countOfZeroToSubtractNumber+ remainNumber;
}

int main() {
    lld A;
    lld B;
    lld numberOfOnes;
    
    std::cin >> A >> B;

    numberOfOnes = solution(B)- solution(A -  1);
    
    std::cout << numberOfOnes;
    
    return 0;
}
