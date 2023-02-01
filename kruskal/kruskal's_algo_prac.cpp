#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
class Edge
{
public:
    int u;
    int v;
    int weight;
    Edge(int w,int x,int y)
    {
        u = x;
        v = y;
        weight = w;
    }
    bool operator<(Edge const& obj)
    {
        return weight<obj.weight;
    }
};
class Kruskal
{
    int parent[50];
    int rank1[50];
    vector<Edge> edges,result;
    int cost;
public:
    Kruskal()
    {
        cost = 0;
    }
    void add_graph(int n)
    {
        for(int i=0;i<n;i++)
        {
            int w,x,y;
            scanf("%d %d %d",&w,&x,&y);
            edges.push_back(Edge(w,x,y));
        }
    }
    int find_set(int v)
    {
        if(v == parent[v])
        {
            return parent[v];
        }
        else
        {
            find_set(parent[v]);
        }
    }
    void sort_vec()
    {
        sort(edges.begin(),edges.end());
    }
    void union_set(int a,int b)
    {
        printf("%d %d\n",a,b);
        int u = find_set(a);
        int v = find_set(b);
        printf("%d %d\n",u,v);
       /* if(u!=v)
        {
            parent[u] = v;
        }*/
        if(rank1[v]>rank1[u])
        {
            parent[a] = b;
            if(b!=v)
            {

                rank1[b]++;
                if(rank1[b]+1 <= rank1[v])
                {
                    printf("Rank increased! of %d\n",b);
                    rank1[v] = rank1[v];
                }
                else
                {
                    printf("Rank increased! of %d %d\n",b,v);
                    rank1[v]++;
                }
                //rank1[v]++;
            }

        }
        else if(rank1[u]>rank1[v])
        {
            parent[b] = a;
            if(a!=u)
            {
                printf("Rank increased! of %d %d\n",a,u);
                rank1[a]++;
                rank1[u]++;
            }
        }
        else
        {
            parent[a] = b;
            if(b!=v)
            {
                printf("Rank increased! of %d %d\n",b,v);
                rank1[b]++;
                rank1[v]++;
            }
            else
            {
                printf("Rank increased! of %d\n",b);
                rank1[b]++;
            }
        }
    }
    void kruskal_alg(int n)
    {

        sort_vec();
        for(int i=0;i<edges.size();i++)
        {
            if(find_set(edges[i].u)!=find_set(edges[i].v))
            {
                cost = cost + edges[i].weight;
                printf("Weight >> %d\n",edges[i].weight);
                result.push_back(edges[i]);

                union_set(edges[i].u,edges[i].v);
            }
        }
    }
    void display(int n)
    {
        for(int i=0;i<result.size();i++)
        {
            printf("%d---%d---%d\n",result[i].u,result[i].weight,result[i].v);
        }
        printf("Cost = %d\n",cost);
        for(int i=0;i<n;i++)
        {
            printf("Parent of %d is <---- %d\n",i,parent[i]);
            printf("Rank of %d is ---- %d\n",i, rank1[i]);
        }
    }
    void make_set(int n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            rank1[i] = 0;
        }
    }
};
int main()
{
    int n,e;
    printf("Enter number of edges & vertices: ");
    scanf("%d %d",&e,&n);
    Kruskal k1;
    k1.add_graph(e);
    k1.make_set(n);
    k1.kruskal_alg(n);
    k1.display(n);
}
