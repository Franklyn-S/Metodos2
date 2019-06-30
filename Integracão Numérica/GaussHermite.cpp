#include "GaussHermite.hpp"
#include "Function.hpp"
#include <cstdlib>
#include <cmath>

#define _USE_MATH_DEFINES

// 2 Points
double GaussHermite::gaussHermite2Points(Function function)
{
  // Hermite's Points
  double p1 = -0.70710678;
  double p2 = 0.70710678;

  // Hermite's Weights
  double w1 = 0.88622692;
  double w2 = 0.88622692;

  // Result
  return (w1*function.hermiteType(p1) + w2*function.hermiteType(p2));
}

// 3 Points
double GaussHermite::gaussHermite3Points(Function function)
{
  // Hermite's Points
  double p1 = -1.22474487;
  double p2 = 0.00000000;
  double p3 = 1.22474487;

  // Hermite's Weights
  double w1 = 0.29540897;
  double w2 = 1.18163590;
  double w3 = 0.29540897;

  // Result
  return (w1*function.hermiteType(p1) + w2*function.hermiteType(p2) + w3*function.hermiteType(p3));
}

// 4 Points
double GaussHermite::gaussHermite4Points(Function function)
{
  // Hermite's Points
  double p1 = -1.65068012;
  double p2 = -0.52464762;
  double p3 = 0.52464762;
  double p4 = 1.65068012;

  // Hermite's Weights
  double w1 = 0.08131283;
  double w2 = 0.80491409;
  double w3 = 0.80491409;
  double w4 = 0.08131283;

  // Result
  return (w1*function.hermiteType(p1) + w2*function.hermiteType(p2) + w3*function.hermiteType(p3) + w4*function.hermiteType(p4));
}
