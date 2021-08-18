#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node *newnode, *temp , *head = NULL;

void reversethenode()
{
    //printf("sorryreverse");
    struct node *ntemp , *ptemp; 
    ptemp=NULL;
    temp=head;
    ntemp=temp;
    while(ntemp!=0)
    {
        ntemp=ntemp->next;
        temp->next=ptemp;
        ptemp=temp;
        temp=ntemp;
    }
    head=ptemp;
    /*printf("\n\nLet print what my program change it....\n\n");
    temp=head;
    while(temp!=0)
    {
        printf("%d ,",temp->data);
        temp=temp->next;
    }
    printf("..");*/
}
 
int main()
{
printf("The program is reverse the nodes\n");
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

//start
reversethenode();
//end

printf("\n\nLet print what my program change it....\n\n");
    temp=head;
    while(temp!=0)
    {
        printf("%d ,",temp->data);
        temp=temp->next;
    }
    printf("..");
    
printf("\n\n------------end----------");

return 0;
}
