#include "Function.hpp"

class GaussLegendre
{
public:
  // Methods
  double gaussLegendre2Points(Function, double, double);
  double gaussLegendre3Points(Function, double, double);
  double gaussLegendre4Points(Function, double, double);

  // Integral Calculus with tolerance
  // double gaussLegendreTolerance2Points(Function, double, double, double);
  // double gaussLegendreTolerance3Points(Function, double, double, double);
  // double gaussLegendreTolerance4Points(Function, double, double, double);
};
