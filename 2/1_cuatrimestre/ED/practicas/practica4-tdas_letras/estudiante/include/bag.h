/**
 * @file bag.h
 * @brief  Archivo de especificación e implementación del TDA Bag
 */


#ifndef __BAG_H__
#define __BAG_H__

/**
 *  @brief TDA abstracto Bolsa
 *
 *  Este TDA abstracto nos permite trabajar con una colección de elementos que
 *  permite la extracción de elementos de forma aleatoria sin reemplazamiento
 */

#include<vector>
#include<stdlib.h>
using namespace std;

template <class T>

class Bag {
private:
    /**
     * @brief Vector que almacena la colección de elementos
     */
    vector<T> v;

public:

    /**
     * @brief Constructor por defecto.
     * Inicializa el objeto de tipo Bag
     */
    Bag() :v() {}

    /**
     * @brief Constructor de copia.
     * Crea una copia exacta de otro objeto de tipo Bag
     * @param other Objeto de tipo Bag<T> del que se va a realizar la copia
     */
    Bag(const Bag<T> & other){

        other.v = this->v;
    }

    /**
     * @brief Añade un elemento a la bolsa
     * @param element elemento del tipo T a añadir a la bolsa
     */
    void add(const T & element){
        v.push_back(element);
    }
    /**
     * @brief Extrae un elemento aleatorio de la bolsa
     * Devuelve un elemento aleatorio de la bolsa y lo borra de la misma
     * @return Elemento de tipo T extraido de la bolsa
     * @pre La bolsa no esta vacia
     * @post El elemento devuelto es eliminado de la bolsa
     */
    T get(){
        int num = rand()%size();
        typename vector<T>::iterator it = v.begin();
        advance(it, num);

        T elemento = v.at(num);

        *it = v.back();
        v.pop_back();

        return elemento;
    }

    /**
     * @brief Elimina todos los elementos de la bolsa.
     * Borra todos los elementos almacenados en la bolsa
     */
    void clear(){
        v.clear();
    }

    /**
     * @brief Tamaño de la bolsa
     * @return Numero de elementos de la bolsa
     */
    int size() const{
        return v.size();
    }

    /**
     * @brief Comprueba si la bolsa esta vacia
     * @return true si la bolsa esta vacia, false en caso contrario
     */
    bool empty (){
        return v.empty();
    }

    /**
     * @brief Sobrecarga del operador de asignacion
     * @param other Bag a copiat
     * @return Referencia a this para poder encadenar el operador
     */
    const Bag<T>& operator=(const Bag<T> & other){

        if(this != &other){
            this->v=other.v;
        }

        return *this;
    }
};
#endif
