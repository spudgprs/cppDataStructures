//implementaion of Queue using vectors

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
		cout<<ve[0]<<" popped out of the stack\n";
		ve.erase(ve.begin());
	}
}

void front()
{
	if(ve.size()==0)
		cout<<"Not yet Initialised\n";
	else
		cout<<"Front Element: "<<ve[0]<<endl;
	
}
void back()
{
	if(ve.size()==0)
		cout<<"Not yet Initialised\n";
	else
		cout<<"Back Element: "<<ve[ve.size()-1]<<endl;
		
}
void traverse()
{
	if(ve.size()==0)
		cout<<"Nothing to Print\n";
	else
		for(int i=0;i<ve.size();i++)
			cout<<ve[i]<<endl;
}
int main()
{
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