#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node *newnode, *temp , *head = NULL;

int Getnodelen()
{
    int count=0;
    temp=head;
    while(temp!=0)
    {
        count++;
        temp=temp->next;
    }
    //printf("length = %d",count);
    return count;
}
 

int main()
{
    printf("The program is to count the lenght of the node\n");
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
  
/*printf("\n\nLet print what you enter....\n\n");
temp=head;
while(temp!=0)
{
    printf("%d ,",temp->data);
    temp=temp->next;
}
printf("..");*/
 int ans;
//start
    ans=Getnodelen();
    printf("\n\nThe lenght of the node you created is %d",ans);
//end
    
printf("\n\n------------end----------");

return 0;
}
