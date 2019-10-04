#include <stdlib.h>
#include <stdio.h>

int main() {
    int N;
    printf("enter N");
    scanf("%d", &N);
    int *ar=(int*)calloc(N, sizeof(int));;
    for (int i=0; i<N; i++){
        ar[i]=i;
        printf("%d  ", ar[i]);
    }
    free(ar);
    return (0);
}
