#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int is_finished(char *string) {
    if (-1 == system(string)) {
        fprintf(stderr, "finished: system error\n");
        exit(EXIT_FAILURE);
    };
    return 1;
}

char *read_line() {
    char *line=NULL;
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1) {
        fprintf(stderr, "read_line: reading error\n");
        exit(EXIT_FAILURE);
    };
    return line;
}

void command_cycles() {
    char *command;
    // char **command_after_parsing;
    int finished = 1;

    while (finished) {
        printf("waiting for a command");
        command = read_line();
        finished = is_finished(command);
    }
    //free memory
    free(command);
}

int main() {

    //start command cycles
    command_cycles();

    return EXIT_SUCCESS;
}