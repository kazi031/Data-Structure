#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
class Graph
{
    vector<int>graph[30];
    vector<int>discovery_time;
    vector<int>finish_time;
    vector<int>colour;
    vector<int>parent;
    vector<int>Q;
    int time;
public:
    void add_graph(int edge)
    {
        int n1,n2;
        printf("Enter nodes n1 & n2:\n");
        for(int i=0;i<edge;i++)
        {
            scanf("%d %d",&n1,&n2);
            graph[n1].push_back(n2);
            //graph[n2].push_back(n1);
        }
    }
    void init(int node)
    {
        for(int i=0;i<node;i++)
        {
            colour.push_back(0);
            discovery_time.push_back(0);
            finish_time.push_back(0);
            parent.push_back(-1);
        }
    }
    void DFS(int n,int e)
    {
        init(n);
        time = 0;
        for(int i=0;i<n;i++)
        {
            if(colour[i]==0)
            {
                dfs_visit(i);
            }
        }
    }
    void dfs_visit(int s)
    {
        colour[s] = 1;
        time++;
        discovery_time[s] = time;
        for(int i=0;i<graph[s].size();i++)
        {
            int v = graph[s][i];
            if(colour[v]==0)
            {
                parent[v] = s;
                dfs_visit(v);
            }
        }
        colour[s] = 2;
        time++;
        finish_time[s] = time;
        Q.push_back(s);
    }
    void print_graph(int node)
    {
        for(int i=0;i<node;i++)
        {
            printf("Adjacent list of node %d",i);
            for(int j=0;j<graph[i].size();j++)
            {
                printf("-->%d",graph[i][j]);
            }
            printf("\n");
        }
        for(int i =0;i<node;i++)
        {
            //printf("Discovery time of node %d >> ",i);
            printf("Node %d >>",i);
            printf("%d/%d\n",discovery_time[i],finish_time[i]);
        }
    }
};
int main()
{
    Graph g;
    g.add_graph(9);
    g.DFS(9,9);
    g.print_graph(9);
}
