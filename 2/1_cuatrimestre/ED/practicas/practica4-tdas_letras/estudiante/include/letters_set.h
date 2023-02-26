/**
 * @file letters_set.h
 * @brief  Archivo de especificación del TDA LettersSet
 */

#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__

#include <map>
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief TDA LetterInfo
 *
 * Contiene información sobre un determinado carácter del juego de las
 * letras. En concreto, almacena información sobre el número de repeticiones de
 * la letra en la partida y de la puntuación que otorga al utilizarse en una
 * palabra
 * @param repetitions Número total de repeticiones de una letra
 * @param score Puntuación de la letra al utilizarla en una palabra
 */
struct LetterInfo{
    int repetitions;
    int score;
};



/**
 * @brief TDA LettersSet
 *
 * Este TDA representa un conjunto de letras, con la información necesaria para
 * jugar una partida al juego de las letras, es decir, el número de repeticiones
 * que tenemos de la letra y la puntuación que dicha letra otorga cuando se
 * utiliza en una palabra
 */

class LettersSet{
private:
    /**
     * @brief Contenedor para guardar las letras, con el número de veces que está repetida esa letra, y la puntuación
     * que aporta.
     */
    map <char, LetterInfo> letters;

public:
    class iterator{
    private:
        map<char, LetterInfo>::iterator it;
    public:
        iterator(){}

        iterator(const map<char, LetterInfo>::iterator &otro):it(otro){}

        iterator(const iterator &otro):it(otro.it){}

        ~iterator(){}

        iterator& operator=(const map<char, LetterInfo>::iterator &otro){
            it=otro;
            return *this;
        }

        iterator& operator=(const iterator& otro){
            it = otro.it;
            return *this;
        }

        pair<char,LetterInfo> operator*() const{
            return *it;
        }

        iterator& operator++(){
            ++it;
            return *this;
        }

        bool operator!=(const iterator& otro){
            return it!=otro.it;
        }

        bool operator==(const iterator& otro){
            return it==otro.it;
        }

    };

    /**
     * @brief Constructor por defecto.
     *
     * Crea un LettersSet vacío
     */
    LettersSet();

    /**
     * @brief Constructor de copia
     * @param other LettersSet a copiar
     */
    LettersSet(const LettersSet & other);

    /**
     * @brief Inserta un elemento en el LettersSet
     * @param val Pareja de letra y LetterInfo asociada a insertar
     * @return booleano que marca si se ha podido insertar la letra en el LettersSet. La letra solo se inserta
     * correctamente si no estaba aún incluida en la colección
     */
    bool insert(const pair<char, LetterInfo> & val);

    /**
     * @brief Elimina un carácter del LettersSet
     * @param key Carácter a eliminar
     * @return Booleano que indica si se ha podido eliminar correctamente la letra del LettersSet
     */
    bool erase(const char & key);

    /**
     * @brief Limpia el contenido del LettersSet
     *
     * Elimina el contenido del LettersSet
     */
    void clear();

    /**
     * @brief Consulta si el LettersSet está vacío
     * @return true si el LettersSet está vacío, falso en caso contrario
     */
    bool empty() const;

    /**
     * @brief Tamaño del LettersSet
     * @return Número de elementos en el LettersSet
     */
    unsigned int size() const;

    /**
     * @brief Calcula la puntuación dada una palabra
     * @param word String con la palabra cuya puntuación queremos calcular
     * @return Puntuación de la palabra, calculada como la suma de las puntuaciones de cada una de sus letras
     */
    int getScore(string word) const;

    /**
     * @brief Sobrecarga del operador de asignación
     * @param cl LettersSet a copiar
     * @return Referencia al objeto this para poder encadenar el operador
     */
    LettersSet & operator=(const LettersSet & cl);

    /**
     * Sobrecarga del operador de consulta
     *
     * Permite acceder a los elementos del map que hay en nuestra clase
     * @param val Carácter a consultar
     * @return Estructura de tipo LetterInfo con la información del carácter consultado: Número de repeticiones y
     * puntuación
     */
    LetterInfo & operator[](const char val);

    /**
     * Sobrecarga del operador de consulta
     *
     * Permite acceder a los elementos del map que hay en nuestra clase
     * @param val Carácter a consultar
     * @return Estructura de tipo LetterInfo con la información del carácter consultado: Número de repeticiones y
     * puntuación
     */
    const LetterInfo & operator[](const char val) const;

    /**
     * @brief Sobrecarga del operador de salida
     * @param os Flujo de salida, donde escribir el LettersSet
     * @param cl LettersSet que se escribe
     * @return Referencia al flujo, para poder encadenar
     */
    friend ostream & operator<<(ostream & os, const LettersSet & cl);

    /**
     * @brief Sobrecarga del operador de entrada
     * @param is Flujo de entrada, del que leer el LettersSet
     * @param cl LettersSet en el que almacenar la información leida
     * @return Referencia al flujo, para poder encadenar
     */
    friend istream & operator>>(istream & is, LettersSet & cl);

    iterator begin() {
        iterator i= letters.begin();
        return i;
    }
    iterator end() {
        iterator i= letters.end();
        return i;
    }
};
#endif
