/**
 *   @file solver.h
 *   @brief Archivo de especificación del TDA solver
 */
#include "dictionary.h"
#include "letters_set.h"
#include <vector>

using namespace std;
/**
 * @brief TDA solver
 * @details Ofrece soluciones para el juego de las letras
 */
class Solver{
private:
    /**
     * @brief dictionario que nos dirá las palabras que podemos formar
     */
    Dictionary d;
    /**
     * @brief contiene la información de las letras para poder resolver el problema
     */
    LettersSet l;

public:
    /**
     * @brief Constuctor con parámetros
     * @param dict objeto del TDA dictionary asociado al solver
     * @param letters_set objeto del TDA LettersSet asociado al solver
     * @details Complejidad computacional: O(n)
     */
    Solver(const Dictionary & dict, const LettersSet & letters_set);

    /**
     * @brief Construye un vector con las soluciones al juego.
     *
     * Dado un conjunto de letras posibles para crear una solución, y el modo de juego con el que se va a jugar la partida
     * se construye el vector con las mejores soluciones en función del juego planteado
     * @param available_letters Vector de letras disponibles para la partida
     * @param score_game Bool que indica el tipo de partida. True indica que se juega a puntuación, false a longitud.
     * @return Pair<vector<string>, int> con el vector de palabras que son solución y la puntuación que obtienen.
     * @details Complejidad computacional: O(n^3)
     */
    pair<vector<string>,int> getSolutions(const vector<char> & available_letters, bool score_game);

private:
    /**
     * @brief función auxiliar que nos dice si podemos formar una palabra con las letras disponibles
     * @param word palabra que queremos formar
     * @param letters letras disponibles para formar la palabre
     * @return true si podemos formar la palabra, false en caso contrario
     * @pos el vector se modifica
     * @details Complejidad computacional: O(n^2)
     */
    bool formable(string word, vector<char> & letters);

    /**
     * @brief Metodo auxiliar que resuelve la partida por puntuación
     * @param available_letters letras disponibles para formar palabras
     * @return pair formado por las soluciones y su puntuación
     * @details Complejidad computacional: O(n^2)
     */
    pair<vector<string>,int> getSolutionsScore(const vector<char> & available_letters);

    /**
    * @brief Metodo auxiliar que resuelve la partida por longitud
    * @param available_letters letras disponibles para formar palabras
    * @return pair formado por las soluciones y su puntuación
    * @details Complejidad computacional: O(n^2)
    */
    pair<vector<string>,int> getSolutionsLength(const vector<char> & available_letters);

};