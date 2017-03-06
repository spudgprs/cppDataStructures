//construting tree and parsing the tree by iterative and recurcive methods.
#include <iostream>
#include <vector>
using namespace std;
struct node
{
	struct node * left;
	int value;
	struct node * right;
}*root;
struct insertListNode
{
	struct node * current;
	struct insertListNode * next;
}*insertListHead, *insertListTail;
void preOrderRecursive(struct node * root) //same as DFS
{
	if(root)
	{
		cout<<root->value<<" ";
		preOrderRecursive(root->left);
		preOrderRecursive(root->right);
	}
}
void preOrderIterative(struct node * root) //same as DFS
{
	if(root)
	{
		vector<struct node * > ve;
		ve.push_back(root);
		while(ve.size())
		{
			struct node * temp = ve[ve.size()-1];
			cout<<temp->value<<" ";
			ve.pop_back();
			if(temp->right)
				ve.push_back(temp->right);
			if(temp->left)
				ve.push_back(temp->left);
		}
	}
}
void inOrderRecursive(struct node * root)
{
	if(root)
	{
		inOrderRecursive(root->left);
		cout<<root->value<<" ";
		inOrderRecursive(root->right);
	}
}
void inOrderIterative(struct node * root)
{
	struct node * current = root;
	vector<struct node *> ve;
	while(ve.size()>0||current)
	{
		if(current)
		{
			ve.push_back(current);
			current = current->left;
		}
		else
		{
			current = ve[ve.size()-1];
			ve.pop_back();
			cout<<(current->value)<<" ";
			current = current->right;
		}
	}
}
void postOrderRecursive(struct node * root)
{
	if(root)
	{
		postOrderRecursive(root->left);
		postOrderRecursive(root->right);
		cout<<root->value<<" ";
	}
}
void postOrderIterative(struct node * root)
{
	if(root)
	{
		vector<struct node * > ve;
		vector<int> ve1;
		ve.push_back(root);
		while(ve.size())
		{
			struct node * temp = ve[ve.size()-1];
			ve.pop_back();
			ve1.push_back(temp->value);
			if(temp->left)
				ve.push_back(temp->left);
			if(temp->right)
				ve.push_back(temp->right);
		}
		while(ve1.size())
		{
			cout<<ve1[ve1.size()-1]<<" ";
			ve1.pop_back();
		}
	}
}
void bfsRecursive(vector<struct node *> &ve)
{
	if(ve.size()==0)
		return;
	else
	{
		struct node * temp = ve[0];
		ve.erase(ve.begin());
		cout<<temp->value<<" ";
		if(temp->left)
			ve.push_back(temp->left);
		if(temp->right)
			ve.push_back(temp->right);
		bfsRecursive(ve);
	}
}
void bfsIterative(struct node * root)
{
	if(root)
	{
		vector<struct node * > ve;
		ve.push_back(root);
		while(ve.size())
		{
			struct node * temp = ve[0];
			ve.erase(ve.begin());
			cout<<temp->value<<" ";
			if(temp->left)
				ve.push_back(temp->left);
			if(temp->right)
				ve.push_back(temp->right);
		}
	}

}
int main()
{
	int n=0;
	cout<<"Enter the number of nodes N: ";
	cin>>n;
	root = NULL;
	insertListHead = NULL;
	insertListTail = NULL;
	for(int i=0; i<n; i++)
	{
		struct node * n1 = (struct node *)malloc(sizeof(struct node));
		cout<<"Enter the value to insert: ";
		cin>>n1->value;
		n1->left = NULL;
		n1->right = NULL;
		struct insertListNode * iln = (struct insertListNode*)malloc(sizeof(struct insertListNode));
		iln->current = n1;
		iln->next = NULL;
		//checkign for position
		if(!root)
		{
			root = n1;
			insertListHead = iln;
			insertListTail = iln;
		}
		else
		{
			if(insertListHead->current->left!=NULL && insertListHead->current->right!=NULL)
				insertListHead = insertListHead -> next;//first delete the ref by moving th head

			if(insertListHead->current->left==NULL)
				insertListHead->current->left = n1;
			else
				insertListHead->current-> right = n1;

			insertListTail -> next = iln;
			insertListTail = insertListTail->next;
		}

	}
	//traversing
	int flag =1;
	while(flag==1)
	{
		cout<<"\nMenu:\n1. Pre Order Recursive\n2. Pre Order Itertaive\n3. In Order Recursive\n4. In order Iterative\n5. Post Order Recursive";
		cout<<"\n6. Post Order Iterative\n7. BFS Recursive\n8. BFS Iterative\n9. DFS Recursive\n10. DFS Iterative\n11. Exit\nChoice: ";
		int choice =0;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nPre Order Recursive: ";
				preOrderRecursive(root);
				cout<<endl;
				break;
			case 2:
				cout<<"\nPre Order Iterative: ";
				preOrderIterative(root);
				cout<<endl;
				break;
			case 3:
				cout<<"\nIn Order Recursive: ";
				inOrderRecursive(root);
				cout<<endl;
				break;
			case 4:
				cout<<"\nIn Order Iterative: ";
				inOrderIterative(root);
				cout<<endl;
				break;
			case 5:
				cout<<"\nPost Order Recursive: ";
				postOrderRecursive(root);
				cout<<endl;
				break;
			case 6:
				cout<<"\nPost Order Iterative: ";
				postOrderIterative(root);
				cout<<endl;
				break;
			case 7:
			{
				cout<<"\nBFS Recursive: ";
				vector<struct node * > ve;
				ve.push_back(root);
				bfsRecursive(ve);
				cout<<endl;
				break;
			}
			case 8:
				cout<<"\nBFS Iterative: ";
				bfsIterative(root);
				cout<<endl;
				break;
			case 9: //same as DFS
				cout<<"\nDFS Recursive: ";
				preOrderRecursive(root);
				cout<<endl;
				break;
			case 10://same as DFS
				cout<<"\nDFS Iterative: ";
				preOrderIterative(root);
				cout<<endl;
				break;
			case 11:
				flag =0;
				cout<<"See You Again\n";
				break;
			default:
				cout<<"wrong choice in your life\n";
				break;
		}
	}
	return 0;
}