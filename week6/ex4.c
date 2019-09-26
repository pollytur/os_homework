#include <printf.h>
#include <stdlib.h>
#include <zconf.h>

void handler_kill() {
    printf("%s", "Kill");
    exit(0);
}

void handler_stop() {
    printf("%s", "Stop");
    exit(0);
}

void handler_usr1() {
    printf("%s", "Usr1");
    exit(0);
}

int main() {
    signal(SIGKILL, handler_kill);
    signal(SIGSTOP, handler_stop);
    signal(SIGUSR1, handler_usr1);

    while(1) {
        pause();
    }
    return 0;
}