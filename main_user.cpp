#include <TXLib.h>
#include <math.h>
#include "solver_equation.hpp"
#include "test_equation.hpp"
#include "colors.hpp"

int main() {

  coefficients_of_sq_equation coef = {0, 0, 0};
  result rl_root = {0, 0, 0};

  printf(COLOR_PROGRAM "Enter the coefficients a, b, c, to solve a quadratic equation of the form\nax^2 + bx + c = 0\n" COLOR_NORMAL);
  printf(COLOR_PROGRAM "(The program accepts only numbers)\n" COLOR_NORMAL);
  coef.a = input_coef('a');
  coef.b = input_coef('b');
  coef.c = input_coef('c');

  solver_of_sq_equation(coef, &rl_root);
  output_results(rl_root);
  
  return 0;
}
