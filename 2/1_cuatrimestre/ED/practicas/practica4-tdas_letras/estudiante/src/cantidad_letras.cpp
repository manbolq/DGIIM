/**
 * @file cantidad_letras.cpp
 * @brief  Archivo de implementación de un programa que, dado un diccionario y un conjunto de letras, imprime las
 * frecuencias absolutas y relativas de cada letras, con respecto al diccionario
 */
#include "dictionary.h"
#include "letters_set.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Error: numero incorrecto de parametros.\n";
        cerr << "Uso: cantidad_letras <FicheroPalabras> <FicheroLetras>";
        exit(1);
    }

    string dic_file = argv[1];
    string let_file = argv[2];
    Dictionary dictionary;
    LettersSet let_set;
    ifstream fs;

    fs.open(dic_file);
    if (fs) {
        while (!fs.eof()) {
            string word;
            fs >> word;
            dictionary.insert(word);
        }
    }
    fs.close();

    fs.open(let_file);
    if (fs)
        fs >> let_set;

    int total_letters = dictionary.getTotalLetters();

    cout << "Letra\tFAbs.\tFrel." << endl;
    for (char c = 'A'; c <= 'Z'; c++){
        LetterInfo aux{0, 0};
        pair<char, LetterInfo> aux_pair;
        aux_pair.first = c;
        aux_pair.second = aux;
        if (!let_set.insert(aux_pair)){
            int ocurrences = dictionary.getOcurrences(c);
            cout << c << "\t" << ocurrences << "\t" << (double)ocurrences/total_letters << endl;
        } else
            let_set.erase(c);
    }

    return 0;
}