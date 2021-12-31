#include <iostream>

int main()
{
    int num;
    double *arr;
    double max;
    double sum = 0;

    std::cin >> num;

    arr = new double[num];

    for(int i = 0; i < num; i++)
    {
        std::cin >> arr[i];
    }

    max = arr[0];

    for(int i = 0; i < num; i++)
    {
        if(max < arr[i])
            max = arr[i];
    }

    for(int i = 0; i < num; i++)
    {
       arr[i] = (arr[i] / max) * 100;
       sum += arr[i];
    }

    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << sum / num;

    delete [] arr;

    return 0;
}
