#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int minimum(vector<int> &, vector<int>::iterator &);
int totalContainers(vector<int> &, int &);


int main(int argc, char *argv[]){
    const int CAPACITY = 100;
    vector<int> weights;
    int total_containers = 0;

    /***************** LECTURA DE DATOS ***************/
    if (argc != 2){
        cout << "Error en el numero de argumentos: introducir un fichero" << endl;
        exit(1);
    }
    else{
        ifstream file(argv[1]);
        if (!file){
            cout << "Error al abrir el archivo" << endl;
            exit(1);
        }
        int aux = 0;
        while (file >> aux)
            weights.push_back(aux);
    }
    /**************************************************/


    int sum = 0;
    bool stop = false;

    sort(weights.begin(),weights.end()) ;       //O(nlogn)
    vector<int>::iterator it = weights.begin();

    while (it != weights.end() && !stop) {  //O(n)

        int min = *it ;

        if (sum+min <= CAPACITY) {
            sum += min ;
            total_containers++;
            ++it ;
        }
        else
            stop = true ;

    }

    cout << "Contenedores cargados: " << total_containers << endl;


    return 0;
}

// funcion que halla el minimo de un vector, y almacena en aux_it el iterador correspondiente a esa posicion

int minimum(vector<int> & vect, vector<int>::iterator & aux_it){
    int min = vect.at(0);
    for (auto it = vect.begin(); it != vect.end(); ++it){
        if (*it < min){
            min = *it;
            aux_it = it;
        }
    }

    return min;
}


