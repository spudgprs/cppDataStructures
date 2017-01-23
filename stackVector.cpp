//implemenation of stacks using vectors
#include <iostream>
#include <vector>
using namespace std;
vector<int> ve;
void push()
{
	cout<<"Element : ";
	int element =0;
	cin>>element;
	ve.push_back(element);
}
void pop()
{
	if(ve.size()==0)
		cout<<"Underflow!\n";
	else
	{
		cout<<ve[ve.size()-1]<<" popped out of the stack\n";
		ve.pop_back();
	}
}
void peek()
{
	if(ve.size()==0)
		cout<<"Underflow!\n";
	else
		cout<<"Top Element: "<<ve[ve.size()-1]<<endl;
	
}
void traverse()
{
	if(ve.size()==0)
		cout<<"Nothing to Print\n";
	else
		for(int i=ve.size()-1;i>=0;i--)
			cout<<ve[i]<<endl;
}
int main()
{
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