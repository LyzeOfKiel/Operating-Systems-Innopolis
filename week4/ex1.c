#include <stdio.h>
#include <unistd.h> 

int main(){
    int n;
    n = fork();
    if (n == 0){
        printf("Hello from child [PID - %d]\n", getpid()); 
    } else {
        printf("Hello from parent [PID - %d]\n", getpid());
    }
}