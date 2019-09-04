#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int length) {
    for (int i=0; i<=length; i++){
        for(int y=1; y<length-i; y++){
            if(arr[y]<arr[y-1]){
                arr[y]=arr[y-1]+arr[y];
                arr[y-1]=arr[y]-arr[y-1];
                arr[y]=arr[y]-arr[y-1];
            }
        }
    }
}

int main() {
    int array[]={4, 1, 3, 2, 5};
    bubble_sort(array, 5);
    for (int i=0; i<5; i++){
        printf("%d  ", array[i]);
    }
    return 0;
}