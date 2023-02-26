// Fichero: icono.cpp
// Crea un icono a partir de una imagen
//

#include <iostream>
#include <cstdlib>

#include <image.h>

using namespace std;

int main(int argc, char *argv[]){
    char *origen, *destino; // nombres de los ficheros
    int factor;
    Image image;

    // Comprobar validez de la llamada
    if (argc != 4){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: icono <FichImagenOriginal> <FichImagenDestino> <factor>\n";
        exit (1);
    }


    // Obtener argumentos
    origen  = argv[1];
    destino = argv[2];
    factor = stoi(argv[3]);

//    string origen_s = "img/vacas.pgm";
//    string destino_s = "./results/icono_pub.pgm";
//
//    for (int i = 0; i < 13; i++)
//        origen[i] = origen_s[i];
//    for (int i = 0; i < 19; i++)
//        destino[i] = destino_s[i];
//    factor = 2;


    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << origen << endl;
    cout << "Fichero resultado: " << destino << endl;
    cout << "Factor de reduccion: " << factor << endl;

    // Leer la imagen del fichero de entrada
    if (!image.Load(origen)){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    // Mostrar los parametros de la Imagen
    cout << endl;
    cout << "Dimensiones de " << origen << ":" << endl;
    cout << "   Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;


    // Generar el icono
    Image icono(image.Subsample(factor));


    // Guardar la imagen resultado en el fichero
    if (!icono.Save(destino)){
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }
    else{
        cout << endl;
        cout  << "La imagen se guardo en " << destino << endl;
    }


    return 0;
}