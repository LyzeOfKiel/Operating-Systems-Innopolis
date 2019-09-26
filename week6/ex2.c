#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int p[2];

    pipe(p);

    if (fork() == 0) {
        char s[10] = "";
        read(p[0], s, 10);
        printf("Read from pipe in child: %s\n", s);
    }
    else {
        char s[10] = "text";
        printf("Writing to pipe in parent: %s\n", s);

        write(p[1], s, 10);
    }

    return 0;
}