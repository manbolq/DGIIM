/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author
 */


#include <stack>
#include <ostream>
using namespace std;


/**
 * @brief Pareja de datos que guarda el valor y el máximo de la cola
 * @param value Almacena el valor
 * @param max Almacena el maximo de la estructura
 */
struct element{
    int value;
    int max;
};

ostream& operator<<(ostream& os, element n);

/**
 * @page Representación de una cola con máximo
 * @brief MaxQueue Implementa los métodos básicos para la gestión de una cola,
 * guardando también el máximo de la cola cuando se extrae algún elemento de esta
 */
class MaxQueue{

private:
    /**
     * @brief Cola que es representada internamente como una pila
     */
    stack<element> queue;

public:
    /**
     * @brief Elimina el primer elemento de la cola
     */
    void pop();

    /**
     * @brief Permite la consulta del primer elemento de la cola
     * @return Primer elemento de la cola
     * @post No extrae el elemento
     */
    element front() const;

    /**
     * @brief Coloca un nuevo elemento en la cola haciendo la gestión del máximo
     * @param value valor del elemento que se coloca
     */
    void push(int value);

    /**
     * @brief Consulta si la cola esta vacia
     * @return true si la cola esta vacía, y false si no lo está
     */
    bool empty() const;

    /**
     * @brief Número de elementos de la cola
     * @return El número de elementos de la cola
     */
    int size() const;
};