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
		(Node*)malloc(sizeof(Node));

	/* put in the data  */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

void quickSortUtil(Node **head_ref,Node **tail)
{
	if (*head_ref == NULL || (*head_ref)->next == NULL)
		return;
	Node *lessHead, *lessTail, *moreHead, *moreTail, *pivotHead, *pivotTail;
	lessHead = lessTail = moreHead = moreTail = pivotHead = pivotTail = NULL;
	Node *cur = *head_ref;
	pivotHead = pivotTail = cur;
	cur = cur->next;
	while (cur != NULL)
	{
		if (cur->data < pivotHead->data)
		{
			if (lessHead == NULL)
				lessHead = lessTail = cur;
			else
			{
				lessTail->next = cur;
				lessTail = lessTail->next;
			}
		}
		else if (cur->data > pivotHead->data)
		{
			if (moreHead == NULL)
				moreHead = moreTail = cur;
			else
			{
				moreTail->next = cur;
				moreTail = moreTail->next;
			}
		}
		else
		{
			pivotTail->next = cur;
			pivotTail = pivotTail->next;
		}
		cur = cur->next;
	}
	quickSortUtil(&lessHead, &lessTail);
	quickSortUtil(&moreHead, &moreTail);
	if (lessTail != NULL)
	{
		lessTail->next = pivotHead;
		*head_ref = lessHead;
	}
	else
	{
		*head_ref = pivotHead;
	}
	pivotTail->next = moreHead;
	if (moreTail != NULL)
	{
		*tail = moreTail;
	}
	else
	{
		*tail = pivotTail;
	}
}

void quickSort(Node **head_ref)
{
	if (*head_ref == NULL || (*head_ref)->next == NULL)
		return;
	Node *temp = *head_ref;
	while (temp->next)
		temp = temp->next;
	quickSortUtil(head_ref, &temp);
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
	quickSort(&a);

	cout << "\n Sorted Linked List is: \n";
	printList(a);

	return 0;
}