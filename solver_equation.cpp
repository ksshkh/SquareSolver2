#include <TXLib.h>
#include <math.h>
#include "solver_equation.hpp"
#include "colors.hpp"

bool compare(double x, double y) {
  return fabs(x - y) < EPS;
}

void buffer_flush(void) {
  scanf("%*s");
}

double input_coef(char letter) {
  double koef = 0;
  printf("%c = ", letter);
  while (scanf("%lf", &koef) != 1) {
    buffer_flush();
    printf(COLOR_ERROR "Please, enter a number.\n" COLOR_NORMAL);
    printf("%c = ", letter);
  }
  return koef;
}

void output_results(result rl_root) {
  switch (rl_root.nroots) {
    case NO_ROOTS:
      printf(COLOR_ANSWER "No roots.\n" COLOR_NORMAL);
      break;
    case SINGLE_ROOT:
      printf(COLOR_ANSWER "x = %.5lf\n" COLOR_NORMAL, rl_root.x1);
      break;
    case TWO_ROOTS:
      printf(COLOR_ANSWER "x1 = %.5lf\nx2 = %.5lf\n" COLOR_NORMAL, rl_root.x1, rl_root.x2);
      break;
    case INFINITY_ROOTS:
      printf(COLOR_ANSWER "x - any number.\n" COLOR_NORMAL);
      break;
    default:
      printf(COLOR_ERROR "ERROR\n" COLOR_NORMAL);
      break;
  }
}

void solver_of_sq_equation(coefficients_of_sq_equation coef, result * rl_root) {

  assert(std::isfinite(coef.a));
  assert(std::isfinite(coef.b));
  assert(std::isfinite(coef.c));

  assert(rl_root != nullptr);

  double D = 0;
  double sqare_root_d = 0;

  if (compare(coef.a, 0)) {
    line_equation(coef, rl_root);
  }
  else {
    D = coef.b * coef.b - 4 * coef.a * coef.c;
    if (compare(D, 0)) {
      rl_root->x1 = (-coef.b) / (2 * coef.a);
      rl_root->nroots = SINGLE_ROOT;
    }
    else if (D > 0) {
      sqare_root_d = sqrt(D);
      rl_root->x1 = (-coef.b + sqare_root_d) / (2 * coef.a);
      rl_root->x2 = (-coef.b - sqare_root_d) / (2 * coef.a);
      rl_root->nroots = TWO_ROOTS;
    }
    else {
      rl_root->nroots = NO_ROOTS;
    }
  }

}

void line_equation(coefficients_of_sq_equation coef, result * rl_root) {
  if (!compare(coef.b, 0)) {
      rl_root->x1 = (-coef.c) / coef.b;
      rl_root->nroots = SINGLE_ROOT;
  }
  else {
    if (compare(coef.c, 0)) {
      rl_root->nroots = INFINITY_ROOTS;
    }
    else {
      rl_root->nroots = NO_ROOTS;
    }
  }
}
