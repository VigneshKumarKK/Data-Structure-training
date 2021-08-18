#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head, *temp, *newnode;

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
        temp=head;
    }
    else
    {
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
    }
    }
}

void displayallnode()
{
    printf("nothing");
}

int main()
{
    createnode();

    printf("\n\nLet print what you enter....\n\n");
    temp=head;
    while(temp!=0)
    {
        printf("%d ,",temp->data);
        temp=temp->next;
    }
    printf("..");
    displayallnode();
    return 0;
}