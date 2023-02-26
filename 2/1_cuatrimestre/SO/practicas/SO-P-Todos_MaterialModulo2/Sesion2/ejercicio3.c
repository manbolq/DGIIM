#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<dirent.h>


DIR *direct;
char cadena[300];
struct stat atributos;
int tam = 0;
int num_x = 0;
struct dirent *ed;

void busca(char *path);


int main(int argc, char *argv[])
{
    char *pathname;

    if (argc == 1)
        pathname = ".";
    else if (argc == 2){
        pathname = argv[1];
    }
    else{
        printf("\nSintaxis de ejecucion: ejercicio3 <pathname>\n\n");
        exit(-1);
    }

    printf("\nLos i-nodos son:\n");
    busca(pathname);
    printf("\n");
    printf("Existen %d archivos regulares con permiso x para grupo y otros\n", num_x);
    printf("El tamaño total ocupado por dichos archivos es %d bytes\n", tam);

    return 0;
}


void busca(char *path)
{
	direct = opendir(path);

	if (direct == NULL){
		printf("No se ha podido abrir el directorio");
		exit(-1);
	}
	while ((ed = readdir(direct)) != 0)
	{
		sprintf(cadena,"%s/%s", path, ed->d_name);
		if (stat(cadena, &atributos) < 0)
	        {
                perror("\nError en stat");
                exit(-1);
       		}
        	else
        	{
                if (S_ISREG(atributos.st_mode))
                {
                    printf("%s %ld\n", cadena, ed->d_ino);
                    if (0 < (atributos.st_mode & S_IXGRP & S_IXOTH))
                    {
                        num_x += 1;
                        tam += atributos.st_size;
                    }
                }
//                	else if (S_ISDIR(atributos.st_mode))
//                	{
//                		busca(cadena);
//                	}
        	}
	}

}





