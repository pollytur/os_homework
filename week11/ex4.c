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
    sfd = open("ex1.txt", O_RDONLY);
    filesize = lseek(sfd, 0, SEEK_END);
    src = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, sfd, 0);
    dfd = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);
    //regulates the size of the file in order if it were longer to get rid of extra info
    ftruncate(dfd, filesize);
    dest = mmap(NULL, filesize, PROT_READ | PROT_WRITE, MAP_SHARED, dfd, 0);
    memcpy(dest, src, filesize);
    //deletes the mappings for the specified address range
    munmap(src, filesize);
    munmap(dest, filesize);
    close(sfd);
    close(dfd);
    return 0;
}
