#!/bin/bash
#Titulo: Practica 5
#Fecha: 27/04/2021
#Autor: Manuel Vicente Bolaños Quesada
#Descripcion: Escribir un script que muestre un menú con el siguiente aspecto:

#Seleccione opción:

#1) Sumar números

#2) Restar números

#3) Multiplicar números

#4) Salir

#Elija la opción deseada:

#(a) La opción 1, debe solicitar por teclado dos números y deberá mostrar los números, así como la suma de ambos.

#(b) La opción 2, debe solicitar por teclado dos números y deberá mostrar los números, así como la diferencia entre ambos.

#(c) La opción 3, debe solicitar por teclado dos números y deberá mostrar los números, así como el producto de ambos.

#(d) La opción 4, debe permitir salir del script y volver al indicador del Shell. Mientras no se pulse este valor, siempre se mostrará el menú.

while true;
do
	printf "Seleccione opción: \n 1)Sumar números. \n 2)Restar números. \n 3)Multiplicar números. \n 4)Salir \n"
	read opcion
	case $opcion in 
		1) printf "\nNumero 1:\n"
		read n1
		printf "\nNumero2:\n"
		read n2
		printf "Numero 1: $n1, Numero2: $n2\n"
		echo  $(($n1+$n2));;
		
		2) printf "\nNumero 1:\n"
                read n1
                printf "\nNumero2:\n"
                read n2
                printf "Numero 1: $n1, Numero2: $n2\n"
                echo $(($n1-$n2));;

		3) printf "\nNumero 1:\n"
                read n1
                printf "\nNumero2:\n"
                read n2
                printf "Numero 1: $n1, Numero2: $n2\n"
                echo $(($n1*$n2));;

		4) exit 1;;
		
		*) ;;
		
		esac
done
