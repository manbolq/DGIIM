/**
 * @file Event.cpp
 * @author DECSAI
 * @note To be implemented by students 
 * 
 */

#include <string>
#include "Event.h"
using namespace std;

Event::Event()
{
    initDefault();
}

void Event::initDefault()
{
    set(EVENT_DEFAULT);
}

Event::Event(const string &line)
{
    set(line);
}

DateTime Event::getDateTime ()const
{
    return _dateTime;
}

string Event::getType() const
{
    return _type;
}

string Event::getProductID()const
{
    return _prod_id;
}

string Event::getCategoryID()const
{
    return _cat_id;
}

string Event::getCategoryCode()const
{
    return _cat_cod;
}

string Event::getBrand()const
{
    return _brand;
}

double Event::getPrice() const
{
    return _price;
}

string Event::getUserID()const
{
    return _user_id;
}

string Event::getSession()const
{
    return _session;
}

void Event::setDateTime(const string &time)
{
    _dateTime = DateTime(time);
}

void Event::setType(const string &type)
{
    if (type == "view" || type == "cart" || type == "purchase" || type == "remove_from_cart")
        _type = type;
    else
        _type = VALID_TYPES[0];
}

void Event::setProductID(const string &prod_id)
{
    _prod_id = prod_id != "" ? prod_id : EMPTY_FIELD;
}

void Event::setCategoryID(const string &cat_id)
{
    _cat_id = cat_id;
}

void Event::setCategoryCode(const string &cat_cod)
{
    _cat_cod = cat_cod;
}

void Event::setBrand(const string &brand)
{
    _brand = brand;
}

void Event::setPrice(const double &price)
{
    _price = price >= 0 ? price : -1.0;
}

void Event::setUserID(const string &user_id)
{
    _user_id = user_id != "" ? user_id : EMPTY_FIELD;
}

void Event::setSession(const string  &session)
{
    _session = session != "" ? session : EMPTY_FIELD;
}

void Event::set(const string &line)
{
    int longitud = line.length();
    int pos;
    string casillas[9];
    casillas[0] = line.substr(0, line.find(','));
    pos = casillas[0].length();
    
    for (int i = 1; i < 9; i++){
        bool encontrado = false;
        for (int j = pos + i; j < longitud && !encontrado; j++){
            if (line.at(j) != ',')
                casillas[i].push_back(line.at(j));
            else
                encontrado = true;
        }
        pos+=casillas[i].length();
    }
    
    _dateTime = DateTime(casillas[0]);
    _type = (casillas[1] ==  "view" || casillas[1] == "cart" || casillas[1] == "purchase" || casillas[1] == "remove_from_cart") ? casillas[1] : "view";
    _prod_id = casillas[2] != "" ? casillas[2] : EMPTY_FIELD;
    _cat_id = casillas[3] != "" ? casillas[3] : "";
    _cat_cod = casillas[4] != "" ? casillas[4] : "";
    _brand = casillas[5] != "" ? casillas[5] : "";
    _price = (casillas[6] != "" && stod(casillas[6]) >= 0) ? stod(casillas[6]) : -1.0;
    _user_id = casillas[7] != "" ? casillas[7] : EMPTY_FIELD;
    _session = casillas[8] != "" ? casillas[8] : EMPTY_FIELD;
}

bool Event::isEmpty()
{
    return _dateTime.to_string() == DATETIME_DEFAULT || (_type != "view" && _type != "cart" && _type != "purchase" && _type != "remove_from_cart")
           || _prod_id == EMPTY_FIELD || _price < 0 || _user_id == EMPTY_FIELD || _session == EMPTY_FIELD;
}

string Event::to_string() const
{
    string salida;
    salida += _dateTime.to_string();
    salida += "," + _type;
    salida += "," + _prod_id;
    salida += "," + _cat_id;
    salida += "," + _cat_cod;
    salida += "," + _brand;
    salida += "," + std::to_string(_price);
    salida += "," + _user_id;
    salida += "," + _session;
    return salida;
}
