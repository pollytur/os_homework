#include <stdio.h>
#include <string.h>

int main() {
    char *str;
    printf("Please, write a string");
    scanf("%[^\n]s", str); //[^\n] to get the line with spaces
    printf("%s", str);
    int len=strlen(str)-1;
    for (len; len>=0; len--){
        printf("%c", str[len]);
    }
    return 0;
}