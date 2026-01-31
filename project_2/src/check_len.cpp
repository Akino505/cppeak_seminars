#include "check_len.h++"
#include <iostream>

int check_len(std::string password)
{
  if (password.length() <= 8)
  {
    std::cout << "Your password is too short. Length must be more than 7.\n";
    return false;
  }
  return true;
}
