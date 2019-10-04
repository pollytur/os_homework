#include <stdio.h>

int main() {
    char *s;
    char foo[] = "Hello World";
    s = foo;
    printf("s in %s \n", s);
    printf("s[0] is %c\n", s[0]);
    return (0);
}
