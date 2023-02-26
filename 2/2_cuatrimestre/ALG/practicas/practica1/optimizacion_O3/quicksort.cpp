



#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>






/* ************************************************************ */ 
/*  Método de ordenación rápida  */

/**
   @brief Ordena un vector por el método quicksort.

   @param T: vector de elementos. Debe tener num_elem elementos.
             Es MODIFICADO.
   @param num_elem: número de elementos. num_elem > 0.

   Cambia el orden de los elementos de T de forma que los dispone
   en sentido creciente de menor a mayor.
   Aplica el algoritmo quicksort.
*/
inline static 
void quicksort(int T[], int num_elem);



/**
   @brief Ordena parte de un vector por el método quicksort.

   @param T: vector de elementos. Tiene un número de elementos 
                   mayor o igual a final. Es MODIFICADO.
   @param inicial: Posición que marca el incio de la parte del
                   vector a ordenar.
   @param final: Posición detrás de la última de la parte del
                   vector a ordenar. 
		   inicial < final.

   Cambia el orden de los elementos de T entre las posiciones
   inicial y final - 1 de forma que los dispone en sentido creciente
   de menor a mayor.
   Aplica el algoritmo quicksort.
*/
static void quicksort_lims(int T[], int inicial, int final);


/**
   @brief Ordena un vector por el método de inserción.

   @param T: vector de elementos. Debe tener num_elem elementos.
             Es MODIFICADO.
   @param num_elem: número de elementos. num_elem > 0.

   Cambia el orden de los elementos de T de forma que los dispone
   en sentido creciente de menor a mayor.
   Aplica el algoritmo de inserción.
*/
inline static 
void insercion(int T[], int num_elem);


/**
   @brief Ordena parte de un vector por el método de inserción.

   @param T: vector de elementos. Tiene un número de elementos 
                   mayor o igual a final. Es MODIFICADO.
   @param inicial: Posición que marca el incio de la parte del
                   vector a ordenar.
   @param final: Posición detrás de la última de la parte del
                   vector a ordenar. 
		   inicial < final.

   Cambia el orden de los elementos de T entre las posiciones
   inicial y final - 1 de forma que los dispone en sentido creciente
   de menor a mayor.
   Aplica el algoritmo de inserción.
*/
static void insercion_lims(int T[], int inicial, int final);


/**
   @brief Redistribuye los elementos de un vector según un pivote.

   @param T: vector de elementos. Tiene un número de elementos 
                   mayor o igual a final. Es MODIFICADO.
   @param inicial: Posición que marca el incio de la parte del
                   vector a ordenar.
   @param final: Posición detrás de la última de la parte del
                   vector a ordenar. 
		   inicial < final.
   @param pp: Posición del pivote. Es MODIFICADO.

   Selecciona un pivote los elementos de T situados en las posiciones
   entre inicial y final - 1. Redistribuye los elementos, situando los
   menores que el pivote a su izquierda, después los iguales y a la
   derecha los mayores. La posición del pivote se devuelve en pp.
*/
static void dividir_qs(int T[], int inicial, int final, int & pp);

/* ************************************************************ */ 
/*  Método de ordenación por montones  */

/**
   @brief Ordena un vector por el método de montones.

   @param T: vector de elementos. Debe tener num_elem elementos.
             Es MODIFICADO.
   @param num_elem: número de elementos. num_elem > 0.

   Cambia el orden de los elementos de T de forma que los dispone
   en sentido creciente de menor a mayor.
   Aplica el algoritmo de ordenación por montones.
*/
inline static 
void heapsort(int T[], int num_elem);



/**
   @brief Reajusta parte de un vector para que sea un montón.

   @param T: vector de elementos. Debe tener num_elem elementos.
             Es MODIFICADO.
   @param num_elem: número de elementos. num_elem > 0.
   @param k: índice del elemento que se toma com raíz
   
   Reajusta los elementos entre las posiciones k y num_elem - 1 
   de T para que cumpla la propiedad de un montón (APO), 
   considerando al elemento en la posición k como la raíz.
*/
static void reajustar(int T[], int num_elem, int k);




/**
   Implementación de las funciones
**/


static void heapsort(int T[], int num_elem)
{
  int i;
  for (i = num_elem/2; i >= 0; i--)
    reajustar(T, num_elem, i);
  for (i = num_elem - 1; i >= 1; i--)
    {
      int aux = T[0];
      T[0] = T[i];
      T[i] = aux;
      reajustar(T, i, 0);
    }
}
  

static void reajustar(int T[], int num_elem, int k)
{
  int j;
  int v;
  v = T[k];
  bool esAPO = false;
  while ((k < num_elem/2) && !esAPO)
    {
      j = k + k + 1;
      if ((j < (num_elem - 1)) && (T[j] < T[j+1]))
	j++;
      if (v >= T[j])
	esAPO = true;
      T[k] = T[j];
      k = j;
    }
  T[k] = v;
}

/**
   Implementación de las funciones
**/


inline static void insercion(int T[], int num_elem)
{
  insercion_lims(T, 0, num_elem);
}


static void insercion_lims(int T[], int inicial, int final)
{
  int i, j;
  int aux;
  for (i = inicial + 1; i < final; i++) {
    j = i;
    while ((T[j] < T[j-1]) && (j > 0)) {
      aux = T[j];
      T[j] = T[j-1];
      T[j-1] = aux;
      j--;
    };
  };
}


const int UMBRAL_QS = 50;


inline void quicksort(int T[], int num_elem)
{
  quicksort_lims(T, 0, num_elem);
}

static void quicksort_lims(int T[], int inicial, int final)
{
  int k;
  if (final - inicial < UMBRAL_QS) {
    insercion_lims(T, inicial, final);
  } else {
    dividir_qs(T, inicial, final, k);
    quicksort_lims(T, inicial, k);
    quicksort_lims(T, k + 1, final);
  };
}


static void dividir_qs(int T[], int inicial, int final, int & pp)
{
  int pivote, aux;
  int k, l;

  pivote = T[inicial];
  k = inicial;
  l = final;
  do {
    k++;
  } while ((T[k] <= pivote) && (k < final-1));
  do {
    l--;
  } while (T[l] > pivote);
  while (k < l) {
    aux = T[k];
    T[k] = T[l];
    T[l] = aux;
    do k++; while (T[k] <= pivote);
    do l--; while (T[l] > pivote);
  };
  aux = T[inicial];
  T[inicial] = T[l];
  T[l] = aux;
  pp = l;
};









void eficiencia (int n) {

  int * T = new int[n];
  assert(T);

  for (int i = 0; i < n; i++)
  {
    T[i] = random();
  };

  clock_t tantes ;
  clock_t tdespues ;

  tantes = clock () ;

  // Si se quiere hacer quicksort / heapsort solo cambiar esto
  quicksort(T, n);

  tdespues = clock() ;

  cout << n << "\t" << ((double)(tdespues - tantes)) / CLOCKS_PER_SEC  << endl ;

  delete [] T;

}



int main()
{
    srandom(time(0));

    const int INICIO     = 100000 ;
    const int FIN        = 12600000 ;
    const int INCREMENTO = 500000 ;
    const int REPETICIONES = 15 ;

    /******************************************/

    cout << "NVECTOR" << "\t" << "ELAPSED" << endl ;

    for (int i=INICIO ; i <= FIN ; i += INCREMENTO ) 
      for (int j=0 ; j<REPETICIONES ; j++)
        eficiencia (i) ;

    /******************************************/

    return 0;
};