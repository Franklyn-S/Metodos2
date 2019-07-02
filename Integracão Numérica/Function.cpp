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
  return sqrt(4 - pow(x,2));
}

double Function::hermiteType(double x)
{
  // (e^(-x²))*f(x)
  return pow(exp(1.0), x);
}

double Function::laguerreType(double x)
{
  // (e^(-x))*f(x)
  return sin(x);
}

double Function::chebyshevType(double x)
{
  // (1/sqrt(1.0 - pow(x, 2.0)))
  // f(x)/((1-x²)^1/2), with f(x) = x²
  return cos(x);
}
