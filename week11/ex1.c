#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){

    int sfd, dfd;
    char *src, *dest;
    size_t filesize;
    FILE *fp;
    if((fp=fopen("ex1.txt", "w"))==NULL) {
        printf ("Cannot open file.\n");
        exit(1);
    }
    fprintf(fp,"This is a nice day");
    fclose(fp);
    return 0;
}
