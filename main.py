#-*- coding: utf-8 -*-
from __future__ import print_function
from argparse import ArgumentParser # Lib que eu vou usar pra fazer a passagem de argumentos (Daniel)
from PIL import Image # Depois vou fazer o try/catch da importação dessa lib (Daniel)

# Abrindo Imagem no Formato 'Image'
normal_image = Image.open('test-image.jpg')

# Criando Image em Grayscale
grayscale_image = normal_image.convert('LA')

# Salvando a imagem em Grayscale em disco
grayscale_image.save('test-image-grayscale.jpg')
