#!/bin/bash

#optimizacion O2
cd optimizacion_O2;
echo "OPTIMIZACION O2";
echo "insercion mejor caso...";
./insercion_mejor_caso >> insercion_mejor_caso.dat;
echo "completado";
echo "insercion peor caso...";
./insercion_peor_caso >> insercion_peor_caso.dat;
echo "completado";
echo "quicksort...";
./quicksort >> quicksort.dat;
echo "completado";
echo "seleccion...";
./seleccion >> seleccion.dat;
echo "completado";
echo "seleccion mejor caso...";
./seleccion_mejor_caso >> seleccion_mejor_caso.dat;
echo "completado";
echo "seleccion peor caso...";
./seleccion_peor_caso >> seleccion_peor_caso.dat;
echo "completado";

#optimizacion O3
cd ../optimizacion_O3;
echo "OPTIMIZACION O3";
echo "floyd...";
./floyd >> floyd.dat;
echo "completado";
echo "Hanoi...";
./hanoi >> hanoi.dat;
echo "completado";
echo "heapsort...";
./heapsort >> heapsort.dat;
echo "completado";
echo "insercion...";
./insercion >> insercion.dat;
echo "completado";
echo "insercion mejor caso...";
./insercion_mejor_caso >> insercion_mejor_caso.dat;
echo "completado";
echo "insercion pero caso...";
./insercion_peor_caso >> insercion_peor_caso.dat;
echo "completado";
echo "quicksort...";
./quicksort >> quicksort.dat;
echo "completado";
echo "seleccion...";
./seleccion >> seleccion.dat;
echo "completado";
echo "seleccion mejor caso...";
./seleccion_mejor_caso >> seleccion_mejor_caso.dat;
echo "completado";
echo "seleccion peor caso...";
./seleccion_peor_caso >> seleccion_peor_caso.dat;
echo "completado";
