#include "Function.hpp"
#include <cmath>

#define _USE_MATH_DEFINES

double Function::f(double x)
{
  // Resultado esperado: 11.7286
  // return M_PI * (x + pow(x,3)/6 + pow(x,5)/80);

  // Resultado esperado: 6 no intervalo -1, 1
  // return (30*pow(x, 4) + 25*pow(x, 3) - 3);

  // Resultado esperado: 1.640533 no intervalo 0, 0.8
  return 0.2 + 25 * x - 200 * pow(x, 2) + 675 * pow(x, 3) - 900 * pow(x, 4) + 400 * pow(x, 5);
}

double Function::hermiteType(double x)
{
  // (e^(-x²))*f(x)
  return pow(exp(1.0), pow(-x, 2));
}

double Function::laguerreType(double x)
{
  // (e^(-x))*f(x)
  return pow(exp(1.0), -x);
}

double Function::chebyshevType(double x)
{
  // f(x)/((1-x²)^1/2), with f(x) = x²
  return pow(x, 2)/sqrt(1 - pow(x, 2));
}
