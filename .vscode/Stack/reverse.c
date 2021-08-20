#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top=0,*topb=0;

void display()
{
    if(top==0)
    {
        printf("no data to display\n");
    }
    else
    {
        struct node * temp = top;
        while(temp!=0)
        {
            printf(" %d",temp->data);
            temp=temp->next;
        }
        printf("..");
    }
}

int isempty()
{
    if(top==0)
    return 0;
    else
    return 1;
}

void push()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data need to push\n");
    scanf("%d",&newnode->data);
    newnode->next=top;
    top=newnode;
    //display();
}

void secondpush(int get)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    //printf("Enter the data need to push\n");
    //scanf("%d",&newnode->data);
    newnode->data=get;
    newnode->next=topb;
    topb=newnode;
    //display();
}

void pop()
{
    if(top==0)
    {
        printf("\nStack underflow!! sorry there is no data\n");
    }
    else
    {
        printf("\n%d is poped out\n",top->data);
        struct node *temp=top;
        top=top->next;
        free(temp);
    }
}

int popreturn()
{
    if(top==0)
    {
        return 0;
    }
    else
    {
        //printf("\n%d is poped out\n",top->data);
        struct node *temp=top;
        int popdata;
        top=top->next;
        popdata=temp->data;
        free(temp);
        return popdata;
    }
}

void peek()
{
    if(top==0)
    {
        printf("\nno data to display\n");
    }
    else
    {
        printf("\n%d\n",top->data);
    }

}

void reverseit()
{
    if(top==0)
    {
        return;
    }
    else
    {
        while(isempty())
        {
            int extratemp;
            extratemp=popreturn();
            secondpush(extratemp);
        }
        top=topb;
    }
}

int main()
{
    int c;
    printf("\npress\n1 for push\n2 for pop\n3 for peek\n4 for display\n0 for exit\n");
    while(1)
    {
        printf("press\n");
        scanf("%d",&c);
        if(c==1)
        push();
        else if(c==2)
        pop();
        else if(c==3)
        peek();
        else if(c==4)
        display();
        else if(c==0)
        break;
        else
        {
            printf("out of the choice!! try again");
            //break;
        }
    }
    printf("before reverse  ::  ");
    display();
    reverseit();
    printf("\n\nfinally  ::  ");
    display();
    return 0;
}