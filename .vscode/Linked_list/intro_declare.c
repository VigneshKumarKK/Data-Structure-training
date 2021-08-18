#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int main()
{
struct Node *head,*temp; 

head=(struct Node*)malloc(sizeof(struct Node));
head->next=(struct Node*)malloc(sizeof(struct Node));
temp=head->next;
temp->next=(struct Node*)malloc(sizeof(struct Node));
temp=temp->next;
temp->next=(struct Node*)malloc(sizeof(struct Node));
//temp=temp->next;
//temp->next=NULL;

head->data=1;
temp=head->next;
temp->data=2;
temp=temp->next;
temp->data=3;


printf("\n\nLet print ehat you enter....\n\n");
temp=head;
while(temp!=0)
{
    printf("%d ,",temp->data);
    temp=temp->next;
}
printf("..");



return 0;

}

