#include <iostream>
#include <string>
#include "check_small.h++"

int check_small(std::string password)
{
  int length = password.length();
  for (int i = 0; i < length; i++)
  {
    if (std::islower(password[i]))
    {
      return true;
    }
  }
  std::cout << "Your password should contain at least one small letter.\n";
  return false;
}
