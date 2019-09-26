#include <printf.h>
#include <stdlib.h>
#include <zconf.h>

void handler() {
    printf("%s", "Handler is working");
    exit(0);
}

int main() {
    signal(SIGINT, handler);
    while(1) {
        pause();
    }
    return 0;
}