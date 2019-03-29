import math

def function(x):
    return pow(x,6)


def Integrate_4(Xi, Xf, function):
    h = (Xf-Xi)/6
    I = 0
    W = [33, -42, 78, -42, 33]
    for i in range(5):
        Xi = Xi + i*h
        I += W[i] + function(Xi)
    return (1/10)*h*I
#def integrate(Xin, Xfin, degree, function):
#    h = (Xfin - Xin)/2
#    I = 0
    #switcher = {
    #    1: 
    #}
#   return 


Xi = -1#float(input("Xi: "))
Xf = 5#float(input("Xf: "))
print("Filosofia 1 - Aberta \nFilosofia 2 - Fechada")
philosophy = 1 #input("Filosofia: ")
degree = 4 #input("Grau: ")
error = 0.1 #input("Erro: ")
print("Xi = {0}\nXf = {1}\nFilosofia = {2}\nGrau = {3}\nErro = {4}".format(Xi, Xf, philosophy, degree, error))
I = 0.0
N = Xf + 1
deltaX = (Xf-Xi)/N
for i in range(Xf+1):
    Xin = Xi + i*deltaX
    Xfin = Xin + deltaX
    if philosophy == 1:
        if degree == 4:
            I += Integrate_4(Xin, Xfin, function)

print("O resultado é {0}".format(I))
            

    



'''
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
'''