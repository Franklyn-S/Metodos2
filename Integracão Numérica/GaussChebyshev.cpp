#include "GaussChebyshev.hpp"
#include "Function.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

#define _USE_MATH_DEFINES

using namespace std;

// N points
double GaussChebyshev::gaussChebyshevNPoints(Function function, int N){
  double result = 0;
  double x;
  double weight = M_PI / N;
  double value;

  // Sum Loop
  for (int i = 1; i <= N; i++) {
    value = (2.0*i - 1.0)/(2.0*N);
    x = cos((value)*M_PI);

    result += function.chebyshevType(x)*weight;
  }

  return result;
}
