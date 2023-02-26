/**
 * @page
 * @file partida_letras.cpp
 * @brief programa que prueba el TDA Solver
 */

#include "solver.h"
#include "letters_bag.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){

    srand(time(NULL));

    if (argc != 5){
        cerr << "Error: numero incorrecto de parametros.\n";
        cerr << "Uso: partida_letras <FicheroLetras> <FicheroDiccionario> <ModoJuego> <CantidadLetras>";
        exit(1);
    }

    string let_file = argv[1];
    string dic_file = argv[2];
    bool score_game = (argv[3][0] == 'P');
    int let_size = stoi(argv[4]);

    LettersSet l;   // Leemos el LettersSet
    ifstream f(let_file);
    f >> l;
    f.close();


    f.open(dic_file);   // Leemos el Dictionary
    Dictionary dictionary;
    if(f){
        while (!f.eof()) {
            string word;
            f >> word;
            dictionary.insert(word);
        }
    }

    vector<char> letters;
    LettersBag bag (l);

    // Rellena el vector con las letras
    letters = bag.extractLetters(let_size);


    pair<vector<string>,int> solutions;
    Solver solver(dictionary,l);

    if(!score_game)
        solutions = solver.getSolutions(letters, false);
    else
        solutions = solver.getSolutions(letters, true);

    cout << "LETRAS DISPONIBLES:" << endl;

    for(int i=0; i<let_size; i++)
        cout << letters[i] << " ";

    cout << endl << "SOLUCIONES:" << endl;

    int size = solutions.first.size();
    for(int i=0; i<size; i++)
        cout << solutions.first[i] << endl;

    cout << "PUNTUACION:" << endl << solutions.second;

    return 0;

}
