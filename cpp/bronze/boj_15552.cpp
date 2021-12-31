#include <iostream>

int main()
{
  int val;
  int a, b;

  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);
  
  std::cin >> val;

  for(int i = 0; i < val; i++)
  {
      std::cin >> a >> b;
      std::cout << a+b << "\n";
  }

  return 0;
}
