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
    int j=0;
    int flag=0;

    for(int i=0;i<n;i++)
    {
        printf("Enter the number of %dth index of array\n",i);
        scanf("%d",&a[i]);
    }

    printf("Enter the number you need find\n");
    int x;
    scanf("%d",&x);

    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            t[j]=i;
            j++;
            flag=1;
        }
    }

    if(flag==1)
    {
        printf("The number %d found in the index",x);
        for(int i=0;i<j;i++)
        {
            printf(" %d,",t[i]);
        }
        printf(".");
    }
    else
    {
        printf("The number %d found not found",x);
    }
        return 0;
}
