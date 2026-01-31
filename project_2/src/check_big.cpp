#include "check_big.h++"
#include <iostream>

int check_big(std::string password)
{
  int length = password.length();
  for (int i = 0; i < length; i++)
  {
    if (std::isupper(password[i]))
    {
      return true;
    }
  }
  std::cout << "Your password should contain at least one capital letter.\n";
  return false;
}
