import math

def function(x):
    return math.cos(x)

#def integrate(Xin, Xfin, degree, function):
#    h = (Xfin - Xin)/2
#    I = 0
    #switcher = {
    #    1: 
    #}
#   return 


Xi = float(input("Xi: "))
print(Xi)
Xf = float(input("Xf: "))
print("Filosofia 1 - Aberta \nFilosofia 2 - Fechada")
philosophy = input("Filosofia: ")
degree = input("Grau: ")
error = input("Erro: ")
print("Xi = {0}\nXf = {1}\nFilosofia = {2}\nGrau = {3}\n Erro = {4}".format(Xi, Xf, philosophy, degree, error))
N = 1
while N<20:
    N *= 2
    deltaX = (Xf-Xi)/N
    I = 0.0
    for i in range(N):
        Xin = Xi + i*deltaX
        Xfin = Xin + deltaX
        if philosophy == 1: 
            #I += Integrate(Xin, Xfin, degree)
        elif philosophy == 2: 
            #I += Integrate   