/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * @author
 */

#include <maxstack.h>

ostream& operator<<(ostream& os, element n){
    os << n.value << "," << n.max;
    return os;
}


void MaxStack::push(int valor) {
    element n;
    n.value = valor;
    n.max = valor;

    if (empty()) stack.push(n);

    else{
        queue<element> aux;

        if (valor <= stack.front().max)
            n.max = stack.front().max;

        aux.push(n);

        while (!empty()){
            aux.push(stack.front());
            stack.pop();
        }

        stack = aux;
    }



//    element n;
//    n.value = valor;
//
//    if(stack.size() == 0){
//        n.max = valor;
//        stack.push(n);
//
//    }else {
//        queue<element> aux;
//        n.max = max(stack.front().max, valor);
//        aux.push(n);
//
//        while(!stack.empty()){
//            aux.push(stack.front());
//            stack.pop();
//        }
//        stack = aux;
//    }
}

element MaxStack::top() const {
    return stack.front();
}

void MaxStack::pop() {
    stack.pop();
}

int MaxStack::size() const {
    return stack.size();
}

bool MaxStack::empty() const {
    return stack.empty();
}