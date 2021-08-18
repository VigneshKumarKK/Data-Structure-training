#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node *newnode, *temp , *head = NULL;

void Deletefrombeg()
{
    //struct node *t;
    temp=head;
    head=head->next;
    free(temp);
}

void Deletefromend()
{
    struct node *btemp;
    temp=head;
    while(temp->next!=0)
    {
        btemp=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head=NULL;
    }
    else
    {
        btemp->next=NULL;
    }
    free(temp);
}

void Deleteatmid()
{
    struct node *ntemp;
    int i=1;
    printf("enter the position of node which need to be delete");
    int place;
    scanf("%d",&place);
    temp=head;
    while(i<place-1)
    {
        temp=temp->next;
        i++;
    }
    ntemp=temp->next;
    temp->next=ntemp->next;
    free(ntemp);
}

int main()
{
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
int press;
//start
while(1)
{
    printf("\nenter 1 - delete at beginning\nenter 2 - delete at end\nenter 3 - delete after a given location\n\n");
    int pos=0;
    scanf("%d",&pos);
    if(pos==1)
    Deletefrombeg();
    else if(pos==2)
    Deletefromend();
    else if(pos==3)
    Deleteatmid();
//end
    printf("\n\nLet print what my program change it....\n\n");
    temp=head;
    while(temp!=0)
    {
        printf("%d ,",temp->data);
        temp=temp->next;
    }
    printf("..");
    printf("\n\npress 1 to continue or press 0 to quit\n\n");
    scanf("%d",&press);
    if(press==0)
    {
        break;
    }
    
}
printf("\n\n------------end----------");

return 0;
}
