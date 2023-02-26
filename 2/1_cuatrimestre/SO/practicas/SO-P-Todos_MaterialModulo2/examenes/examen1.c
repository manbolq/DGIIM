#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<pwd.h>
#include<wait.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    char *home_path;
    char *examen_path;
    char cadena_5[] = "abcde";
    char cadena_10[] = "0123456789";
    int fd5;
    int fd10;
    int fd_fifo;
    int fd_resultados;
    int num_files = 0;

    pid_t pid;
    pid_t pid2;

    if ( (pid = fork()) < 0)
    {
        perror("Error en fork");
        exit(-1);
    }
    else if(pid == 0) // el hijo
    {
        chdir(home_path = getpwuid(getuid())->pw_dir); // nos metemos en home
        mkdir("examen", S_IRWXU); // creamos el directorio examen

        // path de examen
        examen_path = home_path;
        strcat(examen_path, "/");
        strcat(examen_path, "examen");

        chdir(examen_path); // cambiamos al directorio examen

        mkdir("resultados", S_IRWXU); // creamos el directorio resultados

        // abrimos el archivo cinco.txt
        if ( (fd5 = open("cinco.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRUSR|S_IWUSR)) < 0)
        {
            perror ("Error al abrir cinco.txt");
            exit(-1);
        }

        // escribimos en cinco.txt
        if ( (write(fd5, cadena_5, sizeof(cadena_5)) != sizeof(cadena_5)))
        {
            perror("Error al escribir en cinco.txt");
            exit(-1);
        }

        // abrimos el archivo diez.txt
        if ( (fd10 = open("diez.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRUSR|S_IWUSR)) < 0)
        {
            perror ("Error al abrir diez.txt");
            exit(-1);
        }

        // escribimos en diez.txt
        if ( (write(fd10, cadena_10, sizeof(cadena_10)) != sizeof(cadena_10)))
        {
            perror("Error al escribir en diez.txt");
            exit(-1);
        }

        close(fd5);
        close(fd10);
        exit(0);
    }
    else{ // el padre
        wait(NULL);
        DIR *direct;
        struct dirent *file;


        examen_path = getpwuid(getuid())->pw_dir;
        strcat(examen_path, "/");
        strcat(examen_path, "examen");
        chdir(examen_path); // entramos en la carpeta examen
        direct = opendir(examen_path);


        if (direct == NULL) // error al abrir el directorio ~
        {
            perror("Error al abrir ~");
            exit(-1);
        }
        else    // si no hay error
        {
            struct stat atributos;

            mkfifo("padre_hijo", 0666); // creacion del archivo FIFO
            while ( (file = readdir(direct)) != NULL)
            {
                stat(file->d_name, &atributos);
                if (!S_ISFIFO(atributos.st_mode)) {
                    num_files++;

                    if ((fd_fifo = open("padre_hijo", O_RDWR)) < 0) {
                        perror("Error al abrir el fifo");
                        exit(-1);
                    } else {

                        int num_inodo = file->d_ino;
                        char num[10];
                        sprintf(num, "%d", num_inodo);
                        char name[100];
                        sprintf(name, "%s", file->d_name);
                        char buf[100];
                        sprintf(buf, "Archivo: ");
                        strcat(buf, name);
                        strcat(buf, ". Inodo: ");
                        strcat(buf, num);
                        strcat(buf, "\n");

                        if (write(fd_fifo, buf, sizeof(buf) + 1) != sizeof(buf) + 1) {
                            perror("Error al escribir en FIFO");
                            exit(-1);
                        }
                    }
                }
            }
            // Imprimimos el numero de archivos de examen
            printf("Numero de archivos: %d\n", num_files);
        }

        if ( (pid2 = fork()) < 0)
        {
            perror("Error al crear el segundo hijo");
            exit(-1);
        }
        else if (pid2 == 0) // segundo hijo
        {
            char buf[100];
            if ( (fd_resultados = open("resultados.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRUSR|S_IWUSR)) < 0)
            {
                perror("Error al abrir resultados");
                exit(-1);
            }

            while(read(fd_fifo, buf, sizeof(buf)) == sizeof(buf))
            {
                if ( (write(fd_resultados, buf, sizeof(buf))) != sizeof(buf))
                {
                    perror("Error al escribir en resultados");
                    exit(-1);
                }
            }
        }


    }

    return 0;
}