#include <iostream>

bool solution(int num) {
    int cmp, dif;

    if (num < 100)
        return true;

    cmp = num % 100;
    dif = (cmp / 10) - (cmp % 10);
    num /= 10;

    while (1) {
        cmp = num % 100;

        if (dif != (cmp / 10) - (cmp % 10))
            return false;

        num /= 10;

        if (!(num / 10))
            break;
    }

    return true;
}

int main() {
    int num;
    int w_count = 0;

    std::cin >> num;

    for (int i = 1; i <= num; i++) {
        if (solution(i)) {
            w_count++;
        }
    }

    std::cout << w_count;

    return 0;
}
