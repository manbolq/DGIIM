/* 
 * File:   EventSet.cpp
 * @author MP-Team DECSAI
 * @note To be implemented by students 
 */


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
    int pos=-1;
    bool found = false;
    for (int i = 0; i < n_array && !found; i++){
        if (array[i] == name){
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

EventSet::EventSet() {
    clear();
}

int EventSet::size() const
{
    return _nEvents;
}


void EventSet::clear()
{
    _nEvents = 0;    
}

int EventSet::add(const Event & e) {
    int succesful=1;
    
    if(_nEvents < MAXEVENT){
        _events[_nEvents] = e;
        _nEvents++;
    }
        
    else
        succesful=0;
    
    return succesful;
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


EventSet rawFilterEvents(const EventSet& es, const std::string &field, const std::string &value) {
    EventSet subset;
    int size = es.size();
    for (int i = 0; i < size; i++)
        if (es.at(i).getField(field)==value)
            subset.add(es.at(i));
    
    return subset;
}

void findUnique(const EventSet& es, const std::string &field, std::string values[], int & n_values) {
    int size = es.size();
    n_values = 0;
    for (int i = 0; i < size; i++){
        bool found = false;
        string value = es.at(i).getField(field);
        for (int j = 0; j < n_values; j++)
            if (value == values[j])
                found = true;
        if (!found){
            values[n_values] = value;
            n_values++;
        }
    }
}

float sumPrice(const EventSet & evSet) {
    int size = evSet.size();
    float total = 0;
    for (int i = 0; i < size; i++)
        if (evSet.at(i).getPrice() >= 0)
            total+=evSet.at(i).getPrice();
    
    return total;
}

Event NULL_EVENT=Event();