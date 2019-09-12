#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

size_t n = 0; 
int max_args = 10, back_flag = 0;

char **tokenize(char *str)
{
  int i = 0;
  char **tokens = malloc(max_args * sizeof(char*));

  char *token = strtok(str, " \n");
  while (token != NULL) {
    tokens[i] = token;
    i++;
    token = strtok(NULL, " \n");
  }

  if (!strcmp(tokens[i-1], "&")){
      back_flag = 1;
      i--;
  }
  tokens[i] = NULL;
  return tokens;
}

int main(int argc, char **argv)
{
    char *line;
    char **tokens;
    int status;
    while(1) {
        printf("shell > ");
        getline(&line, &n, stdin);
        if (!strcmp(line, "exit\n")){
            exit(0);
        }
        back_flag = 0;
        tokens = tokenize(line);

        int pid = fork();
        if (pid == 0){ // child
            if (back_flag){
                /*
                How to hide terminal output:
                https://stackoverflow.com/questions/26453624/hide-terminal-output-from-execve
                */
                int fd = open("/dev/null", O_WRONLY);
                dup2(fd, 1);
                dup2(fd, 2);
                close(fd);
            }
            printf("*%s*", tokens[0]);
            if (execvp(tokens[0], tokens) == -1)
                perror("child crashed");
        } else if (!back_flag) { //parent
            waitpid(pid, &status, 0);
        }
    }

  return 0;
}