#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int a[5]={1,2,3,4,5};
    printf("%d",a);
    int *b=a+(2*sizeof(int));
    printf("\n\n%d",*b);
    printf("\n\n%d %d %d %d %d",a[0],a[1],a[2],a[3],a[4]);
    return 0;
}