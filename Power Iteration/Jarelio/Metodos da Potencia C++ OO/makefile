#Arquivo makefile para os métodos da potência

all: principal

principal: programaprincipal.o potenciaregular.o potenciainversa.o potenciadeslocamento.o lu.o
	g++ ProgramaPrincipal.o PotenciaRegular.o PotenciaInversa.o PotenciaDeslocamento.o LU.o -o principal

potenciaregular.o: PotenciaRegular.cpp
	g++ -c PotenciaRegular.cpp

potenciainversa.o: PotenciaInversa.cpp LU.cpp
	g++ -c PotenciaInversa.cpp LU.cpp

potenciadeslocamento.o: PotenciaDeslocamento.cpp PotenciaInversa.cpp
	g++ -c PotenciaDeslocamento.cpp PotenciaInversa.cpp 

programaprincipal.o: ProgramaPrincipal.cpp
	g++ -c ProgramaPrincipal.cpp

lu.o: LU.cpp
	g++ -c LU.cpp
	
clean:
	rm -rf *.o *~ principal