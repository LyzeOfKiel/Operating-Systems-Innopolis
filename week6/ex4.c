#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void action(int s) {
    printf("Signal %d\n", s);
}

int main() {
    struct sigaction handler;
    handler.sa_handler = &action;
    sigaction(SIGKILL, &handler, NULL);
    sigaction(SIGSTOP, &handler, NULL);
    sigaction(SIGUSR1, &handler, NULL);

    while (1) {}

    return 0;
}
