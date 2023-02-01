#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int xx[] = {1,-1,0,0};
int yy[] = {0,0,1,-1};
class Graph_dfs
{
    vector<char> *adj;
    vector<int> *visit;
    int row;
    int col;
    int ans;
public:
    Graph_dfs(int r,int c)
    {
        row = r;
        col = c;
        adj = new vector<char>[row];
        visit = new vector<int>[row];
        ans = 0;
    }
    void add_graph()
    {
        for(int i=0;i<row;i++)
        {
            getchar();
            for(int j=0;j<col;j++)
            {
                visit[i].push_back(0);
                char temp;
                scanf("%c",&temp);
                adj[i].push_back(temp);
            }
        }
    }
    int dfs_visit(int sx,int sy)
    {
        //visit[sx][sy] = 1;
        DFS(sx,sy);
        return ans;
    }
    int DFS(int ux,int uy)
    {
        for(int i=0;i<4;i++)
        {
            int vx = ux + xx[i];
            int vy = uy + yy[i];
            if(vx<0 || vy<0 || vx>=row || vy>=col)
            {
                continue;
            }
            else if(visit[vx][vy]==1 || adj[vx][vy]=='#')
            {
                continue;
            }
            else
            {
                visit[vx][vy] = 1;
                //printf("(%d,%d)\n",vx,vy);
                if(adj[vx][vy]=='C')
                    ans++;
                DFS(vx,vy);

            }
        }
    }
    void print_graph()
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                printf("%c",adj[i][j]);
            }
            printf("\n");
        }
    }
};
int main()
{
    freopen("Crystal.txt","r",stdin);
    freopen("Crystal_out.txt","w",stdout);
    int r,c,q;
    scanf("%d %d %d",&r,&c,&q);
    int * f;
    Graph_dfs d1(r,c);
    d1.add_graph();
    f = new int[q];
    for(int i=0;i<q;i++)
    {
        int ux,uy;
        scanf("%d %d",&ux,&uy);
        f[i] = d1.dfs_visit(ux,uy);
    }
    //int x = d1.dfs_visit(4,1);
    d1.print_graph();
    //printf("%d\n",x);
    int * cj = new int[q];
    for(int i=1;i<q;i++)
    {
        cj[i] = f[i] - f[i-1];
    }
    cj[0] = f[0];
    for(int i=0;i<q;i++)
    {
        printf("%d\n",cj[i]);
    }
    delete [] f;
    delete [] cj;
}
