#include "check_specials.h++"
#include "specials.h++"
#include <iostream>

int check_specials(std::string password)
{
  if (password.find_first_of(specials) != std::string::npos)
  {
    return true;
  }
  std::cout << "Your password should contain at least one special symbol.\n";
  return false;
}