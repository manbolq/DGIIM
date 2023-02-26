#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<dirent.h>

int main(int argc, char *argv[])
{

if (argc != 3)
{
	printf("\nSintaxis de ejecucion: ejercicio2 <RutaDirectorio> <NumeroOctal> \n\n");
	exit(-1);
}
else
{
	char *pathname = argv[1];
	int number;
	char *pEnd;
	number = strtol(argv[2], &pEnd, 8);

	DIR directorio = opendir(pathname);


}




return 0;
}
