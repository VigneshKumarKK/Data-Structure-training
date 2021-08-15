//program to rotate "n" size array 
//ex: if array a=1,2,3,4,5 
//then input x=3
//then output will be a=4,5,1,2,3

//rotate clockwise , by one step.

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
    
printf("\nArray before testing be: \n");
    for(int i=0;i<n;i++)
    {
        if(i==0)
        printf("\n%d\n",a[i]);
        else if(i==(n-1))
        printf("%d",a[i]);
        else
        printf("%d\n",a[i]);
    }

//starts
int y=a[0];
    for(int i=0;i<(n-1);i++)
    {
        a[i]=a[i+1];
    }
a[n-1]=y;
   

//ends
printf("\n\nArray after testing be: \n");
    for(int i=0;i<n;i++)
    {
        if(i==0)
        printf("\n%d\n",a[i]);
        else if(i==(n-1))
        printf("%d",a[i]);
        else
        printf("%d\n",a[i]);
    }
    return 0;
}