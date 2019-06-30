#include "_NewtonCotes.hpp"
#include "Function.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

#define _USE_MATH_DEFINES

/*********************\
  
  FILOSOFIAS ABERTAS

\*********************/


/*********************\
  
  FILOSOFIAS FECHADAS

\*********************/

double NewtonCotes::trapezoidRule(Function function, double a, double b, int N) {
  double h = (b - a)/N;
  double solution = function.f(a) + function.f(b);

  for (int i = 1; i < N; i++){
    solution += 2*function.f(a + i*h);
  }

  return (h*solution)/2;
}

double NewtonCotes::simpsons13Rule(Function function, double a, double b, int N) {
  double h = (b - a)/N;
  double solution = function.f(a) + function.f(b);

  for(int i = 1; i < N; i++){
    if(i%2 == 1){
      solution += 4 * function.f(a + i*h);
    } else {
      solution += 2 * function.f(a + i*h);
    }
  }

  return (h*solution)/3;
}

double NewtonCotes::simpsons38Rule(Function function, double a, double b, int N) {
  double h = (b - a)/N;
  double solution = function.f(a) + function.f(b);

  for (int i = 1; i < N; i++){
    if(i%3 == 0){
      solution += 2 * function.f(a + i*h);
    } else {
      solution += 3 * function.f(a + i*h);
    }
  }

  return (3*h*solution)/8;
}

double NewtonCotes::boolesRule(Function function, double a, double b, int N) {
  double h = (b - a)/N;
  double solution = 7*(function.f(a) + function.f(b));

  for (int i = 1; i < N; i++) {
    if (i%4 == 0) {
      solution += 14 * function.f(a + i*h);
    } else if (i%2 == 0) {
      solution += 12 * function.f(a + i*h);
    } else {
      solution += 32 * function.f(a + i*h);
    }    
  }

  return 2*h*solution/45;
}

/************************************\
  
  FILOSOFIAS FECHADAS COM TOLERANCIA

\************************************/

// Grau 1
double NewtonCotes::trapezoidRuleTolerance(Function function, double a, double b, double e){
  int N = abs(log(e)/log(10));
  double solution, step1, step2, delta;

  // Caso o chute inicial do algoritmo para o número de segmentos acerte
  // O valor vai ser retornado dentro do if
  if (N <= 1) {
    step1 = trapezoidRule(function, a, b, 10);
    step2 = trapezoidRule(function, a, b, 100);

    if (abs(step1 - step2) <= e){
      return step2;
    }
  } else {
    step1 = trapezoidRule(function, a, b, pow(10, N-1));
    step2 = trapezoidRule(function, a, b, pow(10, N));

    if (abs(step1 - step2) <= e){
      return step2;
    }
  }

  // Calculando valor do erro antes de entrar no loop
  delta = abs(step1 - step2);

  // Caso o chute inicial não encontre o valor do número de segmentos
  // O número de segmentos vai aumentando na ordem de 10^N+1
  while (delta > e) {
    N++;

    step1 = trapezoidRule(function, a, b, pow(10, N-1));
    step2 = trapezoidRule(function, a, b, pow(10, N));

    delta = abs(step1 - step2);
  }

  return step2;
}

// Grau 2
double NewtonCotes::simpsons13RuleTolerance(Function function, double a, double b, double e){
  int N = abs(log(e)/log(10));
  double solution, step1, step2, delta;

  // Caso o chute inicial do algoritmo para o número de segmentos acerte
  // O valor vai ser retornado dentro do if
  if (N <= 1) {
    step1 = simpsons13Rule(function, a, b, 10);
    step2 = simpsons13Rule(function, a, b, 100);

    if (abs(step1 - step2) <= e){
      return step2;
    }
  } else {
    step1 = simpsons13Rule(function, a, b, pow(10, N-1));
    step2 = simpsons13Rule(function, a, b, pow(10, N));

    if (abs(step1 - step2) <= e){
      return step2;
    }
  }

  // Calculando valor do erro antes de entrar no loop
  delta = abs(step1 - step2);

  // Caso o chute inicial não encontre o valor do número de segmentos
  // O número de segmentos vai aumentando na ordem de 10^N+1
  while (delta > e) {
    N++;

    step1 = simpsons13Rule(function, a, b, pow(10, N-1));
    step2 = simpsons13Rule(function, a, b, pow(10, N));

    delta = abs(step1 - step2);
  }

  return step2;
}

// Grau 3
double NewtonCotes::simpsons38RuleTolerance(Function function, double a, double b, double e){
  int N = abs(log(e)/log(10));
  double solution, step1, step2, delta;

  // Caso o chute inicial do algoritmo para o número de segmentos acerte
  // O valor vai ser retornado dentro do if
  if (N <= 1) {
    step1 = simpsons38Rule(function, a, b, 10);
    step2 = simpsons38Rule(function, a, b, 100);

    if (abs(step1 - step2) <= e){
      return step2;
    }
  } else {
    step1 = simpsons38Rule(function, a, b, pow(10, N-1));
    step2 = simpsons38Rule(function, a, b, pow(10, N));

    if (abs(step1 - step2) <= e){
      return step2;
    }
  }

  // Calculando valor do erro antes de entrar no loop
  delta = abs(step1 - step2);

  // Caso o chute inicial não encontre o valor do número de segmentos
  // O número de segmentos vai aumentando na ordem de 10^N+1
  while (delta > e) {
    N++;

    step1 = simpsons38Rule(function, a, b, pow(10, N-1));
    step2 = simpsons38Rule(function, a, b, pow(10, N));

    delta = abs(step1 - step2);
  }

  return step2;
}

// Grau 4
double NewtonCotes::boolesRuleTolerance(Function function, double a, double b, double e){
  int N = abs(log(e)/log(10));
  double solution, step1, step2, delta;

  // Caso o chute inicial do algoritmo para o número de segmentos acerte
  // O valor vai ser retornado dentro do if
  if (N <= 1) {
    step1 = boolesRule(function, a, b, 10);
    step2 = boolesRule(function, a, b, 100);

    if (abs(step1 - step2) <= e){
      return step2;
    }
  } else {
    step1 = boolesRule(function, a, b, pow(10, N-1));
    step2 = boolesRule(function, a, b, pow(10, N));

    if (abs(step1 - step2) <= e){
      return step2;
    }
  }

  // Calculando valor do erro antes de entrar no loop
  delta = abs(step1 - step2);

  // Caso o chute inicial não encontre o valor do número de segmentos
  // O número de segmentos vai aumentando na ordem de 10^N+1
  while (delta > e) {
    N++;

    step1 = boolesRule(function, a, b, pow(10, N-1));
    step2 = boolesRule(function, a, b, pow(10, N));

    delta = abs(step1 - step2);
  }

  return step2;
}
