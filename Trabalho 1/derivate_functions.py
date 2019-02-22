def forward_derivation(function, value, delta):
    return ((function(value+delta) - function(value))/delta)

def backward_derivation(function, value, delta):
    return ((function(value) - function(value-delta))/delta)

def central_derivation(function, value, delta):
    return ((function(value+delta) - function(value-delta))/delta*2)

def forward_derivation_image(image, position, direction):
    # Pega o valor de f(x)
    #print(image.size)
    #print(position)
    f_x = image.getpixel(position)

    # Pega o valor de f(x + 1)
    if(direction == 'x'):
        # Caso esteja percorrendo em x
        new_position = list(position)
        new_position[1] += 1
        delta_position = tuple(new_position)
        
        f_x_delta = image.getpixel(delta_position)
    elif(direction == 'y'):
        # Caso esteja percorrendo em y
        new_position = list(position)
        new_position[0] += 1
        delta_position = tuple(new_position)
        
        f_x_delta = image.getpixel(delta_position)
    
    return abs(f_x_delta - f_x)

def backward_derivation_image(image, position, direction):
    # Pega o valor de f(x)
    #print(image.size)
    print(position)
    f_x = image.getpixel(position)

    # Pega o valor de f(x - 1)
    if(direction == 'x'):
        # Caso esteja percorrendo em x
        new_position = list(position)
        new_position[1] -= 1
        delta_position = tuple(new_position)
        
        f_x_delta = image.getpixel(delta_position)
    elif(direction == 'y'):
        # Caso esteja percorrendo em y
        new_position = list(position)
        new_position[0] -= 1
        delta_position = tuple(new_position)
        
        f_x_delta = image.getpixel(delta_position)
    
    return abs(f_x - f_x_delta)

def central_derivation_image(image, position, direction):
    if(direction == 'x'):
        # Caso esteja percorrendo em x
        new_position = list(position)
        new_position[1] += 1
        delta_position = tuple(new_position)
        f_x_delta_forward = image.getpixel(delta_position)
        
        new_position[1] -= 2
        delta_position = tuple(new_position)
        f_x_delta_backward = image.getpixel(delta_position)
    elif(direction == 'y'):
        # Caso esteja percorrendo em y
        new_position = list(position)
        new_position[0] += 1
        delta_position = tuple(new_position)
        f_x_delta_forward = image.getpixel(delta_position)
        
        new_position[0] -= 2
        delta_position = tuple(new_position)
        f_x_delta_backward = image.getpixel(delta_position)
    
    return abs((f_x_delta_forward - f_x_delta_backward)/2)