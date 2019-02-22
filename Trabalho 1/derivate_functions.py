def forward_derivation(function, value, delta):
    return ((function(value+delta) - function(value))/delta)

def backward_derivation(function, value, delta):
    return ((function(value) - function(value-delta))/delta)

def central_derivation(function, value, delta):
    return ((function(value+delta) - function(value-delta))/delta*2)

def forward_derivation_image(image, position, direction):
    # Pega o valor de f(x)
    
    f_x = image.getpixel(position)

    # Pega o valor de f(x + 1)
    if(direction == 'x'):
        # Caso esteja percorrendo em x
        delta_position = (position[0], position[1]+1)
        
        f_x_delta = image.getpixel(delta_position)
    elif(direction == 'y'):
        # Caso esteja percorrendo em y
        delta_position = (position[0]+1, position[1])
        f_x_delta = image.getpixel(delta_position)
    
    return abs(f_x_delta - f_x)

def backward_derivation_image(image, position, direction):
    # Pega o valor de f(x)
    
    f_x = image.getpixel(position)

    # Pega o valor de f(x - 1)
    if(direction == 'x'):
        # Caso esteja percorrendo em x
        delta_position = (position[0], position[1]-1)

        f_x_delta = image.getpixel(delta_position)
    elif(direction == 'y'):
        # Caso esteja percorrendo em y
        delta_position = (position[0]-1, position[1])
        
        f_x_delta = image.getpixel(delta_position)
    
    return abs(f_x - f_x_delta)

def central_derivation_image(image, position, direction):
    if(direction == 'x'):
        # Caso esteja percorrendo em x
        delta_position = (position[0], position[1] +1)
        f_x_delta_forward = image.getpixel(delta_position)
        
        delta_position = (position[0], position[1]-1)
        f_x_delta_backward = image.getpixel(delta_position)
    elif(direction == 'y'):
        # Caso esteja percorrendo em y
        delta_position = (position[0]+1, position[1])
        f_x_delta_forward = image.getpixel(delta_position)
        
        delta_position = (position[0]-1, position[1])
        f_x_delta_backward = image.getpixel(delta_position)
    
    return int(abs((f_x_delta_forward - f_x_delta_backward)/2))