#include <iostream>
#include "Function.hpp"
#include "NewtonCotes.hpp"
#include "GaussLegendre.hpp"
#include "GaussHermite.hpp"
#include "GaussLaguerre.hpp"
#include "GaussChebyshev.hpp"

int main(int argc, char const *argv[])
{
  Function function;
  NewtonCotes newtonCotes;
  GaussLegendre gaussLegendre;
  GaussLaguerre gaussLaguerre;
  GaussHermite gaussHermite;
  GaussChebyshev gaussChebyshev;
  
  // std::cout << newtonCotes.openedToleranceNewtonCotesDegree4(function, -2, 2, 0.0001) << std::endl;
  // std::cout << newtonCotes.closedToleranceNewtonCotesDegree4(function, -2, 2, 0.0001) << std::endl;
  
  // std::cout << gaussLegendre.gaussLegendreTolerance2Points(function, -2, 2, 0.0001) << std::endl;
  // std::cout << gaussLegendre.gaussLegendreTolerance3Points(function, -2, 2, 0.0001) << std::endl;
  // std::cout << gaussLegendre.gaussLegendreTolerance4Points(function, -2, 2, 0.0001) << std::endl;

  // std::cout << gaussHermite.gaussHermite2Points(function) << std::endl;
  // std::cout << gaussHermite.gaussHermite3Points(function) << std::endl;
  // std::cout << gaussHermite.gaussHermite4Points(function) << std::endl;

  // std::cout << gaussLaguerre.gaussLaguerre2Points(function) << std::endl;
  // std::cout << gaussLaguerre.gaussLaguerre3Points(function) << std::endl;
  // std::cout << gaussLaguerre.gaussLaguerre4Points(function) << std::endl;

  // std::cout << gaussChebyshev.gaussChebyshevNPoints(function, 30) << std::endl;

  return 0;
}
