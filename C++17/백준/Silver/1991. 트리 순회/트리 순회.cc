#include <iostream>
#include<string>
using namespace std;

class Node
{
public:
	Node* right;
	Node* left;
	char data;
	void SetValue(Node* left, Node* right)
	{
		this->right = right;
		this->left = left;
	}
};

void preorder(Node* node)
{
	cout << node->data;
	if (node->left != NULL)
		preorder(node->left);
	if (node->right != NULL)
		preorder(node->right);
}

void inorder(Node* node)
{
	if (node->left != NULL)
		inorder(node->left);
	cout << node->data;
	if (node->right != NULL)
		inorder(node->right);
}

void postorder(Node* node)
{
	if (node->left != NULL)
		postorder(node->left);
	if (node->right != NULL)
		postorder(node->right);
	cout << node->data;
}

int main()
{
	int count;
	cin >> count;
	Node* nodes = new Node[count];
	for (int i = 0; i < count; i++)
	{
		nodes[i].data = 'A' + i;
	}
	char input1;
	char input2;
	char input3;
	for (int i = 0; i < count; i++)
	{
		cin >> input1;
		cin >> input2;
		cin >> input3;

		nodes[input1 - 'A'].SetValue(input2 == '.' ? NULL : &nodes[input2 - 'A'], input3 == '.' ? NULL : &nodes[input3 - 'A']);
	}
	preorder(&nodes[0]);
	cout << '\n';
	inorder(&nodes[0]);		
	cout << '\n';
	postorder(&nodes[0]);
	cout << '\n';
}