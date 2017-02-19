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
	
	printList(head);

	return 0;
}
