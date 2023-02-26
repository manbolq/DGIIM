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

pid_t *pids;
int *num_reg;
int count = 0;
int se_puede = 1;


int funcion_hijo(int n_count, const char *path)
{
    if (pids[n_count] == 0) // hijo
    {
        // muestra su PID y el de su padre
        printf("Soy un hijo, y mi PID es: %d\n", getpid());
        printf("El PID de mi padre es: %d\n", getppid());

        DIR * direct;
        direct = opendir(path);
        struct dirent *ed;
        struct stat atributos;
        int tam = 0, num_reg_aux = 0;

        // recorremos la carpeta
        while ( (ed = readdir(direct)) != 0)
        {
            char *cadena = NULL;
            sprintf(cadena, "%s/%s", path, ed->d_name);

            // obtenemos los atributos del archivo
            if (stat(cadena, &atributos) < 0)
            {
                perror("Error en stat");
                exit(-1);
            }
            else
            {
                if (S_ISREG(atributos.st_mode)) // si es un archivo regular
                {
                    tam += atributos.st_size;
                    num_reg_aux++;
                }
            }
        }
        printf("Directorio: %s. Suma de tamaños: %d\n", path, tam);
        return num_reg_aux > 255 ? 255 : num_reg_aux;
    }
}


int crea_hijo(const char * path, const struct stat* stat, int flags, struct FTW* ftw)
{
    se_puede = 1;
    for (int i = 0; i < count && se_puede; i++)
        if (pids[i] == 0) se_puede = 0;

    if ( (flags == FTW_D) && (strcmp(path, ".") != 0) && (strcmp(path, "..") != 0) && se_puede)
    {
        pids[count] = fork();
        count++;
        num_reg[count] = funcion_hijo(count, path);
    }
    return 0;
}



int main(int argc, char *argv[])
{
    char *pathname;

    if (argc != 2)
    {
        printf("Error en los argumentos. Sintaxis: ./recorrer <ruta_directorio>\n");
        exit(-1);
    }

    pathname = argv[1];

    // muestra su pid y el pid de su padre
    printf("Mi PID es: %d\n", getpid());
    printf("El PID de mi padre es: %d\n", getppid());



    if (nftw(pathname, crea_hijo, 10, 0) != 0)
        perror("Error en nftw");

    int es_padre = 1;
    for (int i = 0; i < count && es_padre; i++)
    {
        if (pids[i] == 0)
            es_padre = 0;
    }

    int pid;
    if (es_padre)
    {
        while ((pid = wait(NULL)) > 0)
        {
            int aux;
            for (int i = 0; i < count; i++)
                if (pids[i] == pid) aux = i;
            printf("Ha muerto el hijo %d\n", pid);
            printf("Ha devuelto el numero %d\n", num_reg[aux]);
        }


    }



    return 0;
}