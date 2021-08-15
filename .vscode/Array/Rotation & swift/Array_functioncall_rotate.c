//program to rotate "n" size array 
//ex: if array a=1,2,3,4,5 
//then input x=3
//then output will be a=4,5,1,2,3

//rotate using temporary array.

#include <stdio.h>

void reverseme(int a[], int p, int q);

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

    printf("how many rotation you need to make in this array\n");
    int x;
    
while(1)
{
    scanf("%d",&x);
    if(x<=0)
    {
        printf("Error found in factor!! please re-enter the value\n");
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
        printf("\n%d\n",a[i]);
        else if(i==(n-1))
        printf("%d",a[i]);
        else
        printf("%d\n",a[i]);
    }

//starts
reverseme(a, 0, x - 1);
	reverseme(a, x, n - 1);
	reverseme(a, 0, n - 1);
//ends
printf("\n\nArray after rotation be: \n");
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

void reverseme(int a[], int p, int q)
{
	int t2;
	while (p < q) {
		t2 = a[p];
		a[p] = a[q];
		a[q] = t2;
		p++;
		q--;
	}
}

