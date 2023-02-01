#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> ipair;
class Prim
{
    int V;
    vector<ipair> *adj;
public:
    Prim(int v)
    {
        this->V = v;
        adj = new vector<ipair>[v];
    }
    void add_edge(int u,int v,int w)
    {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    void primMST()
    {
        priority_queue<ipair,vector<ipair>,greater<ipair>>pq;
        int source = 0;
        vector<int>key(V,9999);
        vector<bool>inMST(V,false);
        vector<int>parent(V,-1);
        pq.push(make_pair(0,source));
        key[source] = 0;
        while(pq.size()!=0)
        {
            int u = pq.top().second;
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
                    pq.push(key[v],v);
                }
            }
        }
    }

};
