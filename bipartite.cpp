#include<bits/stdc++.h>
using namespace std;
#include"ford.h"
int main(){
	Graph gr;
	
	cout << "Enter the number of vertices in the bipartite graph : ";
	cin >> gr.v;
	
	cout << "Enter the number of edges of the graph : ";

	int e;
	cin >> e;

	cout <<  "Enter the edges : \n";

	//two sets that contain the vertices of each of the sets in the bipartite sets.
	set<int> v1,v2;

	while(e--)
	{

		//taking the input of all edges between the sets.
		int ver1,ver2;
		cin >> ver1 >> ver2;

		//adjascency list initializing.
		gr.edges[ver1].push_back(ver2);
		gr.edges[ver2].push_back(ver1);

		//intializing weights of the edge.
		gr.weight[make_pair(ver1,ver2)] = 1;

		v1.insert(ver1);
		v2.insert(ver2);
	}

	gr.s = gr.v + 1;//the source vertex intialized seperately
	gr.t = gr.v + 2;//the sink vertex intialized seperately
	gr.v += 2;


	for(int vertex : v1)
	{
		gr.edges[gr.s].push_back(vertex);
		gr.edges[vertex].push_back(gr.s);
		gr.weight[make_pair(gr.s , vertex)] = 1;
	}
	
	for(int vertex : v2)
	{
		gr.edges[vertex].push_back(gr.t);
		gr.edges[gr.t].push_back(vertex);
		gr.weight[make_pair(vertex , gr.t)] = 1;
	}

	cout<<endl<<gr.fordFulkerson()<<endl;
}