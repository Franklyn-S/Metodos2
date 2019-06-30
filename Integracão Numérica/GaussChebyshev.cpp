#include "GaussChebyshev.hpp"
#include "Function.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

#define _USE_MATH_DEFINES

// N points
double GaussChebyshev::gaussChebyshevNPoints(Function function, int N){
  double result = 0;
  double x;

  // Sum Loop
  for (int i = 0; i < N; i++) {
    x = cos((((2*i) - 1)/(2*N))*M_PI);
    result += function.chebyshevType(x);
  }

  // Last operation
  result *= M_PI/N;

  return result;
}
