/* 
 * File:   EventSet.cpp
 * @author MP-Team DECSAI
 * @note To be implemented by students 
 */

#include <fstream>
#include <unordered_map>
#include "EventSet.h"

using namespace std;

/**
 * @brief Give string[] and a string, it searches for string within string[]
 * @param array     The set of strings to look for
 * @param n_array   The size of string[]
 * @param name      The string that is being seeked
 * @return          The position of the first occurrence of string within string[]
 *  -1 if the string does not belong to string[]
 */
int findString(const string array[], int n_array, const string & name) {
    int pos = -1;
    bool found = false;
    for (int i = 0; i < n_array && !found; i++) {
        if (array[i] == name) {
            pos = i;
            found = true;
        }
    }
    return pos;
}

std::string EventSet::to_string() const {
    string result;
    result = std::to_string(_nEvents) + " ";
    for (int i = 0; i < _nEvents; i++)
        result += _events[i].to_string() + "\n";
    return result;
}

void EventSet::reallocate(unsigned size){
    while (_nEvents + size > _capacity){
        _capacity = 2*_capacity + 1;
    }
    
    Event *aux = new Event [_capacity];
    
    for (int i = 0; i < _nEvents; i++)
        aux[i] = _events[i];
    
    deallocate();
    _events = aux;
    aux = nullptr;
}

void EventSet::deallocate(){
    if (_events != nullptr){
        delete [] _events;
        _events = nullptr;
    }
}

void EventSet::copy(Event* dest) const{
    dest = new Event [_capacity];
    for (int i = 0; i < _nEvents; i++){
        dest[i] = _events[i];
    }
}

void EventSet::copy(const EventSet& orig){
    _nEvents = orig.size();
    _capacity = orig._capacity;
    
    deallocate();
    
    _events = new Event [_capacity];
    
    for (int i = 0; i < _nEvents; i++)
        _events[i] = orig.at(i);
}

EventSet::EventSet() {
    _nEvents = 0;
    _capacity = 0;
    _events = nullptr;
}

EventSet::EventSet(const EventSet &orig){
    _events = nullptr;
    copy(orig);
}

EventSet::~EventSet(){
    deallocate();
}

int EventSet::size() const {
    return _nEvents;
}

void EventSet::clear() {
    _capacity = 0;
    _nEvents = 0;
    deallocate();
}

int EventSet::add(const Event & e) {
    reallocate(1);
    _events[_nEvents] = e;
    _nEvents++;
    
    return 1;
}

int EventSet::add(const std::string& line) {
    return add(Event(line));
}

const Event & EventSet::at(int pos) const {
    if (0 <= pos && pos < _nEvents)
        return _events[pos];
    else
        return NULL_EVENT;
}

void EventSet::write(std::ofstream &os) const {
    string cadena;
    
    for(int i=0; i < _nEvents; i++)
        cadena += at(i).to_string() + "\n";
    
    os << cadena;
}

bool EventSet::read(std::ifstream &is, int nelements) {    
    Event es;
    bool res = true;
    
    // Limpiar el EventSet
    clear();
    
    for(int i=0; (i < nelements)&&res; i++){
        es.read(is);
    
        if(is)
            add(es);
        else
            res = false;
    }
    return(res);
}

EventSet & EventSet::operator=(const EventSet & one){
    if (&one != this)
        copy(one);
    
    return *this;
}

EventSet rawFilterEvents(const EventSet& es, const std::string &field, const std::string &value) {
    EventSet subset;

    if (field != "DateTime") {
        for (int i = 0; i < es.size(); i++)
            if (es.at(i).getField(field) == value)
                subset.add(es.at(i));
    }
    else {
        for (int i = 0; i < es.size(); i++) {
            DateTime date(value);
            if (date.sameDay(es.at(i).getDateTime()))
                subset.add((es.at(i)));
        }
    }
    return (subset);
}

void findUnique(const EventSet& es, const std::string &field, std::string values[], int & n_values) {
    n_values = 0;
    
    if(field != "DateTime"){
        for(int i = 0; i < es.size(); i++){
            bool found = false;

            for(int j = 0; (j < n_values) && !found; j++)
                if(es.at(i).getField(field) == values[j])
                    found = true;

            if(!found){
                values[n_values] = es.at(i).getField(field);
                n_values++;
            }
        }
    } else {
        for(int i = 0; i < es.size(); i++){
            bool found = false;
        
            for(int j = 0; j < n_values && !found; j++){
                DateTime date(values[j]);
                if(date.sameDay(es.at(i).getDateTime()))
                    found = true;
            }
            
            if(!found){
                string date = es.at(i).getDateTime().to_string();
                date.at(11) = '0';
                date.at(12) = '0';
                date.at(14) = '0';
                date.at(15) = '0';
                date.at(17) = '0';
                date.at(18) = '0';
                
                values[n_values] = date;
                n_values++;
            }
        }
    }
}

float sumPrice(const EventSet & evSet) {
    int size = evSet.size();
    float total = 0;
    for (int i = 0; i < size; i++)
        if (evSet.at(i).getPrice() >= 0)
            total += evSet.at(i).getPrice();

    return total;
}

Event NULL_EVENT = Event();