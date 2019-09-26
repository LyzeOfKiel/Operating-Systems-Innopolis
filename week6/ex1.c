#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int p[2];

    pipe(p);

    char s1[10] = "string1", s2[10] = "";
    
    printf("Writing to pipe: %s\n", s1);

    write(p[1], s1, strlen(s1));
    read(p[0], s2, strlen(s1));

    printf("Read from pipe: %s\n", s2);

    return 0;
}