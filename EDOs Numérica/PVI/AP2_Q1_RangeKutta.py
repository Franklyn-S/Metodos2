from __future__ import print_function
from math import sqrt, ceil

def ft(t):
    if ( (t < 0) or (t > 1)):
        return 0;
    elif (t <= 0.5):
        return 4*t
    elif (t <= 1):
        return 4*(1-t)
    else:
        return 0

matricula_franklyn = '397847'
matricula_daniel = '374169'

matricula_hariamy = '397613'

A, B, C, D, E, F = map(int, list(matricula_franklyn))

m = 1 + (A + B + C + D + E + F) % 4
k = 4
w = sqrt(k/m)
z = 0.05

x = (E+F) % 3
t = 0
v = 0

tn = 1.2

h = 0.6 #delta T
e = 0.0001

n = ceil((tn - t) / h) # calcula o número de interações


def Function(t, v, x):
    return (ft(t)/m - 2*z*w*v - pow(w,2)*x)

erroRelativo = 1
aux = 0
while True:
    x_old = x
    #valores iniciais
    x = (E+F) % 3
    y = 0
    t = 0
    for i in range(n):

        k1v = h * Function(t,v,x)
        k1x = h * v
        print("k1v: {}".format(k1v))
        print("k1x: {}".format(k1x))

        k2v = h * Function( (t + h/2), (v+ k1v/2), (x + k1x/2) )
        k2x = h * (v+ k1v/2)

        k3v = h * Function( (t + h/2), (v+ k2v/2), (x + k2x/2) )
        k3x = h * (v+ k2v/2)

        k4v = h * Function(t+h, v+k3v, x+k3x)
        k4x = h * v+k3v

        v = v + (k1v + 2*k2v + 2*k3v + k4v)/6
        x = x + (k1x + 2*k2x + 2*k3x + k4x)/6
        
        print("{} v(1.2): {}".format(i, v))
        print("{} x(1.2): {}".format(i, x))   

    t += h
    erroRelativo = abs(x - x_old)/abs(x)
    if (erroRelativo < e):
        aux += 1
        print("1")
    else:
        aux = 0
    if (aux == 2):
        break
    h = h/2
    n = ceil((tn - t) / h)


print("v(1.2): {}".format(v))
print("x(1.2): {}".format(x))
