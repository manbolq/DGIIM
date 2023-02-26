/**
 * @file bolsa_letras.cpp
 * @brief  Archivo de implementación de un programa que crea un LetterSet a partir de un fichero dado y un LettersBag a
 * partir de ese LetterSet y muestra todas las letras de LettersBag por pantalla
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "letters_bag.h"

using namespace std;

int main(int argc, char *argv[]){

    // Inicializamos el generador de números aleatorios
    srand(time(NULL));

    if(argc != 2){
        cout << "ERROR: solo se admite un argumento con el nombre del fichero";
    }

    else{
        ifstream f;
        f.open(argv[1]);

            LettersSet letterSet;
            f >> letterSet;
            LettersBag bag(letterSet);
            while (bag.size() > 0) {
                cout << bag.extractLetter() << endl ;
            }

    }

    return 0;
}
