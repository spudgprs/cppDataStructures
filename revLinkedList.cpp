//reverse a linked list
#include <iostream>
using namespace std;
struct node
{
	int value;
	struct node * next;
}*head, *tail;
int main()
{
	head = NULL;
	tail = NULL;
	int n=0;
	cout<<"Enter the number of elements N: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		struct node * temp = new node;
		temp->next= NULL;
		cout<<(i+1)<<" element: ";
		cin>>temp->value;
		if(head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail -> next = temp;
			tail = tail->next;
		}

	}
	cout<<"Inserted Linked list : ";
	struct node * temp = head;
	while(temp)
	{
		cout<<temp->value<<" -> ";
		temp = temp ->next;
	}
	cout<<"NULL"<<endl;
	//reverse
	struct node * prev = NULL;
	struct node * current = head;
	struct node * next = NULL;
	while(current)
	{
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	cout<<"Reversed Linked list : ";
	temp = head;
	while(temp)
	{
		cout<<temp->value<<" -> ";
		temp = temp ->next;
	}
	cout<<"NULL"<<endl;

	return 0;
}