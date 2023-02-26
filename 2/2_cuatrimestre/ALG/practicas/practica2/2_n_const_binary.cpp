#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

// Genera un nÚmero uniformemente distribuido en el intervalo [0,1) a partir de 
// uno de los generadores disponibles en C. 
double uniforme() 
{
    int t = rand();
    double f = ((double)RAND_MAX+1.0);
    return (double)t/f;
}

//                               GENERADOR DE VECTORES 
// Para obtener k vectores ordenados de forma creciente cada uno con n elementos, 
// genera un vector de tamaño k*n con todos los enteros entre 0 y kn-1 ordenados. 
// Se lanzan entonces k iteraciones de un algoritmo de muestreo aleatorio de 
// tamaño n para obtener los k vectores. Están ordeados porque el algoritmo de 
// muestreo mantiene el orden
void genera (vector<vector<int>> &myvector, int k, int n) {

    myvector.clear() ;
    int **T;
    T =  new int * [k];
    assert(T);

    for (int i = 0; i < k; i++)
        T[i]= new int [n];

    int N=k*n;
    int * aux = new int[N];
    assert(aux);

    
    //genero todos los enteros entre 0 y k*n-1
    for (int j=0; j<N; j++) aux[j]=j;

    //para cada uno de los k vectores se lanza el algoritmo S (sampling) de Knuth
    for (int i=0; i<k; i++) {

        int t=0;
        int m=0;

        while (m<n) {
            double u=uniforme();
            if ((N-t)*u >= (n-m)) t++;
            else {
                T[i][m]=aux[t];
                t++;
                m++;
            }
        }
    }


    for (int i=0; i<k; i++) 
        myvector.push_back(vector<int> (T[i],T[i]+n)) ;

    delete [] T ;
    delete [] aux;
    

}


/****************************************************************************/
/******************************ALGORITMO BÁSICO******************************/
/****************************************************************************/

void merge_basic (int l, const vector<int> &r, vector<int> &output) {

    int n = r.size() ;
    vector<int> copy_l ;

    for (int i=0 ; i<l ; i++) 
        copy_l.push_back(output[i]) ;

    // Se almacena el índice actual en el array izquierdo y derecho
    int l_curr = 0, r_curr = 0;
 
    // Índice actual en el array de salida
    int in = 0;
 
    // Mezcla de l_arr y r_arr, que se almacena en output
    while (l_curr + r_curr < l + n) {

        if (r_curr == n || (l_curr != l && copy_l[l_curr] < r[r_curr])) {
            output[in] = copy_l[l_curr];
            l_curr++ ;
            in++;
        }
        else {
            output[in] = r[r_curr] ;
            r_curr++ ; 
            in++ ;
        }
    }



}


void knvector_basic (const vector<vector<int>> &arr, vector<int> &output) {

    // Primer índice en el que se puede escribir en output
    int index_output = 0 ;
    int n = arr[0].size() ;

    for (auto it=arr.begin(); it != arr.end(); ++it) {

        merge_basic (index_output, *it, output) ;
        index_output += n ;
    }



}


/****************************************************************************/
/******************************DIVIDE Y VENCERÁS*****************************/
/****************************************************************************/


// Mezcla la mitad l (un vector) con la mitad r (un vector) de output
void merge(int n, int l, int r, vector<int>& output)
{
    // comiendo del array izquierdo y comienzo del array derecho en output
    int l_in = l * n ;
    int r_in = ((l + r) / 2 + 1) * n ;
 
    // Tamaño del array izquierdo y derecho, respectivamente
    int l_c = ((l + r) / 2 - l + 1) * n;
    int r_c = (r - (l + r) / 2) * n;
 
    // Arrays temporales para almacenar mitad izquierda y derecha
    int l_arr[l_c], r_arr[r_c];
 
    // Se copia de output la mitad izquierdo
    for (int i = 0; i < l_c; i++)
        l_arr[i] = output[l_in + i];
 
    // Se copia de output la mitad derecha
    for (int i = 0; i < r_c; i++)
        r_arr[i] = output[r_in + i];
 
    // Se almacena el índice actual en el array izquierdo y derecho
    int l_curr = 0, r_curr = 0;
 
    // Índice actual en el array de salida
    int in = l_in;
 
    // Mezcla de l_arr y r_arr, que se almacena en output
    while (l_curr + r_curr < l_c + r_c) {

        if (r_curr == r_c || (l_curr != l_c && l_arr[l_curr] < r_arr[r_curr])) {
            output[in] = l_arr[l_curr];
            l_curr++ ;
            in++;
        }
        else {
            output[in] = r_arr[r_curr] ;
            r_curr++ ; 
            in++ ;
        }
    }
}
 

// ALGORITMO 2: divide en dos partes iguales los k vectores (cada una con
// k/2 vectores), y cada mitad se vuelve a dividir en dos mitades hasta que solo 
// quedan dos vectores, que se mezclan de forma ordenada. Dicha mezcla se le 
// aplica a cada partición de dos vectores. (DIVIDE Y VENCERÁS)
void divide(int l, int r, vector<int>& output,const vector<vector<int>> &arr)
{
    int n = arr[0].size() ;

    if (l == r) {
 
        // Cuando solo queda un vector en la partición, se escribe en output 
        for (int i = 0; i < n; i++)
            output[l * n + i] = arr[l][i];
 
        return;
    }
 
    // Mitad izquierda
    divide(l, (l + r) / 2,
           output, arr);
 
    // Mitad derecha
    divide((l + r) / 2 + 1, r,
           output, arr);
 
    // Mezcla la mitad izquierda y la mitad derecha
    merge(n, l, r, output);
}


/****************************************************************************/
/*********************************EFICIENCIA*********************************/
/****************************************************************************/

void eficiencia (int k, int n) {

    vector<vector<int>> myvector ;
    genera (myvector,k,n) ;
    vector<int> output (n*k);

    clock_t tantes ;
    clock_t tdespues ;

    tantes = clock () ;

    //*******************************ALGORITMO******************************//
 
    divide(0, k - 1, output, myvector);
    // knvector_basic (myvector, output) ;

    //**********************************************************************//

    tdespues = clock() ;

    cout << n << "\t" << ((double)(tdespues - tantes)) / CLOCKS_PER_SEC  << endl ;

}


/****************************************************************************/
/*************************************MAIN***********************************/
/****************************************************************************/
int main(int argc, char * argv[])
{
    srand(time(0));

    const int INICIO       = 200 ;
    const int FIN          = 10200 ;
    const int INCREMENTO   = 200 ;
    const int REPETICIONES = 15 ;

    /******************************************/

    cout << "NVECTOR" << "\t" << "ELAPSED" << endl ;

    // Una de las dos será constante
    // const int k = 30 ;
    const int n = 20 ;
    

    for (int i=INICIO ; i <= FIN ; i += INCREMENTO ) 
        for (int j=0 ; j<15 ; j++)
            eficiencia (i,n) ; 

    /******************************************/

    return 0;

}



/* PARA MOSTRAR RESULTADOS
/*

    for (auto it = myvector.begin(); it != myvector.end(); ++it)
        for (auto it2 =  (*it).begin(); it2 != (*it).end(); ++it2) 
            cout << *it2 << endl ;

*/