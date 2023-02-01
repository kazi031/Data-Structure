#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<map>
using namespace std;

class Graph
{
    vector<int>graph[100];
    map<string,int>mapped_vertices;
    vector<int>Q;
    vector<int>discovery_time;
    vector<int>finish_time;
    vector<int>colour;
    vector<int>parent;
    int time;
public:
    void add_graph(int edge,int n)
    {
        string v;
        for(int i=0;i<n;i++)
        {
            cin>>v;
            //cout<<v<<endl;
            //mapped_vertices.insert(pair<string,int>(v,i));
            mapped_vertices[v] = i;
            //cout<<v<<" "<<mapped_vertices[v];
            printf("Map of %s is %d\n",&v[0],mapped_vertices[v]);
        }
        int n1,n2;
        /*printf("Enter nodes n1 & n2:\n");
        for(int i=0;i<edge;i++)
        {
            scanf("%d %d",&n1,&n2);
            graph[n1].push_back(n2);
            //graph[n2].push_back(n1);
        }*/
    }
    void init(int n)
    {
        for(int i=0;i<n;i++)
        {
            colour.push_back(0);
            discovery_time.push_back(0);
            finish_time.push_back(0);
            parent.push_back(-1);
        }
    }
    void DFS(int n,int e)
    {
        init(9);
        time = 0;
        for(int i = 0;i<n;i++)
        {
            if(colour[i]==0)
            {
                DFS_VISIT(i);
            }
        }
    }
    void DFS_VISIT(int s)
    {
        colour[s] = 1;
        time = time + 1;
        discovery_time[s] = time;
        for(int i=0;i<graph[s].size();i++)
        {
            int v = graph[s][i];
            if(colour[v]==0)
            {
                parent[v] = s;
                DFS_VISIT(v);
            }
        }
        colour[s] = 2;
        time=time+1;
        finish_time[s] = time;
        Q.push_back(s);
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
        for(int i =0;i<node;i++)
        {
            //printf("Discovery time of node %d >> ",i);
            printf("Node %d >>",i);
            printf("%d/%d\n",discovery_time[i],finish_time[i]);
        }
        /**for(int i =0;i<node;i++)
        {
            printf("Finishing time time of node %d >> ",i);
            printf("%d\n",finish_time[i]);
        }**/
        printf("Topological Sort :\n");
        for(int i=9-1;i>0;i--)
        {
            printf("%d %d/%d\n",Q[i],discovery_time[i],finish_time[i]);
        }
    }
};
int main()
{
    freopen("bfs1.txt","r",stdin);
    freopen("dfs1out.txt","w",stdout);
    Graph g1;
    g1.add_graph(9,9);
    //g1.DFS(9,9);
    //g1.print_graph(9);

}

