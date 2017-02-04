//implementation of linked list
#include <iostream>
using namespace std;
struct node
{
	int value;
	struct node * next;
}*head, *tail;
int count()
{
	int count =0;
	struct node * temp = head;
	while(temp)
	{
		count++;
		temp = temp->next;
	}
	return count;
}
void print()
{
	cout<<"List: ";
	struct node * temp = head;
	while(temp)
	{
		cout<<temp->value<<" -> ";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}
void insert()
{
	struct node * temp = new node;
	temp-> next = NULL;
	cout<<"Enter the value : ";
	cin>>temp-> value;                                                                                                                                                                                                                                                                                                                                                                                                                                  
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
void remove()
{
	cout<<"Enter the position of the element to delete : ";
	int pos=0;
	cin>>pos;
	if(pos<=0 || pos> count())
		cout<<"Invalid Position"<<endl;
	else
	{
		if(pos==1)
		{	
			if(count() ==1)
				tail = tail ->next;
			head = head ->next;
		}
		else
		{
			struct node * temp = head;
			pos--;//checking for the element from the (pos-1)
			while(--pos)
				temp = temp -> next;
			temp->next = temp->next->next;
			if(temp->next == NULL)
				tail = temp;
		}

	}
}
void reverse()
{
	struct node * prev=NULL;
	struct node * current=head;
	struct node * next =NULL;
	while(current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;

	}
	head = prev;
	cout<<"Reverse Linked ";
	print();

}
int main()
{
	int choice =0;
	int con =1;
	head = NULL, tail = NULL;
	while(con)
	{
		cout<<"Menu:\n(1) Insert\n(2) Remove\n(3) Reverse\n(4) Print\n(5) Count\n(6) Exit\nCoice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				remove();
				break;
			case 3:
				reverse();
				break;
			case 4:
				print();
				break;
			case 5:
				cout<<"Count: "<<count()<<endl;
				break;
			case 6:
				con =0;
				break;
			default:
				cout<<"Wrong choice in your life :("<<endl;
				break;
		}
	}
	return 0;
}
