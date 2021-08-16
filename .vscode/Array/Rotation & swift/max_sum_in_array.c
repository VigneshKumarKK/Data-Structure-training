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
    int b[n];
    int sum=0,gsum=0,count=0;


    for(int i=0;i<n;i++)
    {
        printf("Enter the number of %dth index of array\n",i);
        scanf("%d",&a[i]);
    }
    
    for(int i=0;i<n;i++)
            {
                b[i]=a[i];
            }
            
    int t2=0;
    for(int j=0;j<n;j++)
    {
        
        t2=a[0];
        for(int i=0;i<(n-1);i++)
        {
            a[i]=a[i+1];
        }
        a[n-1]=t2;
        
        for(int i=0;i<n;i++)
        {
            sum=sum+ (i*a[i]);
        }
        
        if(sum>gsum)
        {
            gsum=sum;
            count=j+1;
            for(int i=0;i<n;i++)
            {
                t[i]=a[i];
            }
        }
        sum=0;
    }
    if(count==n)
    {
        printf("The maximum sum of %d comes at real order without rotation");
        printf("\n The order of array is ");
        for(int i=0;i<n;i++)
        {
            printf(" %d,",b[i]);
        }
    }
    else
    {
        printf("The maximum sum of %d comes at the %d th time of rotation",gsum,count);
        printf("\n The real order of array is ");
        for(int i=0;i<n;i++)
        {
            printf(" %d,",b[i]);
        }
         printf("..");
        printf("\n The Maxout order of array is ");
        for(int i=0;i<n;i++)
        {
            printf(" %d,",t[i]);
        }
    }
    printf("......");
    printf("END");

    return 0;
}

