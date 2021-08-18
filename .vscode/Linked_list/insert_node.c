#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

int main()
{
struct node *newnode, *temp , *head = NULL;
int n;
printf("how many nodes you need to create??\n");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
    newnode= (struct node *) malloc(sizeof(struct node));
    if(head==0)
    {
        head=newnode;
        temp=head;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
        temp->next=NULL;
    }
}

temp=head;
int i=1;
while(temp!=0)
{
    printf("\nenter the data for %d -- node\n",i);
    i++;
    scanf("%d",&temp->data);
    temp=temp->next;
}
  
printf("\n\nLet print what you enter....\n\n");
temp=head;
while(temp!=0)
{
    printf("%d ,",temp->data);
    temp=temp->next;
}
printf("..");

newnode= (struct node *) malloc(sizeof(struct node));
printf("\n\nEnter data u want to insert\n\n");
scanf("%d",&newnode->data);

printf("where you need to insert a node?");
printf("\nenter 1 - insert at beginning\nenter 2 - insert at end\nenter 3 or any - insert after a given location\n\n");
int pos=0;
scanf("%d",&pos);
if(pos==1)
{
    temp=newnode;
    newnode->next=head;
    head=temp;
}
else if(pos==2)
{
    newnode->next=NULL;
    //printf("sorryend");
    temp=head;
    while(temp->next!=0)
{
    temp=temp->next;
}
    temp->next=newnode;
}
else
{
    //printf("sorrymiddle");
    printf("\nEnter the place of node where to enter\n");
    int place;
    while(1)
    {
        scanf("%d",&place);
        if(place>n || place<0)
        {
            printf("\ninvalid position!! enter a valid place\n");
        }
        else
        {
            break;
        }
    }

    temp=head;

    printf("\nenter 1 if you want to add before place %d \n enter 2 or any if you want to add after place %d\n",place,place);
    scanf("%d",&pos);
    int i=2;
    if(pos!=1)
    {
        i=1;
    }
    while(i<place)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

printf("\n\nLet print what my program change it....\n\n");
temp=head;
while(temp!=0)
{
    printf("%d ,",temp->data);
    temp=temp->next;
}
printf("..");
return 0;
}

