#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX 1024
#define MAX_ARGS 64

void type_prompt() {
    printf("meu_shell> ");
}

void read_command(char *command, char **parameters) {
    fgets(command, MAX, stdin);

    command[strcspn(command, "\n")] = 0;

    int i = 0;
    parameters[i] = strtok(command, " ");

    while (parameters[i] != NULL && i < MAX_ARGS - 1) {
        i++;
        parameters[i] = strtok(NULL, " ");
    }
}

int main() {
    char command[MAX];
    char *parameters[MAX_ARGS];
    int status;

    while (1) {
        type_prompt();
        read_command(command, parameters);

        if (parameters[0] == NULL) continue;

        if (strcmp(parameters[0], "exit") == 0) {
            break;
        }

        pid_t pid = fork();

        if (pid < 0) {
            perror("Erro no fork");
            exit(1);
        } 
        else if (pid > 0) {
            waitpid(pid, &status, 0);
        } 
        else {
            execvp(parameters[0], parameters);

            perror("Comando não encontrado");
            exit(1);
        }
    }

    return 0;
}