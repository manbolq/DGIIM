#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
pid_t pid;
pid_t pid2;
int numero;
if (argc != 2){
	printf("Error parámetros");
	exit(-1);
}
numero = strtol(argv[1], NULL, 10);

pid = fork();
int hola = 2;
if (pid == 0){
	pid2 = fork();
	if (pid2 == 0)
		(numero % 3 == 0) ? printf("Hijo2. ES DIVISIBLE POR 3\n") : printf("Hijo2. NO ES DIVISIBLE POR 3\n");
	else{
		(numero % 2 == 0) ? printf("Hijo. ES PAR\n") : printf("Hijo. ES IMPAR\n");
		printf("HOLA");
	}

}
else{
	(numero % 4 == 0) ? printf("Padre. ES DIVISIBLE POR 4\n") : printf("Padre. NO ES DIVISIBLE POR 4\n");
//	printf("%i", hola);
}
return 0;
}
