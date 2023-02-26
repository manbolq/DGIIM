#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int fd;
	int fd2;

	fd2 = open("salida.txt", O_CREAT|O_WRONLY, 0700);
	char buf[80];

	if (argc != 2){
		fd = 0;
	}
	else{
		if ( (fd = open(argv[1], O_RDONLY)) < 0 ){
			printf("\nError %d en open",errno);
			perror("\nError en open");
			exit(-1);
		}
	}

	int i = 0, aux = 0;

	do{
		i += 1;
		if ((aux = read(fd, buf, 80)) < 0){
			perror ("\nErorr en read");
			exit(-1);
		}else{
			char titulo[] = "Bloque ";
			char numero[1];
			sprintf(numero, "%d", i);
			strcat(titulo, numero);
			strcat(titulo, "\n");

			write(fd2, titulo, strlen(titulo));
			if (write(fd2, buf, strlen(buf)) < 0){
				perror ("\nError en write");
				exit(-1);
			}
		}

	}while(1 <= aux && aux <= 80);

	return 0;
}
