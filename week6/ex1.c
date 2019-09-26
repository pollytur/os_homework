#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int a[2];
    char buf2[256] = "";
    char buf1[256] = "hello_world";
    if (pipe(a) == 0) {
        write(a[1], buf1, strlen(buf1));
        read(a[0], buf2, strlen(buf1));
    }
    printf("%s", buf2);
}