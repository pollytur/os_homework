#include <stdlib.h>
#include <stdio.h>
#include <malloc/malloc.h>
#include <memory.h>

void* my_realloc(void* smth, size_t size){
    if (smth==NULL){
        return malloc(size);
    }
    if(size==0){
        free(smth);
        return NULL;
    }
    if(size>malloc_size(smth)) {
        void *new=malloc(size);
        memcpy(new, smth,malloc_size(smth));
        free(smth);
        return new;
    }
    else{
        void *new=malloc(size);
        memcpy(new, smth, size);
        free(smth);
        return new;
    }
}

int main(){
    int n = 10;
    int * arr = (int *) malloc(sizeof(int));
    for (int i = 0; i < n; i++) {
        arr = (int *) my_realloc(arr, sizeof(int) * (i + 1));
        arr[i] = i;
        for (int j = 0; j <= i; j++) {
            printf("%d ", arr[j]);
        }
        printf ("\n");
    }
    free(arr);
    return 0;
}

