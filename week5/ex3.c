#include <stdio.h>
#include <pthread.h>

int count = 0;

// flags
int consumerSleep = 0;
int producerSleep = 0;

void consumer() {
    int i = 0;
    while(1) {
        while(consumerSleep) {}
        
        if (i < 100)
            printf("%d\n", count);

        if (count) {
            count--;
            producerSleep = 0;
            i++;
        }
        else {
            consumerSleep = 1;
        }
    }
}

void producer() {
    int i = 0;
    while(1) {
        while(producerSleep) {}

        if (i < 100)
            printf("%d\n", count);

        if (count < 100) {
            count++;
            consumerSleep = 0;
            i++;
        } else {
            producerSleep = 1;
        }
    }
}

int main() {
    pthread_t prodid, conid;

    pthread_create(&prodid, NULL, &producer, NULL);
    pthread_create(&conid, NULL, &consumer, NULL);

    pthread_join(prodid, NULL);
    pthread_join(conid, NULL);
}