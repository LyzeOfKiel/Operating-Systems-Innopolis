#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int f = open("/dev/random", O_RDONLY);
    int out = open("./ex1.txt", O_WRONLY | O_CREAT, S_IRWXU);
    char arr[20];
    read(f, arr, 20);
    write(out, arr, 20);
    close(f);
    close(out);
}