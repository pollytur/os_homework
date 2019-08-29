#include <stdio.h>
#include <limits.h>
#include  <float.h>

//http://tigcc.ticalc.org/doc/float.html

int main() {
    int a=INT_MAX;
    float b=FLT_MAX;
    double c=DBL_MAX;
    printf("max integer=%d\nmax float=%f\nmax double=%lf\n", a,b,c);
    printf("size of integer=%lu, size of float=%lu, size of double=%lu\n", sizeof(a), sizeof(b),
           sizeof(c));
    return 0;
}