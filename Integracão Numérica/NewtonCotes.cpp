#include "NewtonCotes.hpp"
#include "Function.hpp"
#include <cstdlib>
#include <cmath>

#define _USE_MATH_DEFINES

// Basic Polynoms:
// Opened Philosophies
// Degree 1
double NewtonCotes::basicOpenedNewtonCotesDegree1(Function function, double a, double b, double h)
{
  return h*(function.f(a + (b-a)/3) + function.f(a + (b-a)*2/3))/2;
}

// Degree 2
double NewtonCotes::basicOpenedNewtonCotesDegree2(Function function, double a, double b, double h)
{
  return h*(2*function.f(a + (b-a)/4) + -1*function.f(a + (b-a)/2) + 2*function.f(a + (b-a)*3/4))/3;
}

// Degree 3
double NewtonCotes::basicOpenedNewtonCotesDegree3(Function function, double a, double b, double h)
{
  return h*(11*function.f(a + (b-a)/5) + function.f(a + (b-a)*2/5) + function.f(a + (b-a)*3/5) + 11*function.f(a + (b-a)*4/5))/24;
}

// Degree 4
double NewtonCotes::basicOpenedNewtonCotesDegree4(Function function, double a, double b, double h)
{
  return h*(11*function.f(a + (b-a)/6) + -14*function.f(a + (b-a)/3) + 26*function.f(a + (b-a)/2) + -14*function.f(a + (b-a)*2/3) + 11*function.f(a + (b-a)*5/6))/20;
}

// Closed Philosophies
// Degree 1
double NewtonCotes::basicClosedNewtonCotesDegree1(Function function, double a, double b)
{
  // Trapezoid Rule
  return (b-a)*(function.f(a) + function.f(b))/2;
}

// Degree 2
double NewtonCotes::basicClosedNewtonCotesDegree2(Function function, double a, double b)
{
  // Simpson's 1/3 Rule
  return (b-a)*(function.f(a) + 4*function.f((a+b)/2) + function.f(b))/6;
}

// Degree 3
double NewtonCotes::basicClosedNewtonCotesDegree3(Function function, double a, double b)
{
  // Simpson's 3/8 Rule
  return (b-a)*(function.f(a) + 3*function.f(a + (b-a)/3) + 3*function.f(a + (b-a)*2/3) + function.f(b))*3/24;
}

// Degree 4
double NewtonCotes::basicClosedNewtonCotesDegree4(Function function, double a, double b)
{
  // Boole's Rule
  return (b-a)*(7*function.f(a) + 32*function.f(a + (b-a)/4) + 12*function.f(a + (b-a)/2) + 32*function.f(a + (b-a)*3/4) + 7*function.f(b))/90;
}

// Polynoms with Tolerance:
// Opened Philosophies
// Degree 1
double NewtonCotes::openedToleranceNewtonCotesDegree1(Function function, double a, double b, double tolerance)
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

      sum += basicOpenedNewtonCotesDegree1(function, x0, x1, delta);
    }

    anterior = current;
    current = sum;
  }
  
  return current;
}

// Degree 2
double NewtonCotes::openedToleranceNewtonCotesDegree2(Function function, double a, double b, double tolerance)
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

      sum += basicOpenedNewtonCotesDegree2(function, x0, x1, delta);
    }

    anterior = current;
    current = sum;
  }
  
  return current;
}

// Degree 3
double NewtonCotes::openedToleranceNewtonCotesDegree3(Function function, double a, double b, double tolerance)
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

      sum += basicOpenedNewtonCotesDegree3(function, x0, x1, delta);
    }

    anterior = current;
    current = sum;
  }
  
  return current;
}

// Degree 4
double NewtonCotes::openedToleranceNewtonCotesDegree4(Function function, double a, double b, double tolerance)
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

      sum += basicOpenedNewtonCotesDegree4(function, x0, x1, delta);
    }

    anterior = current;
    current = sum;
  }
  
  return current;
}

// Closed Philosophies
// Degree 1
double NewtonCotes::closedToleranceNewtonCotesDegree1(Function function, double a, double b, double tolerance)
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

      sum += basicClosedNewtonCotesDegree1(function, x0, x1);
    }

    anterior = current;
    current = sum;
  }
  
  return current;
}

// Degree 2
double NewtonCotes::closedToleranceNewtonCotesDegree2(Function function, double a, double b, double tolerance)
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

      sum += basicClosedNewtonCotesDegree2(function, x0, x1);
    }

    anterior = current;
    current = sum;
  }
  
  return current;
}

// Degree 3
double NewtonCotes::closedToleranceNewtonCotesDegree3(Function function, double a, double b, double tolerance)
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

      sum += basicClosedNewtonCotesDegree3(function, x0, x1);
    }

    anterior = current;
    current = sum;
  }
  
  return current;
}

// Degree 4
double NewtonCotes::closedToleranceNewtonCotesDegree4(Function function, double a, double b, double tolerance)
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

      sum += basicClosedNewtonCotesDegree4(function, x0, x1);
    }

    anterior = current;
    current = sum;
  }
  
  return current;
}
