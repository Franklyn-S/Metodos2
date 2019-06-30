#include "Function.hpp"

class NewtonCotes
{
public:
  // Basic Polynoms:
  // Opened Philosophies
  double basicOpenedNewtonCotesDegree1(Function, double, double, double);
  double basicOpenedNewtonCotesDegree2(Function, double, double, double);
  double basicOpenedNewtonCotesDegree3(Function, double, double, double);
  double basicOpenedNewtonCotesDegree4(Function, double, double, double);
  // Closed Philosophies
  double basicClosedNewtonCotesDegree1(Function, double, double);
  double basicClosedNewtonCotesDegree2(Function, double, double);
  double basicClosedNewtonCotesDegree3(Function, double, double);
  double basicClosedNewtonCotesDegree4(Function, double, double);

  // Polynoms with Tolerance:
  // Opened Philosophies
  double openedToleranceNewtonCotesDegree1(Function, double, double, double);
  double openedToleranceNewtonCotesDegree2(Function, double, double, double);
  double openedToleranceNewtonCotesDegree3(Function, double, double, double);
  double openedToleranceNewtonCotesDegree4(Function, double, double, double);
  // Closed Philosophies
  double closedToleranceNewtonCotesDegree1(Function, double, double, double);
  double closedToleranceNewtonCotesDegree2(Function, double, double, double);
  double closedToleranceNewtonCotesDegree3(Function, double, double, double);
  double closedToleranceNewtonCotesDegree4(Function, double, double, double);
};
