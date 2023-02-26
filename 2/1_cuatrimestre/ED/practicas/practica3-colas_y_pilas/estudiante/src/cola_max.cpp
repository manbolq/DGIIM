/**
 * @file cola_max.cpp
 * @brief  Archivo de implementación del programa cola con máximo
 * @author
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "maxqueue.h"

using namespace std;

int main(int argc, char *argv[]){

     // Run the current exercise
     MaxQueue queue;

     for(int i = 1; i < argc; i++){
         if (argv[i][0] == '.'){
             cout << queue.front() << endl;
             queue.pop();
         } else {
             queue.push(atoi(argv[i]));
         }
     }
     return 0;
}
