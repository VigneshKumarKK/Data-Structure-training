//Display the tree in in-order manner , pre-order manner, post-order manner

#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node* create_tree()
{
	struct node *newnode;
	int datax;
	newnode = (struct node*)malloc(sizeof(struct node));
	cout << "Enter data or enter -1 if you no need for node" << endl;
	cin >> datax;
	if (datax == -1)
	{
		return 0;
	}
	newnode->data = datax;
	cout << "Enter the left child for the parent " << datax << endl;
	newnode->left = create_tree();
	cout << "Enter the Right child for the parent " << datax << endl;
	newnode->right = create_tree();
	return newnode;
}

struct node * display_tree_preorder(struct node *root)
{
	if (root == 0)
		return 0;
	cout << root->data << " , ";
	display_tree_preorder(root->left);
	display_tree_preorder(root->right);
}

struct node * display_tree_inorder(struct node *root)
{
	if (root == 0)
		return 0;
	display_tree_inorder(root->left);
	cout << root->data << " , ";
	display_tree_inorder(root->right);
}

struct node * display_tree_postorder(struct node *root)
{
	if (root == 0)
		return 0;
	display_tree_postorder(root->left);
	display_tree_postorder(root->right);
	cout << root->data << " , ";
}

int main()
{
	struct node *root;
	root = create_tree();
	system("CLS");
	cout << endl << "The Tree is displaying in preorder manner" << endl;
	display_tree_preorder(root);
	cout << endl << "The Tree is displaying in postorder manner" << endl;
	display_tree_postorder(root);
	cout << endl << "The Tree is displaying in inorder manner" << endl;
	display_tree_inorder(root);
	system("PAUSE");
	return 0;
}
