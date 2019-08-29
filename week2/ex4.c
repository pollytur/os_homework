#include <stdio.h>

void swap(int *a, int *b){
    int t=*b;
    *b=*a;
    *a=t;
}

int main(int argc, char *argv[]) {
       int a,b;
       printf("Please enter 2 integers");
       scanf("%d%d", &a,&b);
       printf("Before swap a=%d, b=%d\n", a,b);
       swap(&a,&b);
       printf("After swapa=%d, b=%d", a,b) ;
    return 0;
}