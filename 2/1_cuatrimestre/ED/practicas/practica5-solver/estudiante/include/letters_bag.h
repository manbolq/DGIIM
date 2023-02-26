/**
 * @file letters_bag.h
 * @brief  Archivo de especificación del TDA LettersBag
 */

#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include "bag.h"
#include "letters_set.h"

/**
 * @brief TDA LettersBag
 *
 * Este TDA almacena un conjunto de chars utilizado en el juego de letras.
 * La estructura de datos subyacente es una lista de chars.
 */

class LettersBag{
private:
    /**
     * @brief almacena las letras que se utilizaran en el juego
     */
    Bag <char> letters;
public:
    /**
     * @brief Constructor por defecto
     */
     LettersBag();

    /**
     * @brief Constructor dado un LettersSet
     *
     * Dado un LettersSet como argumento, el consturctor rellena LettersBag con las letras que contiene
     * el LettersSet, introduciendo cada letra el número de veces indicado por el campo LetterInfo::repetitions.
     * @param letterSet TDA LettersSet que se usará para construir LettersBag
     */
    LettersBag(LettersSet & letterSet);

    /**
     * @brief Introduce una letra en la bolsa
     * @param l letra a añadir en LettersBag
     */
    void insertLetter(const char &l);

    /**
     * @brief Extrae una letra aleatoria del conjunto, eliminandola de el
     * @return char que representa la letra extraida
     */
    char extractLetter();

    /**
     * @brief Extrae un conjunto de letras de LettersBag eliminandolas del conjunto
     * @param num Numero de letras a extraer
     * @return Lista con las letras extraidas aleatoriamente
     */
    vector<char> extractLetters(int num);

    /**
     * @brief Elimina todo el contenido de LettersBag
     */
    void clear();

    /**
     * @brief Tamaño de la bolsa
     * @return int con el tamaño de la bolsa
     */
    unsigned int size() const;

    /**
     * @brief Sobrecarga del operador de asignacion
     * @param other LettersBag de la que se tomaran los valores a asignar
     * @return referencia a this para poder encadenar el operador
     */
    LettersBag& operator=(const LettersBag & other);
};
#endif
