#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
pid_t pid;
int bg;
char **argv2;

if (argc < 2)
{
	printf("Error. Número incorrento de argumentos\n");
	exit(-1);
}
else if ((strcmp(argv[argc-1], "bg")) == 0){

	printf("HOLA\n");
	bg = 1;
	for (int i = 0; i < argc - 3; i++)
		argv2[i] = argv[i+2];
}
else{
	bg = 0;
	for (int i = 0; i < argc - 2; i++)
		argv2[i] = argv[i+2];
}

if (bg)
{
	printf("***EJECUTANDO EN BACKGROUND***\n");
	pid = fork();
	if (pid == 0) // el hijo
	{
		if( (execl(argv[1], *argv, NULL)) < 0)
		{
			perror("\nError en execl con bg\n");
			exit(-1);
		}
		exit(0);
	}
	else // el padre
	{
		wait(NULL);
	}
}
else
{
	printf("***EJECUTANDO EN FOREGROUND***\n");
	if ( (execl(argv[1], *argv, NULL)) < 0)
	{
		perror("\nError en execl sin bg\n");
		exit(-1);
	}
}


return 0;
}
