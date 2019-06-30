#Arquivo makefile para os métodos da potência

all: principal

principal: todos
	g++ ProgramaPrincipal.o PotenciaRegular.o PotenciaInversa.o PotenciaDeslocamento.o LU.o -o principal

todos: PotenciaRegular.cpp PotenciaInversa.cpp PotenciaDeslocamento.cpp ProgramaPrincipal.cpp LU.cpp
	g++ -c PotenciaRegular.cpp PotenciaInversa.cpp PotenciaDeslocamento.cpp ProgramaPrincipal.cpp LU.cpp


questao1: principal2

principal2: todos2
	g++  PotenciaRegular.o PotenciaInversa.o LU.o 1Q.o -o questao1

todos2:  PotenciaRegular.cpp PotenciaInversa.cpp LU.cpp 1Q.cpp
	g++ -c PotenciaRegular.cpp PotenciaInversa.cpp LU.cpp 1Q.cpp
	
clean:
	rm -rf *.o *~ principal