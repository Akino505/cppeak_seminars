#include <iostream>
#include <string>
#include "check_len.h++"
#include "check_big.h++"
#include "check_small.h++"
#include "check_digit.h++"
#include "check_specials.h++"
#include "check_bad_specials.h++"
#include "specials.h++"
#include "check.h++"

int main()
{
  std::cout << "Enter your password:\n";
  std::string password;
  std::getline(std::cin, password);
  check(password);
  return 0;
}
