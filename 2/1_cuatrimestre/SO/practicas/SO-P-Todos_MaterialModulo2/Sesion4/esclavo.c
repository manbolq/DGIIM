#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<math.h>
#include <string.h>

int main(int argc, char *argv[])
{
    printf("EJECUCION ESCLAVO\n");
    int inf, sup;
    int prime = 1;

    if (argc != 3)
    {
        printf("Error. Número de parámetros incorrecto\n");
        exit(-1);
    }
    else
    {
        inf = strtol(argv[1], NULL, 10);
        sup = strtol(argv[2], NULL, 10);
    }

    for (int num = inf; num <= sup; num++)
    {
        prime = 1;
        for (int i = 2; i <= sqrt(num) && prime; i++)
        {
            if (num%i == 0) prime = 0;
        }
        if (prime)
        {
            printf("LLEGA\n");
            if (write(STDOUT_FILENO, &num, sizeof(int)) < 0)
            {
                perror("Error en write");
                exit(-1);
            }
        }
    }

    return 0;
}
