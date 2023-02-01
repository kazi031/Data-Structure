#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int parent[100];
int rank1[100];
//int result[50];
//vector<int>result;
class Edge
{
public:
    int u,v,weight;
    Edge(int w,int x,int y)
    {
        u = x;
        v = y;
        weight = w;
    }
    bool operator<(Edge const& other)
    {
        return weight < other.weight;
    }
};
//vector <pair<int,int> > *adj;
void make_set(int v)
{
    parent[v] = v;
    rank1[v] = 0;
}
/*void add_edge(int u,int v,int w)
{
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}*/
int find_set(int v)
{
    if(v != parent[v])
    {
        parent[v] = find_set(parent[v]);
    }
    return parent[v];
}
void union_set(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a!=b)
    {
        if(rank1[a]>rank1[b])
            parent[b] = a;
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
int main()
{
    vector<Edge>edges,result;
    int n,e;
    int cost = 0;
    edges.push_back(Edge(0,7,8));
    edges.push_back(Edge(1,2,8));
    edges.push_back(Edge(1,7,11));
    edges.push_back(Edge(2,3,7));
    edges.push_back(Edge(2,8,2));
    edges.push_back(Edge(2,5,4));
    edges.push_back(Edge(3,4,9));
    edges.push_back(Edge(3,5,14));
    edges.push_back(Edge(4,5,10));
    edges.push_back(Edge(5,6,2));
    edges.push_back(Edge(6,7,1));
    edges.push_back(Edge(6,8,6));
    edges.push_back(Edge(7,8,7));
    scanf("%d",&n);
    //adj = new vector<pair<int,int> >[n];
    for(int i=0;i<n;i++)
    {
        make_set(i);
    }
    sort(edges.begin(),edges.end());
    for(int i=0;i<edges.size();i++)
    {
        if(find_set(edges[i].u)!=find_set(edges[i].v))
        {
            cost = cost + edges[i].weight;
            result.push_back(edges[i]);
            union_set(edges[i].u,edges[i].v);
        }
    }

    for(int i=0;i<result.size();i++)
    {
        printf("%d---%d---%d\n",result[i].u,result[i].weight,result[i].v);
    }
    printf("Cost = %d\n",cost);
}
