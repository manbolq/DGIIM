/**
 * @file solver.cpp
 * @brief Archivo de implementación del TDA solver.
 */

#include "solver.h"

Solver::Solver(const Dictionary & dict, const LettersSet & letters_set){
    d = dict;
    l = letters_set;
}

pair<vector<string>,int> Solver::getSolutions(const vector<char> & available_letters, bool score_game){
    if(score_game)
        return getSolutionsScore(available_letters);
    else
        return getSolutionsLength(available_letters);
}

bool Solver::formable(string word, vector<char> &letters) {
    bool formable = true;
    int size = word.size();
    for(int i=0; i<size && formable; i++){
        bool found = false;

        for(auto it = letters.begin(); it != letters.end() && !found; ++it){
            if(*it == toupper(word[i])){
                found = true;
                letters.erase(it);
            }
        }
        if(!found) formable = false;
    }
    return formable;
}

pair<vector<string>, int> Solver::getSolutionsScore(const vector<char> &available_letters) {
    vector <string> solution;
    int max_puntuacion = 0;

    for(Dictionary::iterator it = d.begin(); it != d.end(); ++it){
        vector <char> aux = available_letters;

        if(formable((*it),aux)) {
            int score = l.getScore(*it);
            if (score==max_puntuacion)
                solution.push_back(*it);

            else if(score>max_puntuacion){
                solution.clear();
                solution.push_back(*it);
                max_puntuacion = score;
            }
        }

    }
    return pair<vector<string>, int> (solution, max_puntuacion) ;
}

pair<vector<string>, int> Solver::getSolutionsLength(const vector<char> &available_letters) {

    vector <string> solution;
    int max_length = 0;

    for(Dictionary::iterator it = d.begin(); it != d.end(); ++it){
        vector <char> aux = available_letters;
        int size = (*it).length();
        if((*it).length()>=max_length) {
            if (formable((*it), aux)) {
                if (size == max_length)
                    solution.push_back(*it);

                else {
                    solution.clear();
                    solution.push_back(*it);
                    max_length = size;
                }
            }
        }
    }
    return pair<vector<string>, int> (solution, max_length) ;

}