#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front=0, *rear=0;

void display()
{
    struct node * temp;
    if(front==0 && rear==0 )
    {
        printf("\nno data to display\n");
    }
    else
    {
        struct node *temp = front;
        while(temp!=0)
        {
            printf(" %d",temp->data);
            temp=temp->next;
        }
        printf("..");
    }
}

int countnode()
{   
    struct node *temp;
    int count=0;
    temp=front;
    while(temp!=0)
    {
        count++;
        temp=temp->next;
    }
    //printf("length = %d",count);
    return count;
}

void enqueue()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data for node - %d\n",(countnode()+1));
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(front==0 && rear==0)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {   
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue()
{
    struct node *temp;
    temp=front;
    front=front->next;
    printf("\n%d is dequeued\n",temp->data);
    free(temp);
}

void peek()
{
    if(front==0 && rear==0 )
    {
        printf("\nno data to display\n");
    }
    else
    {
        printf("\npeeked value: %d\n",front->data);
    }

}

int main()
{
    int enqueue_count=10,dequeue_count=3;
    for(int i=0;i<enqueue_count;i++)
    enqueue();
    peek();
    for(int i=0;i<dequeue_count;i++)
    dequeue();
    peek();
    printf("\nThe Final Outcome:\n");
    display();
}
