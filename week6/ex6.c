#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>

void INThandler() {
    printf("%s", "bye\n");
    exit(0);
}

int main() {
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);
    pid_t first_child_pid = 1;
    pid_t second_child_pid = 1;


    first_child_pid = fork();
    if (!first_child_pid) {
        pid_t rec;
        read(fd1[0], &rec, sizeof(rec));

        printf("1: going to sleep.\n");
        sleep(5);

        printf("1: stopping process\n");
        kill(rec, SIGSTOP);

        printf("1: going to sleep\n");
        sleep(5);

        printf("1: resuming process \n");
        kill(rec, SIGCONT);

        printf("1: going to sleep\n");
        sleep(5);

        printf("1: asking process to terminate.\n");
        kill(rec, SIGINT);

    } else {
        second_child_pid = fork();
    }

    if (!second_child_pid) {
        signal(SIGINT, INThandler);
        while (1) {
            printf("2: living\n");
            sleep(1);
        }
    }

    if (first_child_pid) {
        printf("P: Sending 2nd child PID to 1st child...\n");
        write(fd1[1], &second_child_pid, sizeof(second_child_pid));
        close(fd1[1]);
        waitpid(second_child_pid, 0, 0);
    }

    return 0;
}