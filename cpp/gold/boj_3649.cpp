#include <iostream>
#include <algorithm>
#include <vector>

int x, n, tmp;
std::vector<int> l;

void binary_search()
{
    int left, right, mid;
    
    for (int i = 0; i < n; i++)
    {
        left = i + 1;
        right = n - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (l.at(mid) + l.at(i) < x)
                left = mid + 1;
            else if (l.at(mid) + l.at(i) > x)
                right = mid - 1;
            else
            {
                std::cout << "yes " << l.at(i) << " " << l.at(mid) << "\n";
                return;
            }
        }
    }
    std::cout << "danger\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    while (std::cin >> x >> n)
    {
        x *= 10000000;
        l.resize(n);
        for (int i = 0; i < n; i++)
            std::cin >> l[i];

        std::sort(l.begin(), l.end());
        binary_search();
    }
    return (0);
}
