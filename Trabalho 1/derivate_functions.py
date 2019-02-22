def forward_derivation(function, value, delta):
    return ((function(value+delta) - function(value))/delta)

def backward_derivation(function, value, delta):
    return ((function(value) - function(value-delta))/delta)

def central_derivation(function, value, delta):
    return ((function(value+delta) - function(value-delta))/delta*2)