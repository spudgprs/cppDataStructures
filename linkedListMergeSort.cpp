//merge sort for linked list
#include <iostream>
#include <vector>
using namespace std;
struct node {
	int value;
	struct node * next;
}*head, *tail;
void print(struct node * head)
{
	while(head)
	{
		cout<<head->value<<" -> ";
		head = head->next;
	}
	cout<<"NULL"<<endl;
}
struct node * merge(struct node * left, struct node * right)
{
	struct node * resultHead = NULL;
	struct node * resultTail = NULL;
	while(left && right)
	{
		struct node * temp = new node;
		temp -> next = NULL;
		if(left->value < right->value)
		{
			temp->value = left->value;
			left = left->next;
		}
		else
		{
			temp->value = right->value;
			right = right ->next;
		}
		if(resultHead== NULL)
		{
			resultHead = temp;
			resultTail = temp;
		}
		else
		{
			resultTail -> next = temp;
			resultTail = resultTail -> next;
		}
		
	}
	while(left)
	{
		struct node * temp = new node;
		temp -> next = NULL;
		temp ->value = left->value;
		if(resultHead== NULL)
		{
			resultHead = temp;
			resultTail = temp;
		}
		else
		{
			resultTail -> next = temp;
			resultTail = resultTail -> next;
		}
		left = left->next;
	}
	while(right)
	{
		struct node * temp = new node;
		temp -> next = NULL;
		temp -> value = right -> value;
		if(resultHead== NULL)
		{
			resultHead = temp;
			resultTail = temp;
		}
		else
		{
			resultTail -> next = temp;
			resultTail = resultTail -> next;
		}
		right = right->next;
	}
	return resultHead;

}
void list_split(struct node * head, struct node **left, struct node ** right)
{
	//using slow and fast pointer logic
	struct node * slow;
	struct node * fast;
	slow = head;
	fast = head -> next;
	while(fast && fast ->next)
	{
		//advance fast two times and slow one time 
		fast= fast->next->next;
		slow = slow->next;
	}
	*left = head;
	*right = slow->next;
	slow->next = NULL; //for termintating the splitted list
	}
}
void merge_sort(struct node ** headRef)
{
	struct node * head = *headRef;
	if(head && head->next) //if (n>=2)
	{	
		struct node * left;
		struct node * right;
		list_split(head, &left, &right); //need left and right after splitting so pass &
		merge_sort(&left);
		merge_sort(&right);
		//now merge botht the split lists
		*headRef = merge(left, right);//no need with a and b values further so no &
	}
}
int main()
{
	head = NULL, tail = NULL;
	int n=0;
	cout<<"Enter the value of N: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		struct node * temp = new node;
		temp -> next = NULL;
		cout<<(i+1)<<" element : ";
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
	cout<<"Inserted List: ";
	print(head);
	merge_sort(&head);
	print(head);
	
	return 0;
}