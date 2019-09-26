#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h> 
#include <sys/wait.h>

int main() {
    int childId1, childId2;
    int p[2];
    pipe(p);

    if ((childId1 = fork()) == 0) {
        printf("Child 1 forked\n");
        char s[20];
        read(p[0], s, 20);
        int pid;
        sscanf(s, "%d", &pid);
        printf("Read child 2 id from pipe: %d\n", pid);
        sleep(2);
        printf("Killing child 2\n");
        kill(pid, SIGSTOP);
        printf("Exiting child 1\n");
        exit(0);
    }
    else {
        if ((childId2 = fork()) == 0) {
            printf("Child 2 forked\n");
            while (1) {
                printf("Child 2 is alive\n");
                sleep(1);
            }
        }
        else {
            char s[20];
            sprintf(s, "%d", childId2);
            printf("Sending child 2 pid to pipe: %d\n", childId2);
            write(p[1], s, 20);

            printf("Waiting for child 2 to change state\n");
            waitpid(childId2, NULL, WUNTRACED);
            printf("Wait finished\n");
        }
    }

    return 0;
}