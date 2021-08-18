#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int a[20]={1,2,3,4,5,6,7,8,9};
    int n,p;
    printf("Enter the number you need to insert\n");
    scanf("%d",&n);
    printf("Enter the position where you need to insert\n");
    scanf("%d",&p);
    int size=strlen(a);
    //printf("\n%d  %d",n,p);
    for(int i=size;i>=p-1;i--)
    {
        a[i+1]=a[i];
    }
    a[p-1]=n;
    size++;

    for(int i=0;i<size;i++)
        {
            if(i==0)
            printf("%d, ",a[i]);
            else if(i==(size-1))
            printf("%d",a[i]);
            else
            printf("%d, ",a[i]);
        }

    return 0;
}