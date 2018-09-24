//----------원형 큐
#include <iostream>
#include <cstdlib>
using namespace std;

int queue[101];

typedef struct _node {
	struct _node *next;
	int val;	
}node;

node *head = NULL;
node *tail = NULL;
int node_seq = 0;
int n, m;
bool isFULL()
{	
	if (node_seq == n)
	{
		return true;
	}
	return false;
	
}
bool isEmpty()
{
	if (head == tail)
	{
		return true;
	}
	return false;
}
void enqueue(int x)
{
	if (isFULL())
	{
		cout << "Overflow" << endl;
		return;
	}
	node_seq++;
	node *new_node = (node*)malloc(sizeof(node));
	new_node->next = NULL;
	new_node->val = x;
	
	tail->next = new_node;
	tail = tail->next;

}
void dequeue()
{
	if (isEmpty())
	{
		cout << "Underflow" << endl;
		return;
	}
	node_seq--;
	node *cur = head;
	head = head->next;
	free(cur);
}
void top()
{
	if (isEmpty())
	{
		cout << "NULL" << endl;
		return;
	}
	cout <<head->next->val << endl;
}
void print()
{
	node * cur = head;
	while (cur != NULL)
	{
		cout << cur->val << "->";
		cur = cur->next;
	}
	cout << endl;
}
void init(int n)
{
	node *new_node = (node*)malloc(sizeof(node));
	new_node->val = 0;
	new_node->next = NULL;	
	head = new_node;
	tail = new_node;
}
int main()
{	
	cin >> n >> m;
	init(n);
	for (int i = 0; i < m; i++)
	{
		int cmd = 0;
		cin >> cmd;
		if (cmd == 1)
		{
			int num = 0;
			cin >> num;
			enqueue(num);
		}
		else if (cmd == 2)
		{
			dequeue();
		}
		else if (cmd == 3)
		{
			top();
		}
		//print();
	}

}

//-------------------------------선형큐
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int queue[101];

typedef struct _node {
	struct _node *next;
	int val;
}node;

node *head = NULL;
node *tail = NULL;
int node_seq = 0;
int n, m;
bool isFULL()
{
	if (node_seq == n)
	{
		return true;
	}
	else
	{
		return false;
	}

}
bool isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void enqueue(int x)
{
	if (isFULL())
	{
		cout << "Overflow" << endl;
		return;
	}
	node *cur = (node *)malloc(sizeof(node));
	cur->next = NULL;
	cur->val = x;
	node_seq++;

	if (head == NULL)
	{
		head = cur;
		tail = cur;
	}
	else {
		tail->next = cur;
		tail = cur;
	}
}
void dequeue()
{
	node * cur = head;
	if (isEmpty())
	{
		cout << "Underflow" << endl;
		return;
	}

	head = head->next;
	if (head == NULL)
	{
		tail = NULL;
	}
	free(cur);
}
int top()
{
	if (isEmpty())
	{
		cout << "NULL" << endl;
		return -999;
	}
	return head->val;
}
void print()
{
	node * cur = head;
	while (cur != NULL)
	{
		cout << cur->val << "->";
		cur = cur->next;
	}
	cout << endl;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int cmd = 0;
		cin >> cmd;
		if (cmd == 1)
		{
			int num = 0;
			cin >> num;
			enqueue(num);
		}
		else if (cmd == 2)
		{
			dequeue();
		}
		else if (cmd == 3)
		{
			int ans = top();
			if (ans >= 0)
			{
				cout << ans << endl;
			}
		}
		//print();
	}

}