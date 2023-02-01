#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
class Graph
{
   vector<int>graph[10];
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
    void print_graph(int n)
    {
         for(int i=0;i<n;i++)
         {
             printf("%d",i);
             for(int j=0;j<graph[i].size();j++)
             {
                 printf("-->%d",graph[i][j]);
             }
             printf("\n");
         }
    }
    int bfs(int s,int n)
    {
        int u;
        int distance[10];
        int parent[10];
        int colour[10];
        for(int i=0;i<n;i++)
        {
            if(i==s)
                continue;
            else
            {
                distance[i]=-1;
                parent[i]=NULL;
                colour[i]=0;
            }
        }
        distance[s]=0;
        parent[s]=-1;
        colour[s]=1;
        Q.push(s);
        while(Q.size()!=0)
        {
            u = Q.front();
            Q.pop();
            for(int i=0;i<graph[u].size();i++)
            {
                int v = graph[u][i];
                if(colour[v]==0)
                {
                    colour[v] = 1;
                    parent[v] = u;
                    distance[v] = distance[u]+1;
                    Q.push(v);
                }
            }
            colour[u] = 2;
        }
        return distance[n-1];
    }
};
int main()
{
    Graph g1;
    int edge;
    scanf("%d",&edge);
    int N;
    scanf("%d",&N);
    g1.add_graph(edge);
    g1.print_graph(N);
    cout<<g1.bfs(0,N);
}
