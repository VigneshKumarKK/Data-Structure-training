//program to rotate "n" size array 
//ex: if array a=1,2,3,4,5 
//then input x=3
//then output will be a=3,4,5,1,2

//rotate right wise by rotational factor given

#include <stdio.h>

int main()
{
    printf("Enter the size of the array\n");
    int n;

while(1)
{
    scanf("%d",&n);
    if(n>=10)
    {
        printf("Over size, please give 10 or below 10\n");
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

    for(int i=0;i<n;i++)
    {
        printf("Enter the number of %dth index of array\n",i);
        scanf("%d",&a[i]);
    }

    printf("Enter the index of array you need to rotate\n");
    int x;
    
while(1)
{
    scanf("%d",&x);
    if(1>=x || x>=n)
    {
        printf("Error found in rotatioal factor!! please re-enter the value\n");
    }
    else
    {
        break;
    }
}
    
printf("\nArray before rotation be: \n");
    for(int i=0;i<n;i++)
    {
        if(i==0)
        printf("%d, ",a[i]);
        else if(i==(n-1))
        printf("%d",a[i]);
        else
        printf("%d, ",a[i]);
    }

//starts
    int s;
    for(int i=1;i<=x;i++)
    {
        s=a[n-1];
        for(int i=n-1;i>=1;i--)
        {
            a[i]=a[i-1];
        }
        a[0]=s;
        
        /* printf("\n\nArray after %dst rotation be: \n",i);
        for(int i=0;i<n;i++)
        {
            if(i==0)
            printf("%d, ",a[i]);
            else if(i==(n-1))
            printf("%d",a[i]);
            else
            printf("%d, ",a[i]);
        }*/

    }

//ends
printf("\n\nArray after rotation be: \n");
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