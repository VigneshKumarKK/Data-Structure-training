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

    printf("Enter the sum number you need find the pair\n");
    int x;
    scanf("%d",&x);

    int flag=0;
    int flag2=0;
    int r=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if((a[i]+a[j])==x)
                {
                    flag=1;
                    t[r]=a[i];
                     r++;
                    t[r]=a[j];
                     r++;
                    break;  
           
                }
        }
    }

    if(flag==1)
    {
        printf("The sum %d gets from the pair",x);
        for(int i=0;i<r;i++)
        {
            printf(" %d",t[i]);
            i++;
            printf(" and %d,",t[i]);
        }
        printf(".");
    }
    else
    {
        printf("The pair not found",x);
    }
        return 0;
}
