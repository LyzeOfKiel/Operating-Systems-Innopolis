#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* my_realloc(void *p, int prev_size, int new_size) {
    if (new_size == 0) {
        free(p);
        return NULL;
    }
    if (p == NULL) return malloc(new_size);

    if (new_size <= prev_size){
        return p;
    }

    void* newp;
    newp = malloc(new_size);
    memcpy(newp, p, prev_size);
    free(p);
    return newp;
}

int main() {

    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        a[i] = i;
        printf("%d ", a[i]);
    }
    printf("\n");

    int m;
    scanf("%d", &m);
    a = (int *) my_realloc(a, n * sizeof(int), m * sizeof(int));

    for (int i = 0; i < m; ++i){
        printf("%d ", a[i]);
    }
    printf("\n");

}