#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head, *temp, *newnode , *tail;


void createnode()
{
    int n;
    printf("how many nodes you need to create??\n");
    scanf("%d",&n);
    head=NULL;
    for(int i=0;i<n;i++)
    {
        newnode= (struct node *) malloc(sizeof(struct node));
        printf("\n\nenter the data to store in node %d\n",(i+1));
        scanf("%d",&newnode->data);
        newnode->prev=NULL;
        newnode->next=NULL;
        if(head==0)
        {
            head=newnode;
            tail=newnode;
            temp=head;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
            tail=temp;
        }
    }
}
void displayallnode()
{
    if(head==0 || tail==0)
    {
        printf("nothing to show");
    }
    else
    {
        printf("\n\nLet print....\n\n");
        temp=head;
        while(temp!=0)
        {
            printf("%d ,",temp->data);
            temp=temp->next;
        }
        printf("...The End...");
    }
}

void reversenode()
{
    if(head==0 || tail==0)
    {
        printf("nothing to reverse");
    }
    else
    {
        temp=head;
        while(temp!=0)
        {
            newnode=temp->next;
            temp->next=temp->prev;
            temp->prev=newnode;
            temp=newnode;
        }
        temp=head;
        head=tail;
        tail=temp;
    }
}

int main()
{
    createnode();
    //displayallnode();
    reversenode();
    displayallnode();
    return 0;
}