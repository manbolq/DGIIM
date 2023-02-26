/* 
 * File:   Index.cpp
 * @author MP-Team DECSAI
 */
#include <string>
#include <iostream>
#include <fstream>
#include "Index.h"

using namespace std;

Index::Index()  {
    _onBrand = 0;
    _nEntries = 0;
}

Index::Index(int onBrand) {
    setIOnWhich(onBrand);
    _nEntries = 0;
}

void Index::setIOnWhich(int val) {
    _onBrand = val;
}

int Index::size() const {
    return _nEntries;
}

void Index::clear() {
    _nEntries = 0;
}

int Index::getIOnWhich() const {
    return _onBrand;
}

int Index::add(const Pair & pair) {
    int success = 0;
    
    if(!pair.isEmpty() && _nEntries < MAXEVENT){
        success = 1;
        
        int pos = upper_bound(pair.getKey());
        
        for(int i = _nEntries; i > pos; i--)
            _entries[i]=_entries[i-1];
        
        _entries[pos] = pair;
        _nEntries++;
    }
    
    return(success);
}


void Index::build(const EventSet & evSet, int onBrand) {
    setIOnWhich(onBrand);
    clear();   
    int size = evSet.size();
    for (int i = 0; i < size; i++){
        string key = _onBrand == 1 ? evSet.at(i).getBrand() : evSet.at(i).getUserID();
        if (key != "")
            add(Pair(key, i));
    }
}

int Index::lower_bound(const string & key) const {
    for(int i = 0; i < _nEntries; i++){
        if(key <= _entries[i].getKey())
            return i;
    }
    return _nEntries;
}

int Index::upper_bound(const string & key) const { 
    for(int i = 0; i < _nEntries; i++){
        if(key < _entries[i].getKey())
            return i;
    }
    return _nEntries;
}

const Pair & Index::at(int pos) const {
    return _entries[pos];
}

Pair & Index::at(int pos) {
    return _entries[pos];
}

void Index::print()const {
    cout << endl << to_string() << endl;
}

Event getEvent(const EventSet & evSet, const Index & indx, int pos) {
    return evSet.at(indx.at(pos).getPos());
}

void write(ofstream &os, const EventSet & evSet, const Index & indx) {
    int size = indx.size();
    for (int i = 0; i < size; i++){
        os << evSet.at(indx.at(i).getPos()).to_string() << endl;
    }
}

Index rawFilterIndex(const EventSet & evSet, const Index & indx, const std::string &field, const std::string &value) {
    int size = indx.size();
    Index filteredIndex;
    
    for (int i = 0; i < size; i++){
        string key = getEvent(evSet, indx, i).getField(field);
        if (key == value)
            filteredIndex.add(Pair(key, indx.at(i).getPos()));
    }
    
    return filteredIndex;
}


float sumPrice(const EventSet & evSet, const Index & indx) {
    double price = 0;
    int size = indx.size();
    for (int i = 0; i < size; i++){
        price += getEvent(evSet, indx, i).getPrice();
    }
    return price;
}