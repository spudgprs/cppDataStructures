//implementaion fo stacks using linkedlist
#include <iostream>
using namespace std;
struct node
{
	int value;
	struct node * next;
}*head;
void push()
{
	struct node * temp = new node;
	temp->next = NULL;
	cout<<"Element : ";
	cin>>temp->value;
	if(head==NULL)
		head = temp;
	else
	{
		temp -> next = head;
		head = temp;
	}
}
void pop()
{
	if(head == NULL)
		cout<<"Underflow!\n";
	else
	{
		cout<<(head->value)<<" popped out of the stack\n";
		head = head ->next;
	}
}
void peek()
{
	if(head == NULL)
		cout<<"Nothing to print\n";
	else cout<<"Top Element :"<<(head->value)<<endl;
}
void traverse()
{
	struct node * temp = head;
	while(temp)
	{
		cout<<temp->value<<endl;
		temp = temp->next;
	}
}
int main()
{
	
	head = NULL;
	int repeat =1;
	while(repeat)
	{
		cout<<"Menu:\n(1) Push\n(2) Pop\n(3) Peek\n(4) Traverse\n(5) Exit\nChoice:  ";
		int choice =0;
		cin>>choice;
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2: 
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				traverse();
				break;
			case 5:
				exit (0);
			default:
				cout<<"Wrong choice in your life!\n";
		}
	}
	return 0;
}