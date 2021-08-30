#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
	public:
	int data;
	Node *left;
	Node *right;
	int height;
};

//get left tree height and right tree height and return the maximum one
int max(int left_tree, int right_tree)
{
	return (left_tree > right_tree)? left_tree : right_tree;
}

//return the height stored in node->height but return  if there is NULL
int height(Node *Nodeforheight)
{
	if (Nodeforheight == NULL)
		return 0;
	return Nodeforheight->height;
}

//create a newnode as seen in BST
Node* newNode(int newdata)
{
	Node* node = new Node();
	node->data = newdata;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;			
	return(node);
}

//rotate the tree right
Node *rightRotate(Node *center)
{
	Node *t1 = center->left;
	Node *t2 = t1->right;

	//rotation
	t1->right = center;
	center->left = t2;

	// changing the heights after rotation
	center->height = max(height(center->left),
					height(center->right)) + 1;
	t1->height = max(height(t1->left),
					height(t1->right)) + 1;

	// Return new center root
	return t1;
}

//rotate the tree right
Node *leftRotate(Node *center)
{
	Node *t1 = center->right;
	Node *t2 = t1->left;

	// rotation
	t1->left = center;
	center->right = t2;

	// changing the heights after rotation
	center->height = max(height(center->left),
					height(center->right)) + 1;
	t1->height = max(height(t1->left),
					height(t1->right)) + 1;

	// Return new center root
	return t1;
}

// Finding Balance factor 
int getBalance(Node *Nodebal)
{
	if (Nodebal == NULL)
		return 0;
	return height(Nodebal->left) - height(Nodebal->right);
}


Node* insert(Node* node, int data)
{
    //we are creating the BST tree first
	if (node == NULL)
		return(newNode(data));
	if (data < node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);
	else 
		return 0; //BST not allow equal value or duplication

    //Declaring the node height for checking AVl balance
	node->height = 1 + max(height(node->left),height(node->right));

    //checking balance factor incorrection
	int balance = getBalance(node);

	if (balance > 1 && data < node->left->data)
		return rightRotate(node);

	if (balance < -1 && data > node->right->data)
		return leftRotate(node);

	if (balance > 1 && data > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && data < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

    //return asusal if there is proper balance
	return node;
}

void inorder( Node* root)
{
	if (root != NULL) 
    {
		inorder(root->left);
		cout << root->data <<" ,";
		inorder(root->right);
	}
}

void preorder(Node* root)
{
	if (root != NULL) 
    {
        cout << root->data <<" ,";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Node* root)
{
	if (root != NULL) 
    {
	    postorder(root->left);
		postorder(root->right);
        cout << root->data <<" ,";
	}
}


int main()
{
	
     Node* root = NULL;
    int maindata=0;
    while(1)
    {
        cout << "Enter a number into binary tree or press -1 to exit   :::::::    ";
        cin >> maindata;
        if( maindata!=-1)
        {
            root=insert(root, maindata);
        }
        else if(maindata==-1)
        {
            break;
        }
        else
        {
            cout <<"\n\nPlease Re-enter with valid choice \n\n";
        }
    }

    cout<<"\n======================\n\n";
	cout <<"\n\nINORDER DISPLAY OF AVL BINARY TREE\n";
	inorder(root);
    cout <<"\n\n\nPREORDER DISPLAY OF AVL BINARY TREE\n";
    preorder(root);
    cout <<"\n\n\nPOSTORDER DISPLAY OF AVL BINARY TREE\n";
    postorder(root);
    cout<< "\n\n";

	return 0;
}
