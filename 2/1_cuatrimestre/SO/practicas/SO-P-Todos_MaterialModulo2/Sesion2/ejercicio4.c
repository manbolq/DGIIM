#include<libgen.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include <ftw.h>



int tam = 0;
int num_x = 0;
int busca(const char *path, const struct stat *stat, int flags, struct FTW* ftw)
{
	if (flags == FTW_F)
	{
		printf("%s %li \n", path, stat->st_ino);
		if (0 < (stat->st_mode & S_IXGRP) & S_IXOTH)
		{
			num_x += 1;
			tam += stat->st_size;
		}
	}
	else if (flags == FTW_D)
	{
	printf("El directorio %s %li contiene:", path, stat->st_ino);
	}
}

int main(int argc, char *argv[])
{
printf("Los i-nodos son:\n");
if (nftw(argc == 2 ?  argv[1] : ".", busca, 10, 0) != 0)
	perror("nftw");

printf("Existen %d archivos regulares con permiso x para grupo y otros\n", num_x);
printf("El tamaño total ocupado por dichos archivos es %d bytes\n", tam);

return 0;
}
