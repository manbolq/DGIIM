#include <fstream>
#include <iostream>

#include "dictionary.h"
#include "letters_set.h"

using namespace std;

int main(int argc, char *argv[]){

    if (argc != 3){
        cout << "Parametros incorrectos. Uso:" << endl;
        cout << "cantidad_letras <Diccionario> <FichLetras>" << endl;
        return 1;
    }

    Dictionary dictionary;
    LettersSet lettersSet;

    ifstream f_diccionario(argv[1]);
    ifstream letters_file(argv[2]);

    if(!f_diccionario){
        cout << "No puedo abrir el fichero " << argv[1] << endl;
        return 0;
    }
    f_diccionario >> dictionary;

    if(!letters_file){
        cerr << "No puedo abrir el fichero " << argv[2] << endl;
        return 0;
    }
    letters_file >> lettersSet;

    int usages = 0;
    int ocurr = 0;
//    cout << "Letra \t Usos \t Ocurrencias" << endl;
//    for (char c = 'a'; c <= 'z'; c++){
//        usages = dictionary.getTotalUsages(c);
//        if (usages > 0){
//            cout << c << "\t" << usages << "\t" << dictionary.getOccurrences(c) << endl;
//        }
//    }


    ocurr = dictionary.getOccurrences('a');
    usages = dictionary.getTotalUsages('a');


    cout << "Usages: " << usages << endl;
    cout << "Ocurrencies: " << ocurr << endl;

    return 0;
}