#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc == 2) {
        int n;
        if(sscanf(argv[1], "%d", &n)==0){
            fprintf(stderr, "error in sscanf \n");
        };
        for (int i = 0; i < n; i++) {
            for (int a = 0; a < (n - i); a++) {
                printf(" ");
            };
            for (int a = 0; a < 2 * i + 1; a++) {
                printf("*");
            };
            for (int a = 0; a < (n - i); a++) {
                printf(" ");
            };
            if (i != n - 1) {
                printf("\n");
            }
        }
    }
    else if (argc>2){
        printf("Too many arguments");
    }
    else{
        printf("One argument expected");
    }
    return 0;
}