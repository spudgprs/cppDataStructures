///implementing stacks
#include <iostream>
#include <vector>
using namespace std;
class Stack
{
	int size;
	public:
		vector<int> ve;
		Stack(int size)
		{
			this->size = size;
		}
		void push(int number);
		void pop();
		int peek();
		void display();

};
void Stack::push(int number)
{
	if(ve.size() < size)
		ve.push_back(number);
	else
		cout<<"PUSH: Stack Overflow!\n";
}
void Stack::pop()
{
	if(ve.size()==0)
		cout<<"POP: Stack Underflow!\n";
	else
	{
		cout<<ve[ve.size()-1]<<" popped out\n";
		ve.pop_back();
	}
}
int Stack::peek()
{
	if(ve.size()==0)
		return -1;
	else return ve[ve.size()-1];
}
void Stack::display()
{
	if(ve.size()==0)
		cout<<"Display: Stack Empty!\n";
	else
	{
		cout<<"Stack Elements:\n";
		for(int i=ve.size()-1; i>=0; i--)
			cout<<ve[i]<<endl;
	}
}
int main()
{
	int flag =1;
	cout<<"Enter the Size of the stack: ";
	int size;
	cin>>size;
	Stack * stack = new Stack(size);
	while(flag==1)
	{
		cout<<"Menu:\n1. PUSH\n2. POP\n3. PEEK or TOP\n4. DISPLAY\n5. EXIT\n\nChoice: ";
		int choice=0;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the element to PUSH: ";
				int number;
				cin>>number;
				stack->push(number);
				break;
			case 2:
				stack->pop();
				break;
			case 3:
			{
				int value = stack->peek();
				if(value==-1)
					cout<<"PEEK: Stack is Empty!\n";
				else cout<<"PEEK is "<<value<<endl;
				break;
			}
			case 4:
				stack->display();
				break;
			case 5:
				cout<<"See You again!\n";
				flag =0;
				break;
			default:
				cout<<"Wrong choice in your life\n";
		}
	}
	return 0;
}