
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char c;
    int *fs = malloc(argc * sizeof(int));
    for (int i = 1; i < argc; i++) {
        fs[i] = open(argv[i], O_WRONLY | O_CREAT, S_IRWXU);
    }
    ssize_t s = read(0, &c, 1);
    while (s) {
        for(int i = 1; i < argc; i++) {
            write(fs[i], &c, 1);
        }
        write(1, &c, 1);
        s = read(0, &c, 1);
    }
}