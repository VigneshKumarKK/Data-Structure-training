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

void deleteatbeg()
{
    //printf("sorry1");
    if(head==0 || tail==0)
    {
        printf("nothing to delete");
    }
    else
    {
        temp=head;
        head=temp->next;
        head->prev=NULL;
        free(temp);
        //displayallnode();
    }
}

void deleteatend()
{
    //printf("sorry2");
    if(head==0 || tail==0)
    {
        printf("nothing to delete");
    }
    else
    {
        temp=tail;
        tail=temp->prev;
        tail->next=NULL;
        free(temp);
        //displayallnode();
    }
}

void deleteatpos()
{
    //printf("sorry3");
    int i=1,pos;
    printf("Enter the position where node to be deleted");
    scanf("%d",&pos);
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}


int main()
{
    createnode();
    //displayallnode();
    int choice;
    printf("\nEnter the deletion method from the choice below\n");
    while(1)
    {
        printf("\n press 1 for delete at beginning\n press 2 for delete at end");
        printf("\n press 3 for delete at after the given position \n press any to exit\n");
        scanf("%d",&choice);
        if(choice==1)
        deleteatbeg();
        else if(choice==2)
        deleteatend();
        else if(choice==3)
        deleteatpos();
        else
        break;
        displayallnode();
    }

    printf("\n\nFinal outcome");
    displayallnode();
    printf("\n------------The End------------");
    return 0;
}