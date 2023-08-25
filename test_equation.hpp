#ifndef TEST_EQUATION
#define TEST_EQUATION

#include "solver_equation.hpp"

//----------------------------------------------------------------------------------------------
/// @brief Run all tests
//----------------------------------------------------------------------------------------------
void run_all_tests(void);

//----------------------------------------------------------------------------------------------
/// @brief Checks whether the received results match the expected ones
///
/// @param [in]  coef   Coefficients of the equation (a, b, c)
/// @param [in]  exp_root   Expected roots and their number (x1_exp, x2_exp, num_exp)
/// @param [out] rec_root  Recieved roots of the equation (x1, x2)
///
/// @return True if the numbers are equal and false in other case
//----------------------------------------------------------------------------------------------
bool test_solver_of_sq_equation(coefficients_of_sq_equation coef, result * rec_roots, result exp_root);

#endif
