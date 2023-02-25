#!/bin/bash
# Titulo: Practica 3
# Fecha: 16/3/2021
# Autor: Manuel Vicente Bolaños Quesada
# Versión: 1.0
# Descripción: Crea un guión que muestre los archivos de un directorio
#    (que se pasará como primer argumento) que han sido accedidos en los últimos x
#    días (este número de días se pasará como segundo argumento al guión)
#    Al ejecutar el guión deberá aparecer: "Los archivos del directorio
#    nombre_directorio que han sido accedidos en los últimos numero_dias días son: "


printf "Los archivos del directorio $1 que han sido accedidos en los últimos $2 días son:\n"
find $1 -atime -$2
