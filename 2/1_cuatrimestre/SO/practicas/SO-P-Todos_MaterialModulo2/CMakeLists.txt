cmake_minimum_required(VERSION 3.21)
project(SO_P_Todos_MaterialModulo2 C)

set(CMAKE_C_STANDARD 11)

add_executable(ejercicio7 Sesion3/ejercicio7.c Sesion3/consumidorFIFO.c Sesion3/productorFIFO.c)
add_executable(programa3 Sesion3/programa3.c)
add_executable(consumidorFIFO Sesion3/consumidorFIFO.c recorrer.c examen/buscar.c)
add_executable(productorFIFO Sesion3/productorFIFO.c)
add_executable(ejercicio3 Sesion2/ejercicio3.c)
add_executable(tarea7 Sesion4/tarea7.c)
add_executable(recorrer recorrer.c)
add_executable(examen1 examenes/examen1.c)
add_executable(buscar examen/buscar.c examen/pares_impares.c)