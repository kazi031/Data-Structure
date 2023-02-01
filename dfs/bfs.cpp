#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
class Graph
{
    vector<int>graph[100];
    queue<int>Q;
public:
    void add_graph(int edge)
    {
        int n1,n2;
        printf("Enter nodes n1 & n2:\n");
        for(int i=0;i<edge;i++)
        {
            scanf("%d %d",&n1,&n2);
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }
    }
    void print_graph(int node)
    {
        for(int i=0;i<node;i++)
        {
            printf("Adjacent List of node %d",i);
            for(int j=0;j<graph[i].size();j++)
            {
                printf("-->%d",graph[i][j]);
            }
            printf("\n");
        }
    }
    void bfs(int s,int n)
    {
        int u;
        int distance[10];
        int parent[10];
        int colour[10];
        for(int i=0;i<n;i++)
        {
            if(i==s)
            {
                continue;
            }
            else
            {
                colour[i]=0;
                distance[i]=-1;
                parent[i]=NULL;
            }
        }
        colour[s]=1;
        distance[s]=0;
        parent[s]=-1;
        Q.push(s);
        while(Q.size()!=0)
        {
            u=Q.front();
            Q.pop();
            printf("%d ",u);
            for(int i=0;i<graph[u].size();i++)
            {
                int v = graph[u][i];
                if(colour[v]==0)
                {
                    colour[v] = 1;
                    distance[v] = distance[u]+1;
                    parent[v] = u;
                    Q.push(v);
                }
            }
            colour[u] = 2;
        }
        printf("\n");
        for(int i=0;i<n;i++)
        {
            printf("The distance of %d node is %d\n",i,distance[i]);
            printf("The colour of %d is %d\n",i,colour[i]);
            printf("Parent of %d node is %d\n",i,parent[i]);
        }
    }
};
int main()
{
    /*freopen("bfs.txt","r",stdin);
    freopen("bfsout.txt","w",stdout);*/
    int n,e;
    printf("Enter The number of nodes:");
    scanf("%d",&n);
    printf("Enter The number of edge:");
    scanf("%d",&e);
    Graph g;
    g.add_graph(e);
    g.print_graph(n);
    g.bfs(0,n);
}
