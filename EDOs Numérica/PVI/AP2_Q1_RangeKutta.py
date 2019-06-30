from __future__ import print_function
from math import sqrt, ceil

def ft(t):
    if (t <= 0.5):
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

x_old = 0

n = ceil((tn - t) / h) # calcula o número de interações


def F(t, v, x):
    return ft(t) - 2*z*w*v - pow(w,2)*x

erroRelativo = 1
aux = 0
while True:
    for i in range(n):
        x_old = x

        k1v = h * F(t,v,x)
        k1x = h * v

        k2v = h * F( (t + h/2), (v+ k1v*(h/2)), (x + k1x*(h/2)) )
        k2x = h * (v+ k1v*(h/2))

        k3v = h * F( (t + h/2), (v+ k2v*(h/2)), (x + k2x*(h/2)) )
        k3x = h * (v+ k2v*(h/2))

        k4v = h * F(t+h, v+k3v, x+k3x)
        k4x = h * v+k3v
        
        v = v + (k1v + 2*k2v + 2*k3v + k4v)/6
        x = x + (k1x + 2*k2x + 2*k3x + k4x)/6

    erroRelativo = abs(x - x_old)/abs(x_old)
    if (erroRelativo < e):
        aux += 1
    else:
        aux = 0
    if (aux == 2):
        break
    h = h/2


print("v(1.2): {}".format(v))
print("x(1.2): {}".format(x))
