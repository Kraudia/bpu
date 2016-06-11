#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    if (-1 == (fd = open("./plik.out", O_CREAT|O_RDWR, 0600))) {
        perror("Blad podczas tworzenia pliku");
    }

    if (-1 == (close(fd))) {
        perror("Blad podczas zamykania pliku");
    } 
    return 0;
}
