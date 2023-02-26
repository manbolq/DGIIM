// Nombre del programa: buscar.c
// Nombre: Manuel Vicente Bolaños Quesada
// DNI: 77688712W
// 20/12/2021

#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <ftw.h>
#include <dirent.h>

char *cadena;
#define MAX 125 // maximo para los arrays

int busca(const char* path, const struct stat* stat, int flags, struct FTW* ftw)
{

    int pos_ultima_barra;
    if ( (flags == FTW_F) && (stat->st_mode & S_IXUSR)){ // si es regular, y si tiene permiso de ejecucion para el usuario

        // buscamos la ultima aparicion de la barra en path
        for (int i = 0; path[i] != '\0'; i++){
            if (path[i] == '/'){
                pos_ultima_barra = i;
            }
        }

        // en direct_name se va a almacenar el directorio del fichero que se esta analizando
        char direct_name[MAX] = {""};
        for (int i = 0; i <= pos_ultima_barra; i++){
            direct_name[i] = path[i];
        }

        // en cadena_extendida sse va a almacenar la ruta de direct_name mas la cadena al final, para poder comparar
        // las dos cadenas
        char cadena_extendida[MAX] = {""};
        for (int i = 0; i < MAX; i++)
            cadena_extendida[i] = direct_name[i];
        strcat(cadena_extendida, cadena);

        // comparamos que el nombre del archivo comience por la cadena "cadena"
        // dividimos por 4 para obtener la longitud real de la cadena
        if (strncmp(cadena_extendida, path, pos_ultima_barra + 1 + sizeof(cadena)/4) == 0){ // si path empieza por la misma cadena que "cadena"
            printf("%s\n", path);
        }

    }

    return 0;
}

int main(int argc, char *argv[])
{
    // Comprobacion correcto uso del programa
    if (argc != 3){
        printf("Numero incorrecto de parametros.\n");
        printf("Sintaxis: ./buscar <cadena> <ruta_directorio>\n");
        exit(-1);
    }

    char *directorio;
    cadena = argv[1];
    directorio = argv[2];

    if (nftw(directorio, busca, 10, 0) != 0){ // recorre recursivamente el arbol de directorios dado por "directorio"
        perror("Error en nftw"); // comprobacion de errores
        exit(-1);
    }


    return 0;
}

