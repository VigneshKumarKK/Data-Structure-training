
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node *newnode, *temp , *head = NULL;

void sortList() 
{  
    struct node *current, *tnext = NULL;  
    int temp;  
    current = head;
          
    if(head == 0)  
    return;  
    else 
    {  
        while(current != NULL) 
        {   
            tnext = current->next;  
            while(tnext != NULL) 
            {   
                if(current->data > tnext->data) 
                    {  
                        temp = current->data;  
                        current->data = tnext->data;  
                        tnext->data = temp;  
                    }  
                tnext = tnext->next;  
            }  
            current = current->next;  
        }      
    }  
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
sortList();
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
