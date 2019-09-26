#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int a[2];
    pipe(a);
    char buf2[256] = "";
    char buf1[256] = "hello_world";
    pid_t pid = fork();

    if (pid == 0){
        read(a[0], buf2, strlen(buf1) + 1);
        close(a[0]);
        printf("%s", buf2);
    }
    else {
        write(a[1], buf1, strlen(buf1) + 1);
        close(a[1]);
    }

}