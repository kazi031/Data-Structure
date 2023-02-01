#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
class Edge
{
public:
    int u,v,len;
    Edge(int x,int y,int l)
    {
        u = x;
        v = y;
        len = l;
    }
    bool operator<(Edge const& p)
    {
        return len<p.len;
    }
    void Print_Edge()
    {
        printf("(%d,%d,%d)",u,v,len);
    }
};
class Graph
{
    vector<Edge> adj,result;
    vector<int> parent,rank1;
    int node;
    int edge;
    int cost;
    int total;
public:
    Graph(int n,int e)
    {
        node = n;
        edge = e;
        cost = 0;
        total = 0;
    }
    void add_graph()
    {
        for(int i=0;i<edge;i++)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            total = total + z;
            adj.push_back(Edge(x,y,z));
        }
    }
    void print_graph()
    {
        for(int i=0;i<adj.size();i++)
        {
            printf("%d--%d--%d\n",adj[i].u,adj[i].len,adj[i].v);
        }
         printf("OUTPUT >> \n");
        for(int i=0;i<result.size();i++)
        {
            printf("%d--%d--%d\n",result[i].u,result[i].len,result[i].v);
        }
    }
    void make_set()
    {
        for(int i=0;i<edge;i++)
        {
            parent.push_back(i);
            rank1.push_back(0);
        }
    }
    int find_set(int v)
    {
        if(parent[v]==v)
        {
            return parent[v];
        }
        else
        {
            find_set(parent[v]);
        }
    }
    void union_set(int a,int b)
    {
        a = find_set(a);
        b = find_set(b);
        if(a!=b)
        {
            if(rank1[a]>rank1[b])
            {
                parent[b] = a;
            }
            else
            {
                parent[a] = b;
            }
            if(rank1[a]==rank1[b])
            {
                rank1[b]++;
            }
        }
    }
    int kruskal()
    {
        sort(adj.begin(),adj.end());
        //print_graph();
        for(int i=0;i<adj.size();i++)
        {
            if(find_set(adj[i].u)!=find_set(adj[i].v))
            {
                cost = cost + adj[i].len;
                result.push_back(adj[i]);
                union_set(adj[i].u,adj[i].v);
            }
        }
        printf("%d\n",total-cost);
    }
};
int main()
{
    freopen("Drk.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    int n,e;
    scanf("%d %d",&n,&e);
    Graph g1(n,e);
    g1.add_graph();
    g1.make_set();
    g1.kruskal();
    g1.print_graph();
}
