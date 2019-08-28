#include <stdio.h>

void right_side_up_triangle(int n){
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < 2*n; ++j){
            if (i+j <= n || j-i >= n) printf(" ");
            else printf("*");
        }
        printf("\n");
    }
}

void ex5_1(int n){
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < i; ++j){
            printf("*");
        }
        printf("\n");
    }
}

void ex5_2(int n){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j <= i && j < n-i; ++j){
            printf("*");
        }
        printf("\n");
    }
}

void ex5_3(int n){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            printf("*");
        }
        printf("\n");
    }
}

int main(int argc, char **argv){
    int n;
    sscanf(argv[1], "%d", &n);
    right_side_up_triangle(n);
}