//implementaion of Queue using linked list

#include <iostream>
using namespace std;
struct node
{
	int value;
	struct node * next;
} *head, *tail;
void push()
{
	struct node * temp = new node;
	temp -> next = NULL;
	cout<<"Element: ";
	cin>>temp->value;
	if(head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail -> next = temp;
		tail = tail ->next;
	}

}
void pop()
{
	if(head == NULL)
		cout<<"Overflow\n";
	else
	{
		cout<<head->value<<" is popped out\n";
		head = head->next;
	}
}
void front()
{
	if(head == NULL)
		cout<<"Not yet Initialized\n";
	else
		cout<<"Front: "<<head->value<<endl;
}
void back()
{
	if(head == NULL)
		cout<<"Not yet Initialized\n";
	else
		cout<<"Back: "<<tail->value<<endl;	
}
void traverse()
{
	struct node * temp = head;
	while(temp)
	{
		cout<<temp->value<<" -> ";
		temp = temp ->next;
	}
	cout<<"NULL\n";
}
int main()
{
	head = NULL, tail = NULL;
	int repeat =1;
	while(repeat)
	{
		cout<<"Menu:\n(1) Push\n(2) Pop\n(3) Front\n(4) Back\n(5) Traverse\n(6) Exit\nChoice:  ";
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
				front();
				break;
			case 4:
				back();
				break;
			case 5:
				traverse();
				break;
			case 6:
				exit (0);
			default:
				cout<<"Wrong choice in your life!\n";
		}
	}
	return 0;
}