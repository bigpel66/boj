#include <iostream>

int main()
{
    int num, val;
    int *arr;

    std::cin >> num >> val;

    arr = new int[num];

    for(int i = 0; i < num; i++)
    {
        std::cin >> arr[i];
    }

    for(int i = 0; i < num; i++)
    {
        if(arr[i] < val)
            std::cout << arr[i] << " ";
    }

    delete [] arr;

    return 0;
}
