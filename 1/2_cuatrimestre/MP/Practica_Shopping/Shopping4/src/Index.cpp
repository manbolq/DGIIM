/* 
 * File:   Index.cpp
 * @author MP-Team DECSAI
 */
#include <string>
#include <iostream>
#include <fstream>
#include "Index.h"

using namespace std;

void Index::reallocate(int size){
    while (_nEntries + size > _capacity){
        _capacity = 2*_capacity + 1;
    }
    
    Pair *aux = new Pair [_capacity];
    
    for (int i = 0; i < _nEntries; i++)
        aux[i] = _entries[i];
    
    deallocate();
    _entries = aux;
    aux = nullptr;
}

void Index::deallocate(){
    if (_entries != nullptr){
        delete [] _entries;
        _entries = nullptr;
    }
}

void Index::copy(const Index& orig){
    _nEntries = orig._nEntries;
    _capacity = orig._capacity;
    _onBrand = orig._onBrand;
    
    deallocate();
    
    _entries = new Pair [_capacity];
    
    for (int i = 0; i < _nEntries; i++)
        _entries[i] = orig.at(i);
}

void Index::copy(Pair *dest){
    dest = new Pair [_capacity];
    for (int i = 0; i < _nEntries; i++)
        dest[i] = _entries[i];
}

Index::Index(int onBrand) {
    _entries = nullptr;
    _capacity = 0;
    _nEntries = 0;
    setIOnWhich(onBrand);
}

Index::Index(const Index & orig){
    _entries = nullptr;
    _capacity = 0;
    _nEntries = 0;
    copy(orig);
}

Index::~Index(){
    deallocate();
}

Index & Index::operator=(const Index &one){
    if (&one != this)
        copy(one);
    
    return *this;
}

void Index::setIOnWhich(int val) {
    _onBrand = val;
}

int Index::size() const {
    return _nEntries;
}

void Index::clear() {
    _capacity = 0;
    _nEntries = 0;
    deallocate();
}

int Index::getIOnWhich() const {
    return _onBrand;
}

int Index::add(const Pair & pair) {   
    if(!pair.isEmpty()){
        reallocate(1);
        int pos = upper_bound(pair.getKey());
        
        for(int i = _nEntries-1; i >= pos; i--)
            _entries[i+1]=_entries[i];
        
        _nEntries++;
        _entries[pos] = pair;
        
    }
    
    return(1);
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