#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *tail=NULL;

void createCiruclarLL()
{
    struct node *newnode;
    int n;
    printf("how many nodes you need to create??\n");
    scanf("%d",&n);
    tail=NULL;
    for(int i=0;i<n;i++)
    {
        newnode= (struct node *) malloc(sizeof(struct node));
        printf("\n\nenter the data to store in node %d\n",(i+1));
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(tail==0)
        {
            tail=newnode; 
            tail->next=newnode;
        }
        else
        {   
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }  
    }
        //printf("%d",tail->next->data);
}

void display()
{
    struct node *temp;
    if(tail==0)
    {
        printf("\nnothing to print\n");
    }
    else
    {
        printf("\nPrinting the nodes: \n");
        temp=tail->next;
        while(temp->next!=tail->next)
        {
            printf("%d, ",temp->data);
            temp=temp->next;
        }
        printf("%d.....",temp->data);
    }    
}


int main()
{
    //display();
    createCiruclarLL();
    display();
}