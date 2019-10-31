#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char **argv){

    int sfd = open("./ex1.txt", O_RDONLY);
    size_t filesize = lseek(sfd, 0, SEEK_END);

    char *src = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, sfd, 0);
    int dfd = open("./ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);
    ftruncate(dfd, filesize);
    char *dest = mmap(NULL, filesize, PROT_READ | PROT_WRITE, MAP_SHARED, dfd, 0);
    memcpy(dest, src, filesize);

    munmap(src, filesize);
    munmap(dest, filesize);

    close(sfd);
    close(dfd);

    return 0;
}