#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int a[5];
    printf("enter the 5 value with comma\n");
    scanf("%d,%d,%d,%d,%d",&a[0],&a[1],&a[2],&a[3],&a[4]);
    printf("\n\n%d %d %d %d %d",a[0],a[1],a[2],a[3],a[4]);
    return 0;
}