#include <iostream>

int solution(int i)
{
    int sum = 0;

    sum = i;

    while(i)
    {
        sum = sum + (i % 10);
        i /= 10;
    }

    return sum;
}

int main()
{
    int N = 10000;
    int val;
    bool *arr;

    arr = new bool[N];

    for(int i =  0; i < N; i++)
    {
        val = solution(i + 1);
        if(val <= N)
        {
            arr[val - 1] = true;
        }
    }

    for(int i = 0; i < N; i++)
    {
        if(arr[i] == false)
        {
            std::cout << i + 1 << "\n";
        }
    }

    delete [] arr;

    return 0;
}
