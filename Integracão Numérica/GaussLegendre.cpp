#include "GaussLegendre.hpp"
#include "Function.hpp"
#include <cstdlib>
#include <cmath>

#define _USE_MATH_DEFINES

// Basic Operations
// 2 Points
double GaussLegendre::gaussLegendre2Points(Function function, double a, double b)
{
  // Legendre Roots
  double legendreRoot1 = -0.577350269;
  double legendreRoot2 = 0.577350269;

  // Adjusts
  double a0 = (a + b)/2;
  double a1 = (b - a)/2;

  // Points
  double p1 = a0 + a1*legendreRoot1;
  double p2 = a0 + a1*legendreRoot2;

  // Result
  return (function.f(p1) + function.f(p2))*a1; // The weights equals to 1.
}

// 3 Points
double GaussLegendre::gaussLegendre3Points(Function function, double a, double b)
{
  // Legendre Roots
  double legendreRoot1 = -0.774596669;
  double legendreRoot2 = 0;
  double legendreRoot3 = 0.774596669;

  // Point weights
  double w1 = 0.5555556;
  double w2 = 0.8888889;
  double w3 = 0.5555556;

  // Adjusts
  double a0 = (a + b)/2;
  double a1 = (b - a)/2;

  // Points
  double p1 = a0 + a1*legendreRoot1;
  double p2 = a0 + a1*legendreRoot2;
  double p3 = a0 + a1*legendreRoot3;

  // Result
  return (w1*function.f(p1) + w2*function.f(p2) + w3*function.f(p3))*a1;
}

// 4 Points
double GaussLegendre::gaussLegendre4Points(Function function, double a, double b)
{
  // Legendre Roots
  double legendreRoot1 = -0.861136312;
  double legendreRoot2 = -0.339981044;
  double legendreRoot3 = 0.339981044;
  double legendreRoot4 = 0.861136312;

  // Point weights
  double w1 = 0.3478548;
  double w2 = 0.6521452;
  double w3 = 0.6521452;
  double w4 = 0.3478548;

  // Adjusts
  double a0 = (a + b)/2;
  double a1 = (b - a)/2;

  // Points
  double p1 = a0 + a1*legendreRoot1;
  double p2 = a0 + a1*legendreRoot2;
  double p3 = a0 + a1*legendreRoot3;
  double p4 = a0 + a1*legendreRoot4;

  // Result
  return (w1*function.f(p1) + w2*function.f(p2) + w3*function.f(p3) + w4*function.f(p4))*a1;
}

// 2 Points
double GaussLegendre::gaussLegendreTolerance2Points(Function function, double a, double b, double tolerance)
{
  double current, anterior, sum, delta, x0, x1;
  
  current = 0.1;
  anterior = 100;

  // Initial number of partitions
  int N = 1;
  
  while (fabs((current - anterior)/current) > tolerance) {
    N *= 2;
    sum = 0;
    delta = (b-a)/N;

    for (int i=0; i < N; i++) {
      x0 = a + i*delta;
      x1 = x0 + delta;

      sum += gaussLegendre2Points(function, x0, x1);
    }

    anterior = current;
    current = sum;
  }
  
  return current;
}

// 3 Points
double GaussLegendre::gaussLegendreTolerance3Points(Function function, double a, double b, double tolerance)
{
  double current, anterior, sum, delta, x0, x1;
  
  current = 0.1;
  anterior = 100;

  // Initial number of partitions
  int N = 1;
  
  while (fabs((current - anterior)/current) > tolerance) {
    N *= 2;
    sum = 0;
    delta = (b-a)/N;

    for (int i=0; i < N; i++) {
      x0 = a + i*delta;
      x1 = x0 + delta;

      sum += gaussLegendre3Points(function, x0, x1);
    }

    anterior = current;
    current = sum;
  }
  
  return current;
}

// 4 Points
double GaussLegendre::gaussLegendreTolerance4Points(Function function, double a, double b, double tolerance)
{
  double current, anterior, sum, delta, x0, x1;
  
  current = 0.1;
  anterior = 100;

  // Initial number of partitions
  int N = 1;
  
  while (fabs((current - anterior)/current) > tolerance) {
    N *= 2;
    sum = 0;
    delta = (b-a)/N;

    for (int i=0; i < N; i++) {
      x0 = a + i*delta;
      x1 = x0 + delta;

      sum += gaussLegendre4Points(function, x0, x1);
    }

    anterior = current;
    current = sum;
  }
  
  return current;
}

