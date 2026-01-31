#include "check.h++"
#include "check_len.h++"
#include "check_big.h++"
#include "check_small.h++"
#include "check_digit.h++"
#include "check_specials.h++"
#include "check_bad_specials.h++"
#include "specials.h++"
#include <iostream>

int check(std::string password)
{
  if ((check_bad_specials(password) + check_len(password) +
       check_digit(password) + check_big(password) + check_small(password) +
       check_specials(password)) == 6)
  {
    std::cout << "Your password is OK :)\n";
  }

  return 0;
}