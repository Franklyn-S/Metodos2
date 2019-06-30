#include "Function.hpp"

class NewtonCotes
{
public:
  // Filosofias Abertas

  // Filosofias Fechadas
  double trapezoidRule(Function, double, double, int);  // Grau 1
  double simpsons13Rule(Function, double, double, int); // Grau 2
  double simpsons38Rule(Function, double, double, int); // Grau 3
  double boolesRule(Function, double, double, int);     // Grau 4

  // Filosofias Fechadas Por Tolerância
  double trapezoidRuleTolerance(Function, double, double, double);  // Grau 1
  double simpsons13RuleTolerance(Function, double, double, double); // Grau 2
  double simpsons38RuleTolerance(Function, double, double, double); // Grau 3
  double boolesRuleTolerance(Function, double, double, double);     // Grau 4
};
