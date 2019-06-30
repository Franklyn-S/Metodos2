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
  
  // std::cout << newtonCotes.openedToleranceNewtonCotesDegree1(function, 0, 0.8, 0.00001) << std::endl;
  
  // std::cout << gaussLegendre.gaussLegendre2Points(function, 0, 0.8) << std::endl;
  // std::cout << gaussLegendre.gaussLegendre3Points(function, 0, 0.8) << std::endl;
  // std::cout << gaussLegendre.gaussLegendre4Points(function, 0, 0.8) << std::endl;

  // std::cout << gaussLaguerre.gaussLaguerre2Points(function) << std::endl;
  // std::cout << gaussLaguerre.gaussLaguerre3Points(function) << std::endl;
  // std::cout << gaussLaguerre.gaussLaguerre4Points(function) << std::endl;

  std::cout << gaussChebyshev.gaussChebyshevNPoints(function, 2) << std::endl;

  return 0;
}
