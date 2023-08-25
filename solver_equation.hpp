#ifndef SOLVER_EQUATION
#define SOLVER_EQUATION

/// @brief EPS is a constant for comparinf double numbers
const double EPS = 1e-9;

/// @brief Number of roots
enum solutions {
  NO_ROOTS, ///< No roots
  SINGLE_ROOT, ///< Single root
  TWO_ROOTS, ///< Two roots
  INFINITY_ROOTS ///< Infinitie number of roots
};

/// @brief Structure for coefficient names
struct coefficients_of_sq_equation {
  double a;
  double b;
  double c;
};

/// @brief Structure for the roots of equation
struct result {
  double x1;///< The first root
  double x2;///< The second root
  int nroots;///< Number of roots
};

//----------------------------------------------------------------------------------------------
/// @brief Compares two double numbers
///
/// @param [in]  x   The first number
/// @param [in]  y   The second number
///
/// @return True if the numbers are equal and false in other case
//----------------------------------------------------------------------------------------------
bool compare(double x, double y);

//----------------------------------------------------------------------------------------------
/// @brief Clear the boofer
//----------------------------------------------------------------------------------------------
void buffer_flush(void);
// ok boomer buffer

//----------------------------------------------------------------------------------------------
/// @brief Solves a square equation ax^2 + bx + c = 0
///
/// @param [in]  coef   Coefficients of the equation (a, b, c)
/// @param [out] rl_root  Roots of the equation (x1, x2) and number of rootd (nroots)
//----------------------------------------------------------------------------------------------
void solver_of_sq_equation(coefficients_of_sq_equation coef, result * rl_root);

//----------------------------------------------------------------------------------------------
/// @brief Solves a line equation bx + c = 0
///
/// @param [out] rl_root  Roots of the equation (x1, x2) and number of rootd (nroots)
///
/// @attention If a = 0, the line_equation function is called
//----------------------------------------------------------------------------------------------
void line_equation(coefficients_of_sq_equation coef, result * rl_root);

//----------------------------------------------------------------------------------------------
/// @brief Enter the coefficients of the equation. If enter is wrong, jffers to re-enter
///
/// @param [in]  letter   The coefficient (a, b or c)
//----------------------------------------------------------------------------------------------
double input_coef(char letter);

//----------------------------------------------------------------------------------------------
/// @brief Output results of program
///
/// @param [in]  num_of_roots   Number of roots
/// @param [in]  rl_root   The value of roots (x1, x2)
//----------------------------------------------------------------------------------------------
void output_results(result rl_root);

#endif
