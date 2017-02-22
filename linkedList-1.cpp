// Introduction to linked list
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct node 
{
	int data;
	struct node *next;
};

// Push to the front of the linked list
void appendAtBeginning(struct node *head, struct node **beforeHead_ref, int new_data)
{
	struct node *new_node = (struct node *) malloc(sizeof(struct node));

	new_node->data = new_data;
	new_node->next = head;
	(*beforeHead_ref) = new_node;
	cout<<"beforeHead data: "<<new_node->data<<" next: "<<new_node->next;
}

void appendAfter(struct node *prev_node, int new_data)
{
	if (prev_node == NULL) {
		printf("The given previous node cannot be NULL");
		return;
	}

	struct node *new_node = (struct node *) malloc(sizeof(struct node));

	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
	cout<<"\nNew node to be added after: "<<new_node->data<<" next: "<<new_node->next;
}

void appendAtLast(struct node *last, struct node **afterLast_ref, int new_data)
{
	struct node *new_node = (struct node *) malloc(sizeof(struct node));

	new_node->data = new_data;
	new_node->next = NULL;
	(*afterLast_ref) = new_node;
	cout<<"\nNode added after last, data: "<<new_node->data<<" next: "<<new_node->next;

	last->next = new_node;

	return;
}	

void printList(struct node *n)
{
	while(n != NULL) 
	{
		printf(" %d ", n->data);
		n = n->next;	
	}
}

int main()
{
	struct node *head = NULL;
	struct node *second = NULL;
	struct node *third = NULL;

	cout<< "Initialisation :"<<endl;
	cout<< "head :" << "address: " << head <<endl;
	cout<< "second :"<< "address :" << second <<endl;
	cout<< "third :" << "address :" << third <<endl;
	cout<<endl;

	head = (struct node *) malloc(sizeof(struct node));
	second = (struct node *) malloc(sizeof(struct node));
	third = (struct node *) malloc(sizeof(struct node));

	cout<< "After memory allocation :"<<endl;
	cout<< "head :" << head <<endl;
	cout<< "second :" << second <<endl;
	cout<< "third :" << third <<endl;
	cout<<endl;

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;
	
	cout<< "After data assignment :"<<endl;
	cout<< "head :" << "data: " << head->data <<" next: " << head->next <<endl;
	cout<< "second :"<< "data :" << second->data <<" next: " << second->next<<endl;
	cout<< "third :" << "data :" << third->data <<" next: " << third->next<<endl;
	cout<<endl;

	struct node *beforeHead = NULL;
	appendAtBeginning(head, &beforeHead, 100);

	printf("\nUpdated Linked List is: ");
	printList(beforeHead);
	cout<<endl;

	// Adding after second node
	struct node *afterNode = NULL;
	appendAfter(second, 200);

	printf("\nUpdated Linked List is: ");
	printList(beforeHead);		
	cout<<endl;

	// Adding after last node
	struct node *lastNode = NULL;
	appendAtLast(third, &lastNode, 300);
	
	printf("\nUpdated Linked List is: ");
	printList(beforeHead);

	return 0;
}
