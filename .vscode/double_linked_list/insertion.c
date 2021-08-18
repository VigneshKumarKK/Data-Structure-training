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
    printf("\nprinting the nodes\n");
    temp=head;
    while(temp!=0)
    {
        printf("%d ,",temp->data);
        temp=temp->next;
    }
}

void insertatbeg()
{
    //printf("sorry1");
    newnode =(struct node *) malloc(sizeof(struct node));
    printf("\n\nenter the data to store in node begining\n");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
    //displayallnode();
}

void insertatend()
{
    //printf("sorry2");
    newnode =(struct node *) malloc(sizeof(struct node));
    printf("\n\nenter the data to store in node at the end\n");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    //displayallnode();
}

void insertatpos()
{
    //printf("sorry3");
    int i=1,pos;
    newnode =(struct node *) malloc(sizeof(struct node));
    printf("\n\nenter the data to store in node at position\n");
    scanf("%d",&newnode->data);
    printf("Enter the position you need to insert\n");
    scanf("%d",&pos);
    //newnode->prev=NULL;
    //newnode->next=NULL;
    temp=head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->next->prev=newnode;
}

void insertafterpos()
{
    //printf("sorry4");
    int i=1,pos;
    newnode =(struct node *) malloc(sizeof(struct node));
    printf("\n\nenter the data to store in node at after the position you enter\n");
    scanf("%d",&newnode->data);
    printf("Enter the position you need to insert\n");
    scanf("%d",&pos);
    //newnode->prev=NULL;
    //newnode->next=NULL;
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->next->prev=newnode;
}


int main()
{
    createnode();
    //displayallnode();
    int choice;
    printf("\nEnter the insertion method from the choice below\n");
    while(1)
    {
        printf("\n press 1 for insert at beginning\n press 2 for insert at end\n press 3 for insert at position");
        printf("\n press 4 for insert at after the position \n press any to exit\n");
        scanf("%d",&choice);
        if(choice==1)
        insertatbeg();
        else if(choice==2)
        insertatend();
        else if(choice==3)
        insertatpos();
        else if(choice==4)
        insertafterpos();
        else
        break;
        displayallnode();
    }
    printf("\n\nFinal outcome");
    displayallnode();
      printf("\n------------The End------------");
    return 0;
}