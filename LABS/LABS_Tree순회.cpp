#include <iostream>

using namespace std;

typedef struct node {
	struct node *left;
	struct node *right;
	int val;
}Tree;

Tree *root = NULL;
Tree *temp = NULL;
Tree * create_node(int n)
{
	if (n == -1)
	{
		return NULL;
	}
	Tree *new_node = (Tree *)malloc(sizeof(Tree));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->val = n;

	return new_node;
}
Tree * find_node(Tree * node,int num)
{
	if (node == NULL)
	{
		return NULL;
	}
	if (node->val == num)
	{
		temp = node;
	}
	
	find_node(node->left, num);
	find_node(node->right, num);
}
void PreorderTraversal(Tree *cur)
{
	if (cur == NULL)
	{
		return;
	}
	cout << cur->val << ' ';
	PreorderTraversal(cur->left);
	PreorderTraversal(cur->right);
}
void PostorderTraversal(Tree *cur)
{
	if (cur == NULL)
	{
		return;
	}
	
	PostorderTraversal(cur->left);
	PostorderTraversal(cur->right);
	cout << cur->val << ' ';
}
void InorderTraversal(Tree *cur)
{
	if (cur == NULL)
	{
		return;
	}
	InorderTraversal(cur->left);
	cout << cur->val << ' ';
	InorderTraversal(cur->right);	
}
void addToTree(int _parent,int _left, int _right)
{
	Tree *parent_node = create_node(_parent);
	Tree *left_node = create_node(_left);
	Tree *right_node = create_node(_right);

	if (root == NULL)
	{
		root = parent_node;
		parent_node->left = left_node;
		parent_node->right = right_node;
	}
	else
	{
		Tree *cur = root;
		find_node(cur, parent_node->val);
		Tree *find = temp;
		

		find->left = left_node;
		find->right = right_node;
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int _parent, _left, _right;
		cin >> _parent >> _left >> _right;		
		addToTree(_parent, _left, _right);

	}
	PreorderTraversal(root);
	cout << endl;
	InorderTraversal(root);
	cout << endl;
	PostorderTraversal(root);
}