#include <iostream>

int main()
{
  char buf[101];
  int count = 0;

  std::cin >> buf;

  for(int i = 0; i < 101; i++)
  {
      if(buf[i] == '\0')
          break;
      else count++;
  }

  for(int i = 0; i < count; i++)
  {
      std::cout << buf[i];
      if((i + 1) % 10 == 0)
      {
          std::cout << "\n";
      }
  }

  return 0;
}
