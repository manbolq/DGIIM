/**
 * @file conjunto_letras.cpp
 * @brief  Archivo de implementación de un programa que, dado un conjunto de letras y una palabra, imprime la puntuación
 * de dicha palabra
 */

#include "letters_set.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char *argv[]){

    if (argc != 3) {
        cerr << "Error: numero incorrecto de parametros.\n";
        cerr << "Uso: conjunto_letras <FicheroLetras> <Palabra>";
        exit(1);
    }

    string file = argv[1]; //Archivo del que se leen las letras
    string word = argv[2]; //Palabra a la que calcular su puntuacion

    LettersSet let_set;
    ifstream is;
    is.open(file);
    is >> let_set; //Leemos el conjunto de letras

    cout << let_set.getScore(word) << endl;

    return 0;
}