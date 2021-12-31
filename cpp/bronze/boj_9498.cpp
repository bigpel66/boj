#include <iostream>

int main()
{
  int val;

  std::cin >> val;

  if(val >=90 && val <= 100)
      std::cout << "A";
  else if (val >= 80 && val <= 89)
      std::cout << "B";
  else if (val >= 70 && val <= 79)
      std::cout << "C";
  else if (val >= 60 && val <= 69)
      std::cout << "D";
  else
      std::cout << "F";

  return 0;
}
