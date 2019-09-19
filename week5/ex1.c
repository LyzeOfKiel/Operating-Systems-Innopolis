#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void* thread_func(void *arg){
    int* id = (int*) arg;
    printf("Message from thread %d\n", (int)pthread_self());
    return NULL;
}

int main(){
    int n = 10;
    pthread_t arr[n];
    for (int i = 0; i < n; ++i){
        pthread_t new_thread;
        int t = i;
        //printf("Creating thread %d\n", t);
        pthread_create( &new_thread, NULL, thread_func, (void *) &t);
        arr[i] = new_thread;
    }
    for (int i = 0; i < n; ++i){
        pthread_join(arr[i], NULL);
    }
}