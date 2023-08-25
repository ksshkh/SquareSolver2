#include <TXLib.h>
#include "test_equation.hpp"
#include "solver_equation.hpp"
#include "colors.hpp"

#define RUN_TEST(a, b, c, x1_exp, x2_exp, num_exp) \
{ \
  ++counter; \
  if (test_solver_of_sq_equation(coefficients_of_sq_equation{a, b, c}, &rec_roots, result{x1_exp, x2_exp, num_exp}) == true) { \
    ++counter_true; \
  } \
  else { \
    printf(COLOR_ERROR "Failed the test %d.\n", counter); \
    printf(COLOR_ERROR "Received results:" COLOR_NORMAL " x1 = %lf, x2 = %lf, number of roots = %d\n", rec_roots.x1, rec_roots.x2, rec_roots.nroots); \
  } \
}

bool test_solver_of_sq_equation(coefficients_of_sq_equation coef, result * rec_roots, result exp_root) {
  result rl_root = {0, 0, 0};
  solver_of_sq_equation(coef, &rl_root);
  if (compare(exp_root.x1, rl_root.x1) && compare(exp_root.x2, rl_root.x2) && rl_root.nroots == exp_root.nroots) {
    return true;
  }
  else {
    rec_roots->x1 = (rl_root.x1);
    rec_roots->x2 = (rl_root.x2);
    rec_roots->nroots = (rl_root.nroots);
    return false;
  }
}

void run_all_tests(void) {

  int counter = 0, counter_true = 0;
  result rec_roots = {0, 0, 0};
  RUN_TEST(0, 0, 0, 0, 0, INFINITY_ROOTS); //1
  RUN_TEST(0, 0, 100, 0, 0, NO_ROOTS); //2
  RUN_TEST(0, 0, 5.6, 0, 0, NO_ROOTS); //3
  RUN_TEST(78, 2, 56, 0, 0, NO_ROOTS); //4
  RUN_TEST(-37, 16, -64, 0, 0, NO_ROOTS); //5
  RUN_TEST(0, 37, -74, 2, 0, SINGLE_ROOT); //6
  RUN_TEST(1, 2, 1, -1, 0, SINGLE_ROOT); //7
  RUN_TEST(1, 5, 6, -2, -3, TWO_ROOTS); //8
  RUN_TEST(56, -56, 0, 1, 0, TWO_ROOTS); //9
  RUN_TEST(55, 0, 46, 0, 0, NO_ROOTS); //10
  RUN_TEST(64, 0, -169, 1.625, -1.625, TWO_ROOTS); //11
  RUN_TEST(1, 1, 1, 1, 1, SINGLE_ROOT); //12 special wrong

  printf(COLOR_OK "%d\\%d tests passed!\n" COLOR_NORMAL, counter_true, counter);
}

#undef RUN_TEST

