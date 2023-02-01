#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> iPair;
class Graph
{
    int V;
    vector<iPair > *adj;
public:
    Graph(int V)
    {
        this->V = V;
        adj = new vector< iPair >[V];
    }
    void addEdge(int u,int v,int w)
    {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    void primMST()
    {
        priority_queue< iPair , vector< iPair > , greater< iPair > >pq;
        int source = 0;
        vector<int> key(V,9999);
        vector<bool> inMST(V,false);
        vector<int>parent(V,-1);
        pq.push(make_pair(0,source));
        key[source] = 0;
        while(pq.size()!=0)
        {
            int u = pq.top().second;
           // printf("%d\n",u);
            pq.pop();
            inMST[u] = true;
            for(int i=0;i<adj[u].size();i++)
            {
                int v = adj[u][i].first;
                int weight = adj[u][i].second;
                if(inMST[v]==false && key[v]>weight)
                {
                    parent[v] = u;
                    key[v] = weight;
                    pq.push(make_pair(key[v],v));
                }
            }
        }
        for(int i=1;i<V;i++)
        {
            printf("%d - %d\n",parent[i],i);
        }
    }
    ~Graph()
    {
        delete [] adj;
    }
};
int main()
{
    int ver = 7;
    //scanf("%d",&ver);
    Graph g(7);
    /*for(int i=0;i<edge;i++)
    {
        int ver1,ver2,weight;
    }*/
    g.addEdge(0,1,28);
    g.addEdge(0,5,10);
    g.addEdge(5,4,25);
    g.addEdge(1,6,14);
    g.addEdge(1,2,16);
    g.addEdge(2,3,12);
    g.addEdge(6,3,18);
    g.addEdge(4,3,22);
    g.addEdge(4,6,24);
    //g.addEdge(0,1,28);
    g.primMST();
}
