#include "check_bad_specials.h++"
#include "specials.h++"
#include <iostream>

int check_bad_specials(std::string password)
{
  int length = password.length();
  if (length == 0)
  {
    std::cout << "Use only digits, latin letters and special symbols: "
                 "~!@#$%^&*()+=-_[]{}<>.,:;/|\\\n";
    return false;
  }
  for (int i = 0; i < length; i++)
  {
    if (!(std::isdigit(password[i])) && !(std::isalpha(password[i])) &&
        !(specials.find(password[i]) != std::string::npos))
    {
      std::cout << "Use only digits, latin letters and special symbols: "
                   "~!@#$%^&*()+=-_[]{}<>.,:;/|\\\n";
      return false;
    }
  }
  return true;
}