#include "GaussLaguerre.hpp"
#include "Function.hpp"
#include <cstdlib>
#include <cmath>

#define _USE_MATH_DEFINES

// 2 Points
double GaussLaguerre::gaussLaguerre2Points(Function function)
{
  // Laguerre's Points
  double p1 = 0.58578643;
  double p2 = 3.41421356;

  // Laguerre's Weights
  double w1 = 0.85355339;
  double w2 = 0.14644660;

  // Result
  return (w1*function.laguerreType(p1) + w2*function.laguerreType(p2));
}

// 3 Points
double GaussLaguerre::gaussLaguerre3Points(Function function)
{
  // Laguerre's Points
  double p1 = 0.41577455;
  double p2 = 2.24428036;
  double p3 = 6.28994508;

  // Laguerre's Weights
  double w1 = 0.71109300;
  double w2 = 0.27851973;
  double w3 = 0.01038926;

  // Result
  return (w1*function.laguerreType(p1) + w2*function.laguerreType(p2) + w3*function.laguerreType(p3));
}

// 4 Points
double GaussLaguerre::gaussLaguerre4Points(Function function)
{
  // Laguerre's Points
  double p1 = 0.32254768;
  double p2 = 1.74576110;
  double p3 = 4.53662029;
  double p4 = 9.39507091;

  // Laguerre's Weights
  double w1 = 0.60315410;
  double w2 = 0.35741869;
  double w3 = 0.03888791;
  double w4 = 0.00053929;

  // Result
  return (w1*function.laguerreType(p1) + w2*function.laguerreType(p2) + w3*function.laguerreType(p3) + w4*function.laguerreType(p4));
}
