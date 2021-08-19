#include <stdio.h>
#include <stdlib.h>

int n=50,top=-1;
int stack[50];

void display()
{
    if(top==-1)
    {
        printf("no data to display");
    }
    else
    {
        for (int i=top;i>=0;i--)
        {
            printf("%d",stack[i]);
        }
    }
}

void push()
{
    int data;
    if(top==n-1)
    {
        printf("Stack overflowed!! sorry we cant push");
    }
    else
    {
        printf("Enter the data need to push");
        scanf("%d",&data);
        top++;
        stack[top]=data;
    }
    //display();
}

void pop()
{
    //int data;
    if(top==-1)
    {
        printf("Stack underflow!! sorry there is no data");
    }
    else
    {
        //data=stack[top];
        top--;
        //printf("\n%d",data);
    }
}

void peek()
{
    if(top==-1)
    {
        printf("no data to display");
    }
    else
    {
        printf("\n%d",stack[top]);
    }

}

int main()
{
    int c;
    while(1)
    {
        printf("\npress\n1 for push\n2 for pop\n3 for peek\n4 for display\n0 for exit\n");
        scanf("%d",&c);
        if(c==1)
        push();
        else if(c==2)
        pop();
        else if(c==3)
        peek();
        else if(c==4)
        display();
        else
        break;
    }
    printf("finally  ::  ");
    display();
    return 0;
}