#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

/* Function to insert a node at the beginging of the linked list */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node =
		(Node*) malloc(sizeof(Node));

	/* put in the data  */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

void splitList(Node *head_ref, Node **a, Node **b)
{
	Node *slow = head_ref;
	Node *fast = head_ref;
	while (fast != NULL&&fast->next != NULL&&fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	*a = head_ref;
	*b = slow->next;
	slow->next = NULL;
}
Node *mergeList(Node *a, Node *b)
{
	if (a == NULL)
		return b;
	if (b == NULL)
		return a;
	Node *temp = (Node *)malloc(sizeof(Node));
	Node *tail = temp;
	while (a != NULL&&b != NULL)
	{
		if ((a)->data < (b)->data)
		{
			tail->next = a;
			a = (a)->next;
			tail = tail->next;
		}
		else
		{
			tail->next = b;
			b = (b)->next;
			tail = tail->next;
		}
	}
	while (a != NULL)
	{
		tail->next = a;
		a = (a)->next;
		tail = tail->next;
	}
	while (b != NULL)
	{
		tail->next = b;
		b = (b)->next;
		tail = tail->next;
	}
	tail = temp;
	temp = temp->next;
	free(tail);
	return temp;
}
void mergeSort(Node **head_ref)
{
	if (*head_ref == NULL || (*head_ref)->next == NULL)
	{
		return;
	}

	Node *a = NULL;
	Node *b = NULL;
	splitList(*head_ref, &a, &b);
	mergeSort(&a);
	mergeSort(&b);
	*head_ref = mergeList(a, b);
}
int main()
{
	/* Start with the empty list */
	Node* res = NULL;
	Node* a = NULL;

	/* Let us create a unsorted linked lists to test the functions
	Created lists shall be a: 2->3->20->5->10->15 */
	push(&a, 15);
	push(&a, 10);
	push(&a, 5);
	push(&a, 20);
	push(&a, 3);
	push(&a, 2);

	/* Sort the above created Linked List */
	mergeSort(&a);

	cout << "\n Sorted Linked List is: \n";
	printList(a);

	return 0;
}