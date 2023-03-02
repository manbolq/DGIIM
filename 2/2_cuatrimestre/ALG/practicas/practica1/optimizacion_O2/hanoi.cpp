/**
   @file Resolución del problema de las Torres de Hanoi
*/

   
#include <iostream>
using namespace std;
#include <ctime>


/**
   @brief Resuelve el problema de las Torres de Hanoi
   @param M: número de discos. M > 1.
   @param i: número de columna en que están los discos.
             i es un valor de {1, 2, 3}. i != j.
   @param j: número de columna a que se llevan los discos.
             j es un valor de {1, 2, 3}. j != i.

   Esta función imprime en la salida estándar la secuencia de 
   movimientos necesarios para desplazar los M discos de la
   columna i a la j, observando la restricción de que ningún
   disco se puede situar sobre otro de tamaño menor. Utiliza
   una única columna auxiliar.
*/
void hanoi (int M, int i, int j);




void hanoi (int M, int i, int j)
{
  if (M > 0)
    {
      hanoi(M-1, i, 6-i-j);
      hanoi (M-1, 6-i-j, j);
  }
}


void eficiencia (int n) {

  clock_t tantes ;
  clock_t tdespues ;



  if (n <= 15) {
    tantes = clock () ;
    for (int i=0; i<100000; i++)
        hanoi(n,1,2) ;
    tdespues = clock() ;

  }
  else {
    tantes = clock() * 100000 ;
    hanoi(n,1,2) ;
    tdespues = clock() * 100000 ;

  }

   cout << n << "\t" << ((double)(tdespues - tantes)) / CLOCKS_PER_SEC  << endl;

}

	

int main()
{
    srandom(time(0));

    const int INICIO       = 1 ;
    const int FIN          = 26 ;
    const int INCREMENTO   = 1 ;
    const int REPETICIONES = 15 ;

    /******************************************/

    cout << "NDISKS" << "\t" << "ELAPSED" << endl ;

    for (int i=INICIO ; i <= FIN ; i += INCREMENTO ) 
      for (int j=0 ; j<REPETICIONES ; j++)
        eficiencia (i) ;

    /******************************************/

    return 0;
};