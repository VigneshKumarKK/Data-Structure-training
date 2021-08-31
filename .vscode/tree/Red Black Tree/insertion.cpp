#include <iostream>
#include <stdlib.h>
using namespace std;

enum Color {BLACK, RED};

struct node 
{
	int data; 
	bool color; // 1-red, 0-black
	struct node* parent; 
	struct node* right; 
	struct node* left; 
};

// Declaring root in global
struct node* root = NULL;

//pre declare to use in insert function
void fixup_rb_tree(struct node* root, struct node* pt);

//return user input value 
int ask_input()
{
    int userdata;
    cout <<"Enter the data to insert in Red black Tree   :::::    ";
    cin >> userdata;
    return userdata;
}

//BST insertion of a node
struct node* bst_insert(struct node* root,struct node* temp)
{
	// If node is empty, then directly return temp;
	if (root == NULL)
		return temp;

	if (temp->data < root->data)
	{
		root->left = bst_insert(root->left, temp);
		root->left->parent = root; //declaring the parent equal to root
	}
	else if (temp->data > root->data)
	{
		root->right = bst_insert(root->right, temp);
		root->right->parent = root; //declaring the parent equal to root
	}

	// if the data is repeted then we can return root pointer
	return root;
}

struct node* insert_new_node(struct node* root)
{
        //creating newnode
		struct node* newnode = (struct node*)malloc(sizeof(struct node));

        //declare all parameter as preset
		newnode->right = NULL;
		newnode->left = NULL;
		newnode->parent = NULL;
        //ask_input function ask input from user thats it..
		newnode->data = ask_input();
		newnode->color = 1;

        //calling bst_insert for basic binary inserting property
		root = bst_insert(root, newnode);

		// function for checking red black tree property
		fixup_rb_tree (root, newnode);

        return root;
}

// Function for right rotation
void rightrotate(struct node* temp)
{

	struct node* left = temp->left;

	temp->left = left->right;

	if (temp->left)
		temp->left->parent = temp;

	left->parent = temp->parent;

	if (!temp->parent)
		root = left;

	else if (temp == temp->parent->left)
		temp->parent->left = left;

	else
		temp->parent->right = left;
    
	left->right = temp;
	temp->parent = left;
}

// Function pfor left rotation
void leftrotate(struct node* temp)
{

	struct node* right = temp->right;

	temp->right = right->left;

	if (temp->right)
		temp->right->parent = temp;

	right->parent = temp->parent;

	if (!temp->parent)
		root = right;

	else if (temp == temp->parent->left)
		temp->parent->left = right;

	else
		temp->parent->right = right;

	right->left = temp;
	temp->parent = right;
}

// Recheck Red black tree property BST insertion
void fixup_rb_tree(struct node* root, struct node* pt)
{
    //this is done for easy representation only
	struct node* parent_pt = NULL;
	struct node* grand_parent_pt = NULL;

	while ((pt != root) && (pt->color != 0) && (pt->parent->color == 1))
	{
        //this is done for easy representation only 
		parent_pt = pt->parent;
		grand_parent_pt = pt->parent->parent;

		/* 
        Case : A
			Parent of this pointer is left child for the Grand-parent of this pointer
                under this there are 3 sub cases available
                    case 1 :if sibilings of this pointer is also red 
                    case 2: if this pointer is right child 
                    case 3: if this pointer is left child 
        */

		if (parent_pt == grand_parent_pt->left)
		{
            //this is done for easy representation only 
            //(uncle of this pointer is same as the sibilings of the parent of this pointer)
			struct node* uncle_pt = grand_parent_pt->right;

			/* 
            Case : 1
                The uncle of this pointer must be available
				The uncle of this pointer is also red
                Then:
				    Recolouring is only needed as result
             */

			if (uncle_pt != NULL && uncle_pt->color == 1)
			{
				grand_parent_pt->color = 1;
				parent_pt->color = 0;
				uncle_pt->color = 0;
				pt = grand_parent_pt;
			}

			else 
            {

                /* 
                Case : 2
                    The Pointer is Right Child of its own parent
                    Then:
				        Left-roation needed as first..
                        then Right-roation need
                */

				if (pt == parent_pt->right) 
                {
					leftrotate(parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}

				/* 
                Case : 3
                    The Pointer is left Child of its own parent
                    Then:
				        Right-roation only needed..
                        left-roation skiped
                */

				rightrotate(grand_parent_pt);
				bool tempcolor = parent_pt->color;
				parent_pt->color = grand_parent_pt->color;
				grand_parent_pt->color = tempcolor;
				pt = parent_pt;
			}
		}

        /* 
        Case : B
			Parent of this pointer is Right child for the Grand-parent of this pointer
                under this there are 3 sub cases available
                    case 1 :if sibilings of this pointer is also red 
                    case 2: if this pointer is leftt child 
                    case 3: if this pointer is right child 
        */

		else 
        {

            //this is done for easy representation only 
            //(uncle of this pointer is same as the sibilings of the parent of this pointer)
			struct node* uncle_pt = grand_parent_pt->left;

			/* 
            Case : 1
                The uncle of this pointer must be available
				The uncle of this pointer is also red
                Then:
				    Recolouring is only needed as result
             */

			if ((uncle_pt != NULL) && (uncle_pt->color == 1))
			{
				grand_parent_pt->color = 1;
				parent_pt->color = 0;
				uncle_pt->color = 0;
				pt = grand_parent_pt;
			}

			else 
            {

                /* 
                Case : 2
                    The Pointer is Left Child of its own parent
                    Then:
				        Right-roation needed as first..
                        then Leftt-roation need
                */

				if (pt == parent_pt->left) 
                {
					rightrotate(parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}

                 /* 
                Case : 3
                    The Pointer is Right Child of its own parent
                    Then:
				        Left-roation only needed..
                        Right-roation skiped
                */   
				
				leftrotate(grand_parent_pt);
				int tempcolor = parent_pt->color;
				parent_pt->color = grand_parent_pt->color;
				grand_parent_pt->color = tempcolor;
				pt = parent_pt;
			}
		}
	}
	root->color = 0; //we need to ensure the root color should be black always 
}


//inorder left root right
void inorder(struct node* root)
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
void preorder(struct node* root)
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
void postorder(struct node* root)
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

// main function
int main()
{
	int maindata=0; //variable to collect a userdata to insert and delete
    int count=0; //variable to know how many input the user needs
    cout <<"How many nodes you need to insert  ::  ";
    cin >> count;
    //calling insert function as per user request
    while(count)
    {
        root=insert_new_node(root);
        count--;
    }

    //print before delete
    cout<<"\n\n\n=========DISPLAY OF RED BLACK TREE=============\n";
	cout <<"\n\nINORDER DISPLAY OF RB TREE\n";
	inorder(root);
    cout <<"\n\n\nPREORDER DISPLAY OF RB TREE\n";
    preorder(root);
    cout <<"\n\n\nPOSTORDER DISPLAY OF RB TREE\n";
    postorder(root);
    cout<< "\n\n";



	return 0;
}
