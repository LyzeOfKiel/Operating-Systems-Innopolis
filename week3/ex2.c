#include <stdio.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble_sort(int arr[], int low, int high){
    int n = high - low + 1;
    do{
        int newn = 0;
        for (int i = low; i < high; ++i){
            if (arr[i-1] > arr[i]){
                swap(&arr[i-1], &arr[i]);
                newn = i;
            }
        }
        n = newn;
    } while (n > 0);
}

int main(){
    int a[] = {10,9,8,7,6,5,4,3,2,1,0};
    int n = sizeof(a)/sizeof(a[0]);
    bubble_sort(a, 0, n);
    
    for (int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
    return 0;
}