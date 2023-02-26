#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int inf, sup;
    int fd1[2];
    int fd2[2];
    pid_t pid1, pid2;
    char buf[6];

    // Procesamiento de los argumentos del programa
    if (argc != 3)
    {
        printf("Error. Número incorrecto de argumentos\n");
        exit(-1);
    }
    else
    {
        inf = strtol(argv[1], NULL, 10);
        sup = strtol(argv[2], NULL, 10);
    }

    // creacion de los pipes
    pipe(fd1);
    pipe(fd2);

    // creacion de los procesos hijos
    if ((pid1 = fork()) < 0)
    {
        perror("Error en primer fork()");
        exit(-1);
    }
    if ((pid2 = fork()) < 0)
    {
        perror("Error en segundo fork");
        exit(-1);
    }

    if (pid1 == 0) // primer esclavo
    {
        close(fd2[0]);
        close(fd2[1]);
        close(fd1[0]);  // cerrar descriptor de lectura
        dup2(fd1[1], STDOUT_FILENO);    // duplicar descriptor de escritura en la salida estandar
        char *aux1, *aux2;
        sprintf(aux1, "%d", inf);
        sprintf(aux2, "%d", (inf + sup)/2);
        execlp("./esclavo", "esclavo", aux1, aux2, NULL);
    }
    if (pid2 == 0) // segundo esclavo
    {
        close(fd1[0]);
        close(fd1[1]);
        close(fd2[0]);  // cerrar descriptor de lectura
        dup2(fd2[1], STDOUT_FILENO);    // duplicar descriptor de escritura en la salida estandar
        char *aux1, *aux2;
        sprintf(aux1, "%d", (inf + sup)/2 + 1);
        sprintf(aux2, "%d", sup);
        execlp("./esclavo", "esclavo", aux1, aux2, NULL);
    }
    int valor;
    if (pid1 != 0 && pid2 != 0) // maestro
    {
        close(fd1[0]);
        close(fd2[0]);

        while (read(STDIN_FILENO, &valor, sizeof(int)) != 0)
        {
            if (write(STDOUT_FILENO, &valor, sizeof(int)) < 0)
            {
                perror("Error en write");
                exit(-1);
            }
        }
    }



    return 0;
}