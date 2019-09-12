#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    char *s;
    while (1){
        scanf("%s", s);
        system(s);
    }
    return 0;
}