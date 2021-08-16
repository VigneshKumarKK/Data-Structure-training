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
          if(a[i]==0)
          {
              for(int j=i;j<n;j++)
              {
                  a[j]=a[j+1];
              }
                  a[n-1]=0;
          }
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

    printf("\n\n...........END..........\n.......Code by Vignesh ");
        return 0;
}
