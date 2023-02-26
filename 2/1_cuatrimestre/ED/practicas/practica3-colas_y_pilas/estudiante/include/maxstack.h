/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author
 */


#include <queue>
#include <ostream>
using namespace std;


/**
 * @brief Pareja de datos que guarda el valor y el máximo de la cola
 * @param value Almacena el valor
 * @param max Almacena el maximo de la estructura
 */
struct element{
    int value; //almacena el valor
    int max; //almacena el maximo de la estructura
};

ostream& operator<<(ostream& os, element n);


/**
 * @page Representación de una pila con máximo
 * @brief MaxQueue Implementa los métodos básicos para la gestión de una pila,
 * guardando también el máximo de la pila cuando se extrae algún elemento de esta
 */
class MaxStack{
private:

    /**
     * @brief Pila, representada internamente como una cola
     */
    queue<element> stack;

public:

    /**
     * @brief Inserta un elemento en la pila haciendo la gestión del máximo
     * @param valor valor del elemento que se inserta
     */
    void push(int valor);

    /**
     * @brief Consulta el elemento en la parte superior de la pila
     * @return El elemento en la parte superior de la pila
     * @post No extrae el elemento
     */
    element top() const;

    /**
     * @brief Extrae el elemento en la parte superior de la pila
     */
    void pop();

    /**
     * @brief Consulta el tamaño de la pila
     * @return El tamaño de la pila
     */
    int size() const;

    /**
     * @brief Consulta si la pila esta vacia
     * @return true si la pila esta vacia, y false si no lo está
     */
    bool empty() const;
};
