#include <stdio.h>
#include <string.h>

int main(){
    char my_str[256];
    scanf("%s", my_str);
    for (int i = strlen(my_str)-1; i >= 0; --i){
        printf("%c", my_str[i]);
    }
}