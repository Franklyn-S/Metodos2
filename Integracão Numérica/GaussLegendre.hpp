#include "Function.hpp"

class GaussLegendre
{
public:
  // Methods
  double gaussLegendre2Points(Function function, double a, double b);
  double gaussLegendre3Points(Function function, double a, double b);
  double gaussLegendre4Points(Function function, double a, double b);

  // Integral Calculus with tolerance
  // double gaussLegendreTolerance2Points(Function, double, double, double);
  // double gaussLegendreTolerance3Points(Function, double, double, double);
  // double gaussLegendreTolerance4Points(Function, double, double, double);
};
