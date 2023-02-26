/**
 * @file dictionary.cpp
 * @brief  Archivo de implementación del TDA Dictionary
 */

#include "dictionary.h"

Dictionary::Dictionary() {
    words.clear();
}

Dictionary::Dictionary(const Dictionary &other) {
    words = other.words;
}

bool Dictionary::exists(const string &val) const {
    return words.count(val);
}

bool Dictionary::insert(const string &val) {
    if (words.count(val) == 0) {
        words.insert(val);
        return true;
    }
    else
        return false;
}

bool Dictionary::erase(const string &val) {
    if (words.count(val) == 1){
        words.erase(val);
        return true;
    }
    else
        return false;
}

void Dictionary::clear() {
    words.clear();
}

bool Dictionary::empty() const {
    return words.empty();
}

unsigned int Dictionary::size() const {
    return words.size();
}

int Dictionary::getOcurrences(const char c) {
    int ocurrences = 0;
    for (auto it = words.begin(); it != words.end(); it++){
        int length = (*it).length();
        for (int i = 0; i < length; i++){
            if (toupper((*it)[i]) == toupper(c))
                ocurrences++;
        }
    }
    return ocurrences;
}

int Dictionary::getTotalLetters() {
    int total = 0;
    for (auto it = words.begin(); it != words.end(); it++)
        total += (*it).length();

    return total;
}

vector<string> Dictionary::wordsOfLength(int length) {
    vector<string> aux;
    for (auto it = words.begin(); it != words.end(); it++){
        if ((*it).length() == length)
            aux.push_back(*it);
    }
    return aux;
}

