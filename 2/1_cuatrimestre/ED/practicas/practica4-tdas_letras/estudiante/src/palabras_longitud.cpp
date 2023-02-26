/**
 * @file palabras_longitud.cpp
 * @brief  Archivo de implementación de un programa que, dado un conjunto de palabras y un entero, imprime todas las
 * palabras que tengan de longitud el entero dado
 */

#include "dictionary.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
    if (argc != 3) {
        cerr << "Error: numero incorrecto de parametros.\n";
        cerr << "Uso: palabras_longitud <FicheroPalabras> <Longitud>";
        exit(1);
    }

    string file = argv[1];
    int length = stoi(argv[2]);
    Dictionary dictionary;
    ifstream fs;

    fs.open(file);
    while (!fs.eof()){
        string word;
        fs >> word;
        if (word.length() > 1) {
            dictionary.insert(word);
        }
    }

    vector<string> words = dictionary.wordsOfLength(length);

    cout << "Palabras de longitud " << length << endl;
    for (auto it = words.begin(); it != words.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}

