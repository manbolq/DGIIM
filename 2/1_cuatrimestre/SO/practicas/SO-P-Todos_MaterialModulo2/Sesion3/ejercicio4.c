#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
pid_t pid;
int nprocs = 5;
int cpid;

for (int i = 0; i < nprocs; i++)
{
	pid = fork();

	if (pid == 0)
	{
		printf("Soy el hijo %i\n", getpid());
		break;
	}
	else if (pid < 0)
	{
		perror("Error en fork\n");
		exit(1);
	}
}

if (pid != 0) // padre
{
	sleep(1);
	for (int i = 0; i < nprocs; i++)
	{
		if ((cpid = wait(NULL)) >= 0)
		{
		        printf("Acaba de finalizar mi hijo con %i\n", cpid);
		        printf("Solo me quedan %i hijos\n", nprocs -i -1);
		}
	}
}


return 0;
}
