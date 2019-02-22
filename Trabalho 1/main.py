#-*- coding: utf-8 -*-
from __future__ import print_function
from argparse import ArgumentParser # Lib que eu vou usar pra fazer a passagem de argumentos (Daniel)
from PIL import Image # Depois vou fazer o try/catch da importação dessa lib (Daniel)
import derivate_functions as derivate

# Abrindo Imagem no Formato 'Image'
normal_image = Image.open('image2.jpg')
print(normal_image.size)
# Criando Image em Grayscale
grayscale_image = normal_image.convert('L')

# Salvando a imagem em Grayscale em disco
# grayscale_image.save('test-image-grayscale.jpg')

# Recebe coordenadas da imagem
def function(image, position):
    # Retorna valor do pixel
    return image.getpixel(position)

#print(function(grayscale_image, (0, 0)))

# Cria a imagem que receberá a mascara nova
masc_image = grayscale_image

# Recebe valor de altura e largura da imagem (último pixel da 'direita' e último pixel de 'baixo')

width, height = masc_image.size

#Trabalhando percorrendo da esquerda pra direita da imagem (percorrendo por colunas)

# Laço de repetição para utilização do Forward (Todos os pixels da primeira coluna da imagem)
for h in range(0, height-1):
    masc_image.putpixel( (0,h), derivate.forward_derivation_image(grayscale_image, (0,h), 'x') )

# Laço de repetição para utilização do Central (Todos os pixels das colunas e linhas centrais)
for h in range(0, height-1):
    for w in range(1, width-2):
        value = derivate.central_derivation_image(grayscale_image, (w,h), 'x')
        masc_image.putpixel( (w,h),  value)

# Laço de repetição para utilização do Backward (Todos os pixels da última coluna da imagem)
for h in range(0, height-1):
    masc_image.putpixel( (width-1,h) , derivate.backward_derivation_image(grayscale_image, (width-1,h), 'x') )

masc_image.save('masc-image.jpg')

# Cria a imagem aplicando o treshold
treshimage = masc_image
treshold = 100

# Percorre todos os pixels verificando o treshold
for x in range(0, height):
    for y in range(0, width):
        if(grayscale_image.getpixel((y,x))>=treshold):
                treshimage.putpixel( (y,x),  255)
        else:
                treshimage.putpixel( (y,x), 0)

treshimage.show()