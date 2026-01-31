#include "check_digit.h++"
#include <iostream>

int check_digit(std::string password)
{
  int length = password.length();
  for (int i = 0; i < length; i++)
  {
    if (std::isdigit(password[i]))
    {
      return true;
    }
  }
  std::cout << "Your password should contain at least one digit.\n";
  return false;
}