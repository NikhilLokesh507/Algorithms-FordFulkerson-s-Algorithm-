#include<bits/stdc++.h>
#include"ford.h"
using namespace std;
int main(){
    Graph gr;
    cout<<"hello \n";
    cout<<"Please enter the number of vertices the source vertex and the sink vertex"<<endl;

    cin >> gr.v >> gr.s >> gr.t;


    cout<<"Please enter the number of edges"<<endl;

    int e;
    //the number of edges.
    cin>>e;

    cout<<"Enter the edges : \n";

    int ver1,ver2;

    double w;

    for(int i = 0;i < e;i++){

        //taking input.
        cin >> ver1 >> ver2 >> w;
        //initializing the adjascency list
        gr.edges[ver1].push_back(ver2);
        gr.edges[ver2].push_back(ver1);

        gr.weight[make_pair(ver1,ver2)] = w;
    }
    cout<<endl<<"The Maximal flow is : "<<gr.fordFulkerson()<<endl;
}