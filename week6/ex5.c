#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main() {
    int childId;

    if ((childId = fork()) == 0) {
        while (1) {
            sleep(1);
            printf("I am alive\n");
        }
    }
    else {
        sleep(10);
        kill(childId, SIGTERM);
    }

    return 0;
}