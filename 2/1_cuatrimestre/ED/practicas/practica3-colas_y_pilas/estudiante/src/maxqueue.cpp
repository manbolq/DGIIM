/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author
 */

#include<maxqueue.h>

ostream& operator<<(ostream& os, element n){
    os << n.value << "," << n.max;
    return os;
}

void MaxQueue::pop(){
    queue.pop();
}

element MaxQueue::front() const{
    return queue.top();
}

void MaxQueue::push(int value){

    element n;
    n.value = n.max = value;

    if(size()==0) queue.push(n);

    else{
        stack<element> aux;
        while(!empty()){
            element front = this->front();
            pop();
            if(value > front.max)   front.max = value;

            aux.push(front);
        }
        queue.push(n);
        while(!aux.empty()){
            queue.push(aux.top());
            aux.pop();
        }
    }

}

bool MaxQueue::empty() const{
    return queue.empty();
}

int MaxQueue::size() const{
    return queue.size();
}
