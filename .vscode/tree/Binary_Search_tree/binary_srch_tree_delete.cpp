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
		inorder(root->left);
		inorder(root->right);
	}
}

void postorder(struct node* root)
{
	if (root != NULL) 
    {
		inorder(root->left);
		inorder(root->right);
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

struct node* minNode(struct node* current)
{
	while (current->left != NULL)
		current = current->left;
	return current;
}

struct node* deleteNode(struct node* root, int data)
{
	if (root == NULL)
		return root;
	else if (data < root->data)
		root->left = deleteNode(root->left, data);
	else if (data > root->data)
		root->right = deleteNode(root->right, data);
	else 
    {
		if (root->left == NULL) 
        {
			struct node* temp ;
            temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) 
        {
			struct node* temp;
            temp = root->left;
			free(root);
			return temp;
		}
		struct node* temp;
        temp = minNode(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}


int main()
{
	struct node* root = NULL;
    int maindata=0;
    bool flag=0;
    while(1)
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

    //print before delete
    cout<<"\n=========BEFORE DELETE FUNCTION TAKE PLACE=============\n\n";
	cout <<"\n\nINORDER DISPLAY OF BINARY TREE\n";
	inorder(root);
    cout <<"\n\n\nPREORDER DISPLAY OF BINARY TREE\n";
    preorder(root);
    cout <<"\n\n\nPOSTORDER DISPLAY OF BINARY TREE\n";
    postorder(root);
    cout<< "\n\n";


while(1)
    {
        cout << "Enter a number to delete in binary tree or press -1 to exit   :::::::    ";
        cin >> maindata;
        if(maindata!=-1)
        {
            root = deleteNode(root, maindata);
            cout <<"\n\nAfter deletion of "<<maindata <<" from binary tree, inorder traverse looks \n";
            inorder(root);
        }
        else
        {
            break;
        }
    }

	//print after delete
    cout<<"\n=========AFTER DELETE FUNCTION TAKE PLACE=============\n\n";
    cout <<"\n\nINORDER DISPLAY OF BINARY TREE\n";
	inorder(root);
    cout <<"\n\n\nPREORDER DISPLAY OF BINARY TREE\n";
    preorder(root);
    cout <<"\n\n\nPOSTORDER DISPLAY OF BINARY TREE\n";
    postorder(root);
    cout<< "\n\n";
	return 1;
}
