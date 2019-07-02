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

tn = 1.2

v0 = 0
x0 = (E + F) % 3

h = 0.6 # Delta T


e = 0.0001


class S:
    def __init__(self, v, x):
        self.v = v
        self.x = x
        
    def __add__(self, other):
        return S(self.v+other.v, self.x+other.x)
    def __sub__(self, other):
        return S(self.v-other.v, self.x-other.x)
    def __mul__(self, other):
        if type(other) is not int and type(other) is not float:
            raise Exception('MultiplicationError')
        return S(self.v*other, self.x*other)
    def __truediv__(self, other):
        if type(other) is not int and type(other) is not float:
            raise Exception('DivisionError')
        return S(self.v/other, self.x/other)
    
    def __radd__(self, value):
        return S(self.v+value, self.x+value)
    def __rsub__(self, value):
        return S(self.v-value, self.x-value)
    def __rmul__(self, value):
        if type(value) is not int and type(value) is not float:
            raise Exception('MultiplicationError')
        return S(self.v*value, self.x*value)
    def __rtruediv__(self, value):
        if type(value) is not int and type(value) is not float:
            raise Exception('DivisionError')
        return S(self.v/value, self.x/value)
    
    def __str__(self):
        return "(v={}, x={})".format(self.v, self.x)




def Function(Si, t):
    return S( (ft(t)/m - 2*z*w*Si.v - pow(w,2)*Si.x), Si.v)


# Programa principal
stopCondition = 0
erroRelativo = 1
s = S(v0, x0)
while stopCondition < 2:
    #valores iniciais
    ############# Range Kutta ############
    x_old = s.x
    s = S(v0, x0)
    t0 = 0
    tf = 1.2
    while t0 < tf:

        k1 = Function(s, t0)

        k2 = Function( (s + k1 * (h/2)) , (t0 + h/2) )
   
        k3 = Function( (s + k2 * (h/2)) , (t0 + h/2) )

        k4 = Function(s + k3 * h, t0 + h)

        s = s + h* (k1 + 2*k2 + 2*k3 + k4)/6
        t0 += h
    print(s)
    ################# FIM #################

    # Verifica o erro
    erroRelativo = abs(s.x - x_old)/abs(s.x)
    print("Erro relativo: {}".format(erroRelativo))

    if (erroRelativo < e):
        stopCondition += 1
    else:
        stopCondition = 0
    h = h/2



print("v(1.2): {}".format(s.v))
print("x(1.2): {}".format(s.x))
