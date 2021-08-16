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

    int x;
    printf("Enter the index of element you need for\n");
    while(1)
    {
        scanf("%d",&x);
        if(0>=x || x>n)
        {
         printf("Error found in index order you asked for!!!! please re-enter the index value\n");
        }
        else
        {
         break;
        }
    }
    

    /*printf("\nThe  order is\n");
    for(int i=0;i<n;i++)
        {
            if(i==0)
            printf("%d, ",a[i]);
            else if(i==(n-1))
            printf("%d",a[i]);
            else
            printf("%d, ",a[i]);
        }*/

    //start
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]>a[j])
            {
                s=a[i];
                a[i]=a[j];
                a[j]=s;
            }
        }
        /*printf("\nThe order is\n");
        for(int k=0;k<n;k++)
        {
            if(k==0)
            printf("%d, ",a[k]);
            else if(k==(n-1))
            printf("%d",a[k]);
            else
            printf("%d, ",a[k]);
        }*/
    }
    //end
    /*printf("\nThe Reaaraged order is\n");
    for(int i=0;i<n;i++)
        {
            if(i==0)
            printf("%d, ",a[i]);
            else if(i==(n-1))
            printf("%d",a[i]);
            else
            printf("%d, ",a[i]);
        }*/

    printf("The number you asked for is %d",a[x]);
        return 0;
}
