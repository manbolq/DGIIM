/**
 * @file letters_bag.cpp
 * @brief  Archivo de implementación del TDA LettersBag
 */
#include "letters_bag.h"

LettersBag::LettersBag() {}

LettersBag::LettersBag(LettersSet &letterSet) {

    for(LettersSet::iterator it=letterSet.begin(); it!=letterSet.end(); ++it){
        char letra = (*it).first;
        for(int j=0; j<letterSet[letra].repetitions; j++)
            insertLetter(letra);
    }

}

unsigned int LettersBag::size() const { return letters.size(); }

void LettersBag::clear() { letters.clear(); }

char LettersBag::extractLetter() { return letters.get(); }

vector<char> LettersBag::extractLetters(int num) {
    vector<char> result;
    for(int i=0; i<num; i++)
        result.push_back(extractLetter());

    return result;
}

void LettersBag::insertLetter(const char &l) { letters.add(l); }

LettersBag &LettersBag::operator=(const LettersBag &other) {

    this->letters = other.letters;

    return *this;
}