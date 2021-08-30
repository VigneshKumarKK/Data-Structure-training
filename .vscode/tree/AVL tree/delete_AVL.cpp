#include <iostream>
#include <stdlib.h>
using namespace std;

//we can define as a structure or class
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

    //condition 1 if we need right rotate
	if (balance > 1 && data < node->left->data)
		return rightRotate(node);

    //condition 2 if we need left rotate
	if (balance < -1 && data > node->right->data)
		return leftRotate(node);

    //condition 3 if we need left-right rotate
	if (balance > 1 && data > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

    //condition 4 if we need right-left rotate
	if (balance < -1 && data < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

    //condition 5 return asusal if there is proper balance
	return node;
}

Node * minValueNode(Node* node)
{
    Node* current = node;
 
    //to find the last left node in AVL tree
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 

Node* deleteNode(Node* root, int datadel)
{
     
    // normal BST delete
    if (root == NULL)
        return root;

    if ( datadel < root->data )
        root->left = deleteNode(root->left, datadel);

    else if( datadel > root->data )
        root->right = deleteNode(root->right, datadel);
 
    //comes to else when the node variable and deleting variable are same...
    else
    {
        //if any left or right side of node is null
        if((root->left == NULL) || (root->right == NULL))
        {
            //if root->left null na *temp=right , if no *temp=left
            Node *temp = root->left ? root->left : root->right;
 
            //this is like condition of both are null type
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }

            //this is normal
            else 
            *root = *temp; 

            //deleting
            free(temp);
        }

        else
        {
            //then taking the minvalue for replacing the deletion by taking the lowest in right
            Node* temp = minValueNode(root->right);
 
            root->data = temp->data;
 
            root->right = deleteNode(root->right,temp->data);
        }
    }
    
    //if this is a final node
    if (root == NULL)
    return root;
 
    //there may be a change in height so updating 
    root->height = 1 + max(height(root->left),height(root->right));
 
    //there may be a change in balancing so updating 
    int balance = getBalance(root);
 
    //again performing balance correction as seen in insertion
    //condition 1 if we need right rotate
	if (balance > 1 && datadel < root->left->data)
		return rightRotate(root);

    //condition 2 if we need left rotate
	if (balance < -1 && datadel > root->right->data)
		return leftRotate(root);

    //condition 3 if we need left-right rotate
	if (balance > 1 && datadel > root->left->data)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

    //condition 4 if we need right-left rotate
	if (balance < -1 && datadel < root->right->data)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

    //condition 5 return asusal if there is proper balance
	return root;
}

//inorder left root right
void inorder( Node* root)
{
	if (root != NULL) 
    {
        //left
		inorder(root->left);

        //root
		cout << root->data <<" ,";

        //right
		inorder(root->right);
	}
}

//preorder  root left right
void preorder(Node* root)
{
	if (root != NULL) 
    {
        //root
        cout << root->data <<" ,";

        //left
		preorder(root->left);

        //right
		preorder(root->right);
	}
}

//preorder  left right root
void postorder(Node* root)
{
	if (root != NULL) 
    {
        //left
	    postorder(root->left);

        //right
		postorder(root->right);

        //root
        cout << root->data <<" ,";
	}
}


int main()
{
	
    Node* root = NULL; //its a class not a struct
    int maindata=0; //variable to collect a userdata to insert and delete

    //calling insert function as per user request
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

    //print before delete
    cout<<"\n\n\n=========BEFORE DELETE FUNCTION TAKE PLACE=============\n";
	cout <<"\n\nINORDER DISPLAY OF AVL BINARY TREE\n";
	inorder(root);
    cout <<"\n\n\nPREORDER DISPLAY OF AVL BINARY TREE\n";
    preorder(root);
    cout <<"\n\n\nPOSTORDER DISPLAY OF AVL BINARY TREE\n";
    postorder(root);
    cout<< "\n\n";

    //calling delete function as per user request
    while(1)
    {
        cout << "Enter a number to delete in AVL binary tree or press -1 to exit   :::::::    ";
        cin >> maindata;
        if(maindata!=-1)
        {
            root = deleteNode(root, maindata);
            cout <<"\n\nAfter deletion of "<<maindata <<" from AVL binary tree, inorder traverse looks \n";
            inorder(root);
        }
        else
        {
            break;
        }
    }

	//print after delete
    cout<<"\n\n\n=========AFTER DELETE FUNCTION TAKE PLACE=============\n";
    cout <<"\n\nINORDER DISPLAY OF AVL BINARY TREE\n";
	inorder(root);
    cout <<"\n\n\nPREORDER DISPLAY OF AVL BINARY TREE\n";
    preorder(root);
    cout <<"\n\n\nPOSTORDER DISPLAY OF AVL BINARY TREE\n";
    postorder(root);
    cout<< "\n\n";

	return 1;
}

