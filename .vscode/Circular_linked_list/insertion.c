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

int count()
{
    struct node *tem;
    int cou=1;
    tem=tail->next;
    while(tem->next!=tail->next)
    {
        cou++;
        tem=tem->next;
    }
    //printf("length = %d",cou);
    return cou;
}
void insertatbeg()
{
    struct node *newnode;
    newnode= (struct node *) malloc(sizeof(struct node));
    printf("\n\nenter the data to store in the new node \n");
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
    }
    display();
}

void insertatend()
{
    struct node *newnode;
    newnode= (struct node *) malloc(sizeof(struct node));
    printf("\n\nenter the data to store in the new node \n");
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
    display();
}

void insertatpos()
{
    struct node *newnode;
    newnode= (struct node *) malloc(sizeof(struct node));
    printf("\n\nenter the data to store in the new node \n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(tail==0)
    {
        tail=newnode; 
        tail->next=newnode;
    }
    else
    {
        int pos,i=1;
        struct node *te;
        int co=count();
        printf("Enter the position where you need to enter the new node\n");
        while(1)
        {
            scanf("%d",&pos);
            if(pos<co && pos>1)
            {
                break;
            }
            printf("ERORR!!Position you have enter try to enter within 2 to %d\n",co);
        }
        te=tail->next;
        while(i<pos-1)
        {
            te=te->next;
            i++;
        }
        newnode->next=te->next;
        te->next=newnode;
    }
    display();
}


int main()
{
    //dis(play();
    createCiruclarLL();
    //int abc=count();
    //start
    int c;
    while(1)
    {
        printf("\n press 1 for insert at beginning\n press 2 for insert at end");
        printf("\n press 3 for insert at after the given position \n press any to exit\n");
        scanf("\n%d",&c);
        if(c==1)
        insertatbeg();
        else if(c==2)
        insertatend();
        else if(c==3)
        insertatpos();
        else
        break;
    }
    //end
    printf("\n\nFinal Outcome: ");
    display();
    printf("\n\n-------------THE END-------------");
}