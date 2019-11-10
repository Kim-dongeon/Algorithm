#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	struct node *left;
	struct node *right;
};
struct node *root = 0;

void addToBST(int n)
{
	struct node *cur = (struct node*)malloc(sizeof(struct node));
	cur->left = cur->right = 0;
	cur->key = n;

	if (root == NULL)
	{
		root = cur;
		
	}
	else
	{
		struct node *temp = root;
		while (1)
		{
			if (temp->key > cur->key)
			{
				if (temp->left == 0)
				{
					temp->left = cur;
					return;
				}
				else
				{
					temp = temp->left;
				}
			}
			else
			{
				if (temp->right == 0)
				{
					temp->right = cur;
					return;
				}
				else
				{
					temp = temp->right;
				}
			}
		}
		
	}
}
struct node *findLeast(struct node *_node)
{
	struct node *cur = _node;
	while (cur->left != 0)
	{
		cur = cur->left;
	}
	return cur;
}
struct node* removeNode(struct node *node, int key)
{
	if (node == 0)
	{
		return 0;
	}

	if (key == node->key)
	{
		if (node->left == 0 && node->right == 0)
		{
			free(node);
			return 0;
		}
		else if (node->left ==0)
		{
			struct node *ret = node->right;
			free(node);
			return ret;
		}
		else if(node->right ==0)
		{
			struct node *ret = node->left;
			free(node);
			return ret;
		}
		else
		{
			struct node *toReplace = findLeast(node->right);
			node->key = toReplace->key;
			node->right = removeNode(node->right,toReplace->key);
			return node;

		}
	}
	else if (key < node->key)
	{
		node->left = removeNode(node->left, key);
		return node;
	}
	else
	{
		node->right = removeNode(node->right, key);
		return node;
	}
}

void inorderTraversal(struct node *_node)
{
	if (_node == 0)
	{
		return;
	}
	
	inorderTraversal(_node->left);
	printf("%d \n", _node->key);
	inorderTraversal(_node->right);
}
int main()
{
	addToBST(10);
	addToBST(5);
	addToBST(20);
	addToBST(7);
	addToBST(30);

	//printf("%d\n", root->key);
	//printf("%d\n", root->left->key);
	//printf("%d\n", root->right->key);
	//printf("----------------\n");
	///inorderTraversal(root);

	root = removeNode(root, 20);
    root = removeNode(root, 10);
	root =removeNode(root, 30);
	root = removeNode(root, 2000);
	
	printf("-=-----------------------\n");
	printf("root %d\n", root->key);
	//printf("root left %d\n", root->left->key);
	//printf("root right %d\n", root->right->key);

	printf("-------------\n");
	inorderTraversal(root);
	
}