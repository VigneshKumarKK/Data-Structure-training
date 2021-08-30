#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node *left;
    struct node *right;
};


struct node* createNode(int newdata)
{
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = newdata;
	newnode->left =  NULL;
    newnode->right = NULL;
	return newnode;
}


void inorder(struct node* root)
{
	if (root != NULL) 
    {
		inorder(root->left);
		cout << root->data <<" ,";
		inorder(root->right);
	}
}

void preorder(struct node* root)
{
	if (root != NULL) 
    {
        cout << root->data <<" ,";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node* root)
{
	if (root != NULL) 
    {
		postorder(root->left);
		postorder(root->right);
        cout << root->data <<" ,";
	}
}


struct node* insert(struct node* node, int data)
{
	if (node == NULL)
		return createNode(data);
	else if (data < node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);
	return node;
}


int main()
{
	struct node* root = NULL;
    int maindata=0;
    bool flag=0;
    while(maindata!=-1)
    {
        cout << "Enter a number into binary tree or press -1 to exit   :::::::    ";
        cin >> maindata;
        if(flag!=0 && maindata!=-1)
        {
            insert(root, maindata);
        }
        else if(flag==0)
        {
            root = insert(root, maindata);
            flag=1;
        }
        else if(maindata==-1)
        {
            break;
        }
    }
    cout <<"\n\nINORDER DISPLAY OF BINARY TREE\n";
	inorder(root);
    cout <<"\n\n\nPREORDER DISPLAY OF BINARY TREE\n";
    preorder(root);
    cout <<"\n\n\nPOSTORDER DISPLAY OF BINARY TREE\n";
    postorder(root);
    cout<< "\n\n";
	return 0;
}
