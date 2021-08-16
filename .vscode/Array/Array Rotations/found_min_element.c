#include <stdio.h>
int main()
{
    printf("Enter the size of the array\n");
    int n;

    while(1)
    {
        scanf("%d",&n);
        if(n>=15)
        {
            printf("Over size, please give 15 or below 15\n");
        }
        else if(n<=1)
        {
            printf("Too low size to test the code, please give above 1\n");
        }
        else
        {
            break;
        }
    }

    int a[n];
    int t[n];

    for(int i=0;i<n;i++)
    {
        printf("Enter the number of %dth index of array\n",i);
        scanf("%d",&a[i]);
    }

    int min=a[0];

    for(int i=1;i<n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
        }
    }

    printf("The minimum number in the array is %d....",min);
    return 0;
}