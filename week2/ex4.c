#include <stdio.h>

void my_swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    my_swap(&a, &b);
}