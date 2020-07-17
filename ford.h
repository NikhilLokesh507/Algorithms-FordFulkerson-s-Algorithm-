#include<bits/stdc++.h>
using namespace std;

static const int V = 10005;

/**
 * @brief the array that stores the parents of the vertices on the s-t path.
 * 
 */
int parent[V];

/**
 * @brief the boolean marker array for convenience of breadth first search.
 * 
 */
bool vis[V];


class Graph{
    public:

        /**
         * @brief The number of vertices in the graph corresponding to the graph object.
         * 
         */
        int v;
        
        /**
         * @brief source vertex.
         * 
         */
        int s;
        /**
         * @brief sink vertex.
         * 
         */
        int t;
        
        /**
         * @brief The adjascency list of the graph.
         * edges[v] contains all the vertices that are neighbours of the vertex 'v'.
         * 
         */
        vector<int> edges[V];
        

        /**
         * @brief map that contains information about the weight of each edge.
         * 
         */
        map<pair<int,int>,double> weight;

        /**
         * @brief s-t cut algo uses bfs to find the augmented path.
         * 
         * @return true if augmented path exists.
         * @return false otherwise
         */

        bool bfs()
        {

            queue<int> q;//this is the queue used for bfs

            q.push(this->s);

            vis[this->s] = true;//marking the source as visited

            parent[this->s] = -1;

            while(!q.empty()){

                int v1 = q.front();

                q.pop();

                for(int ver : edges[v1])
                {
                    if(vis[ver] == true)
                    {
                        continue;
                    }
                    vis[ver] = true;

                    q.push(ver);

                    parent[ver] = v1;
                }
            }

            return vis[t];//returns true if there is an augmented path.
        }
        
        /**
         * @brief The ford fulkerson algorithm.
         * 
         * @return double 
         */
        double fordFulkerson(){

            double m = 0;

            while(this->bfs()){

                double p = INT_MAX;
                
                //iterating each vertex in the s-t cut to find out the bottleneck.
                cout<<"The augmented path : ";
                for(int ver = t;ver != s;ver = parent[ver])
                {
                    cout<<ver<<" -> ";
                    p = min(p , weight[ make_pair(parent[ver] , ver) ]);
                }

                cout<<s<<endl;
                //p is bottleneck

                for(int ver = t;ver != s;ver = parent[ver])
                {
                    //updating the weights of edges.
                    weight[ make_pair(parent[ver] , ver) ] -= p;

                    weight[ make_pair(ver , parent[ver]) ] += p;
                    
                    if(weight[ make_pair(parent[ver] , ver) ] == 0)
                    {
                        auto it = edges[parent[ver]].begin();

                        while(it != edges[parent[ver]].end())
                        {
                            if(*it == ver)
                            {
                                edges[parent[ver]].erase(it);
                                break;
                            }
                            it++;
                        }
                    }
                }
                //updated the weights of the residue graph.
                m += p;

                //reinitializing the boolean marker array.
                memset(vis,false,sizeof(vis));
            }

            return m;
        }


};
