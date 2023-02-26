#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
pid_t pids[5];
int nprocs = 5;
int cpid;

for (int i = 0; i < nprocs; i++)
{
        pids[i] = fork();

        if (pids[i] == 0)
        {
                printf("Soy el hijo %i\n", getpid());
                break;
        }
        else if (pids[i] < 0)
        {
                perror("Error en fork\n");
                exit(1);
        }
}

int total_proc = nprocs;
for (int i = 0; i < nprocs; i++)
{

if (pids[i] != 0)
{
        for (int j = 0; j < nprocs; j+=2)
        {
                if ((cpid = waitpid(pids[j], NULL, 0)) >= 0)
                {
                        printf("Acaba de finalizar mi hijo con %i\n", cpid);
                        printf("Solo me quedan %i hijos\n", --total_proc);
                }
        }
	for (int j = 1; j < nprocs; j+=2)
	{
		if ((cpid = waitpid(pids[j], NULL, 0)) >= 0)
                {
                        printf("Acaba de finalizar mi hijo con %i\n", cpid);
                        printf("Solo me quedan %i hijos\n", --total_proc);
                }
	}
}
}

return 0;
}
