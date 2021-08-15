#include <stdio.h>

int main()
{

	// Creating an integer array named vignesh of size 5.
	int vignesh[5];
	// accessing element from 0 to 4 index and setting its value from 1 to 5..
    for(int i=0;i<=5;i++)
    {
        vignesh[i]=i+1;
    }
	// access and print value from 0 to 4 index we get the output.
    for(int i=0;i<=5;i++)
    {
      if(i!=5)
	    printf("%d, ", vignesh[i]);
      else
        printf("%d.", vignesh[i]);
    }
	return 0;
}
