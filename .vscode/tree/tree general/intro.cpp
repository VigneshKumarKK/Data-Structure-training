// Intro.cpp : This file contains the intro for tree data structure in c++
//like getting input 
//storing the data 
//using linked list..

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
	newnode=(struct node*)malloc(sizeof(struct node));
	cout << "Enter data or enter -1 if you no need for node" << endl;
	cin >> datax;
	if (datax == -1)
	{
		return 0;
	}
	newnode->data = datax;
	cout << "Enter the left child for the parent " << datax <<endl;
	newnode->left = create_tree();
	cout << "Enter the Right child for the parent " << datax << endl;
	newnode->right = create_tree();
	return newnode;
}


int main()
{
	struct node *root;
	root=create_tree();
	cout << "THE END" << endl;
	system("PAUSE");
	return 0;
}
