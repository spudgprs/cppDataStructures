//creating graphs using adjacency list
#include <iostream>
#include <vector>
using namespace std;
struct adjListNode
{
	int value;
	struct adjListNode * next;
};

struct graph
{
	int v;
	vector<struct adjListNode *> ve;
};
void printGraph(struct graph * g)
{
	cout<<"Graph nodes and Edges:"<<endl;
	for(int v=0;v<g->v;v++)
	{
		struct adjListNode * crawl = g->ve[v];
		cout<<v<<" : ->";
		while(crawl)
		{
			cout<<crawl->value<<" -> ";
			crawl = crawl ->next;
		}
		cout<<"NULL"<<endl;
	}
}
struct graph * create_graph(int v)
{
	struct graph * g= new graph;
	g->v = v;
	g->ve.resize(v);
	for(int i=0;i<v;i++)
		g->ve[i] = NULL;
	return g;
}
void addEdge(struct graph * g, int source, int destination)
{
	//add edge from source ->destination
	struct adjListNode * node = new adjListNode;
	node-> value = destination;
	node-> next = g->ve[source];
	g->ve[source] = node;

	//add edge from dest->source
	struct adjListNode * node1 = new adjListNode;
	node1-> value = source;
	node1-> next = g->ve[destination];
	g->ve[destination] = node1;
}
int main()
{
	int v=0, e=0;
	cout<<"Enter the number of Vertices V: ";
	cin>>v;
	//creaete a graph with v vertices;
	struct graph * g = create_graph(v);
	cout<<"Enter the number of edges E: ";
	cin>>e;
	for(int i=0;i<e;i++)
	{
		int source, destination;
		cout<<(i+1)<<" edge source and detination : ";
		cin>>source>>destination;
		addEdge(g, source, destination);
	}
	printGraph(g);
	return 0;
}