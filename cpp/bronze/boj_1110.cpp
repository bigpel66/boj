#include <iostream>

int main()
{
    int count = 0;
    int val;
    int half_lft;
    int half_rht;
    int temp;

    std::cin >> val;

    temp = val;

    while(1)
    {
        half_lft = temp / 10;
        half_rht = temp % 10;

        temp = half_rht;
        half_rht = (half_lft + half_rht) % 10;
        half_lft = temp;
        temp = (half_lft * 10 + half_rht);

        count++;

        if(temp == val)
            break;
    }

    std::cout << count;

    return 0;
}
