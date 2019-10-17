#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int page_frames;

bool search(int page_num, int frame[]) {
    for (int i = 0; i < page_frames; i++) {
        if (frame[i] == page_num) return true;
    }
    return false;
}

int find_most_aged_ind(int *age) {
    int min = INT_MAX;
    int ind = 0;
    for (int i = 0; i < page_frames; i++) {
        if (age[i] < min) {
            min = age[i];
            ind = i;
        }
    }
    return ind;
}

void shift_age(int age[], int page_num, int frame[]) {
    for (int i = 0; i < page_frames; i++) {
//      increased both in cases of hit and miss as algorythm cares about recent calls, not hits and misses
        if (frame[i] == page_num) age[i] = INT_MAX;
        else{
            age[i] = age[i] - 1;
        }

    }
}

int main() {
    printf("Enter the number of page frames: ");
    scanf("%d", &page_frames);

    int hit = 0;
    int miss = 0;
    int page_num=0;
    int frame[page_frames];
    int age[page_frames];

    for (int i = 0; i < page_frames; i++) {
        frame[i] = 0;
        age[i] = 0;
    }

   FILE *file = fopen("input.txt", "r");
    // FILE *file = fopen("/Users/polinaturiseva/Downloads/input.txt", "r");
    while (!feof(file)) {
        fscanf(file, "%d", &page_num);

        if (search(page_num, frame)) {
            hit++;
            shift_age(age, page_num, frame);
        } else {
            miss++;
            int most_aged_ind = find_most_aged_ind(age);
            frame[most_aged_ind] = page_num;
            age[most_aged_ind] = 0;
            shift_age(age, page_num, frame);
        }
    }

    printf("Hit %d\n", hit);
    printf("Miss %d\n",  miss);
    fclose(file);
}
