program: main.o

main.o: Function.o GaussChebyshev.o GaussHermite.o GaussLaguerre.o GaussLegendre.o NewtonCotes.o main.cpp
	g++ Function.o GaussChebyshev.o GaussHermite.o GaussLaguerre.o GaussLegendre.o NewtonCotes.o main.cpp -o main.o

methods: Function.cpp GaussChebyshev.cpp GaussHermite.cpp GaussLaguerre.cpp GaussLegendre.cpp NewtonCotes.cpp
	g++ -c Function.cpp GaussChebyshev.cpp GaussHermite.cpp GaussLaguerre.cpp GaussLegendre.cpp NewtonCotes.cpp

clear:
	rm *.o
