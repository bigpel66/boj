#include <iostream>
#include <vector>

std::vector<int> g_heap;

void    pre_setting(void)
{
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
}

void    input_action(void)
{
        int     iter;

        std::cin >> iter;
        g_heap = std::vector<int>(iter, 0);
        for (auto& i:g_heap)
                std::cin >> i;
}

void    swap(int& v1, int &v2)
{
        int temp;

        temp = v1;
        v1 = v2;
        v2 = temp;
}

void    max_heapify(int cur, int size)
{
        int     max;
        int     left;
        int right;

        max = cur;
        left = cur * 2 + 1;
        right = cur * 2 + 2;
        if (left < size && g_heap.at(max) < g_heap.at(left))
                max = left;
        if (right < size && g_heap.at(max) < g_heap.at(right))
                max = right;
        if (max != cur)
        {
                swap(g_heap.at(max), g_heap.at(cur));
                max_heapify(max, size);
        }
}

void    build_heap(int size)
{
        int     iter;

        iter = size / 2 - 1;
        for (int i = iter; i >= 0; --i)
                max_heapify(i, size);
}

void    solution(void)
{
        int     size;

        size = g_heap.size();
        build_heap(size);
        for (int i = size - 1; i >= 0; --i)
        {
                swap(g_heap.at(0), g_heap.at(i));
                max_heapify(0, i);
        }
}

void    output_action(void)
{
        for (auto& i:g_heap)
                std::cout << i << '\n';
}

int             main(void)
{
        pre_setting();
        input_action();
        solution();
        output_action();
        return (0);
}
