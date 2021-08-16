#include <stdio.h>

int main()
{
    printf("Enter the size of the array\n");
    int n;

while(1)
{
    scanf("%d",&n);
    if(n>=21)
    {
        printf("Over size, please give 20 or below 20\n");
    }
    else if(n<=2)
    {
        printf("Too low size to test the code, please give above 2\n");
    }
    else
    {
        break;
    }
}
    int a[n];
    int t[n];
    int s=0;

    for(int i=0;i<n;i++)
    {
        printf("Enter the number of %dth index of array\n",i);
        scanf("%d",&a[i]);
    }

    printf("\nThe real order is\n");
    for(int i=0;i<n;i++)
        {
            if(i==0)
            printf("%d, ",a[i]);
            else if(i==(n-1))
            printf("%d",a[i]);
            else
            printf("%d, ",a[i]);
        }

    //start
    int nn=n/2;
    for(int i=0;i<nn;i++)
    {
        s=a[i];
        //printf("\n%d,%d",i,s);
        a[i]=a[n-1-i];
        //printf("\n%d",a[i]);
        a[n-1-i]=s;
        //printf("\n%d",a[n-i]);
    }
    //end

    printf("\nThe Reaaraged order is\n");
    for(int i=0;i<n;i++)
        {
            if(i==0)
            printf("%d, ",a[i]);
            else if(i==(n-1))
            printf("%d",a[i]);
            else
            printf("%d, ",a[i]);
        }
        return 0;
}
