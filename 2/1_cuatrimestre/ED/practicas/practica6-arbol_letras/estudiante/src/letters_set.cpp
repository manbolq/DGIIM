/**
 * @file letters_set.cpp
 * @brief  Archivo de implementación del TDA LettersSet
 */

#include "letters_set.h"

LettersSet::LettersSet() {
    letters.clear();
}

LettersSet::LettersSet(const LettersSet &other) {
    letters = other.letters;
}

bool LettersSet::insert(const pair<char, LetterInfo> &val) {
    if (letters.count(val.first) == 0) {
        letters.insert(val);
        return true;
    }
    else
        return false;
}

bool LettersSet::erase(const char &key) {
    if (letters.count(key) == 0)
        return false;
    else {
        letters.erase(letters.find(key));
        return true;
    }
}

void LettersSet::clear() {
    letters.clear();
}

bool LettersSet::empty() const {
    return letters.empty();
}

unsigned int LettersSet::size() const {
    return letters.size();
}

LettersSet & LettersSet::operator=(const LettersSet &cl) {
    letters.clear();
    letters = cl.letters;
    return *this;
}

LetterInfo & LettersSet::operator[](const char val){
    return letters.at(val);
}

const LetterInfo & LettersSet::operator[](const char val) const{
    return letters.at(val);
}

int LettersSet::getScore(string word) const{
    int size = word.length();
    int score = 0;

    for (int i = 0; i < size; i++) {
        score += letters.at(toupper(word[i])).score;
    }

    return score;
}

ostream & operator<<(ostream & os, const LettersSet & cl){
    os << "Letra\tCantidad\tPuntos" << endl;
    for (char c = 'A'; c <= 'Z'; c++){
        if (cl.letters.count(c) == 1)
            os << c << "\t" << cl.letters.at(c).repetitions << "\t" << cl.letters.at(c).score << endl;
    }
    return os;
}

istream & operator>>(istream & is, LettersSet & cl){
    string trash;
    string letter, previous_letter;
    int repetitions = 0, score = 0;
    is >> trash >> trash >> trash; //cabecera

    is >> letter;
    do{
        previous_letter = letter;
        is >> repetitions;
        is >> score;
        LetterInfo aux{repetitions, score};
        pair<char, LetterInfo> aux_pair;
        aux_pair.first = letter[0];
        aux_pair.second = aux;
        cl.insert(aux_pair);
        is >> letter;
    }while (letter != previous_letter);

    return is;
}


