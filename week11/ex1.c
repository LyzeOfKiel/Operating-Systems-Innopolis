#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main () {
    int f = open("./ex1.txt", O_RDWR);
    char *s = "This is a nice day";
    int slen = strlen(s);
    char *str = mmap(NULL, slen, PROT_WRITE | PROT_READ, MAP_SHARED, f, 0);
    memcpy(str, s, slen);
    ftruncate(f, slen);
    close(f);
    return 0;
}