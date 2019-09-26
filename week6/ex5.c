#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void  INThandler(){
    printf("%s", "bye\n");
    exit(0);
}


int main(){
    signal(SIGTERM, INThandler);
    pid_t pid = fork();

    if (pid == 0){
        while (1){
            printf ("I am alive\n");
            sleep(1);
        }
    }
    else {
        sleep(10);
        kill(pid,SIGTERM);
    }
    return 0;
}