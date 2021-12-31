#include <iostream>

int main()
{
  int a[3];
  int temp;

  for(int i = 0; i < 3; i++)
  {
      std::cin >> a[i];
  }

  for(int i = 0; i < 2; i++) {
      for (int j = i + 1; j < 3; j++) {
          if (a[i] > a[j]) {
              temp = a[i];
              a[i] = a[j];
              a[j] = temp;
          }
      }
  }

  std::cout << a[1];

  return 0;
}
