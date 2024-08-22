#include <iostream>
#include<string>
using namespace std;

struct Node
{
	int data;
	Node* right;
	Node* left;
};

Node* root;

Node* MakeNode(int data)
{
	Node* node = new Node();
	node->data = data;
	node->right = NULL;
	node->left = NULL;
	return node;
}

void InsertNode(Node* r, Node* node)
{
	if (r->data < node->data)
	{
		if (r->right == NULL)
			r->right = node;
		else
			InsertNode(r->right, node);
	}
	else if (r->data > node->data)
	{
		if (r->left == NULL)
			r->left = node;
		else
			InsertNode(r->left, node);
	}
}

void Search(Node* node)
{
	if (node->left != NULL)
		Search(node->left);
	if (node->right != NULL)
		Search(node->right);
	cout << node->data << endl;
}

int main() 
{
	int input;
	cin >> input;
	root = MakeNode(input);
	while (cin >> input)
	{
		InsertNode(root, MakeNode(input));
	}

	Search(root);
}