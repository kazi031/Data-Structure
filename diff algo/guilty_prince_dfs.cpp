#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int xx[]= {1,-1,0,0};
int yy[]= {0,0,1,-1};
class Program
{
    int r;
    int c;
    vector <char> *obj;
    int sx,sy;
    vector <int> *visit;
    int ans;
public:
    Program(int row,int col)
    {
        sx = 0;
        sy = 0;
        r = row;
        c = col;
        obj = new vector <char>[r];
        visit = new vector <int>[r];
        ans = 0;
    }
    void add_graph()
    {
        for(int i=0;i<r;i++)
        {
            getchar();
            for(int j=0;j<c;j++)
            {
                visit[i].push_back(0);
                char temp;
                scanf("%c",&temp);
                if(temp == '@')
                {
                    sx = i;
                    sy = j;
                }
                obj[i].push_back(temp);
            }
        }
        //printf("%d %d",sx,sy);
    }
    void DFS(int ux,int uy)
    {

        for(int i=0;i<4;i++)
        {
            int vx = ux + xx[i];
            int vy = uy + yy[i];
            if(vx<0 || vy<0 || vx>=r || vy>=c)
            {
                continue;
            }
            else if(visit[vx][vy]==1 || obj[vx][vy]=='#')
            {
                continue;
            }
            else
            {
                ans++;
                visit[vx][vy] = 1;
                DFS(vx,vy);
            }
        }
    }
    void DFS_Vis()
    {
        DFS(sx,sy);
        printf("\n%d\n",ans);
    }
    void print_graph()
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                printf("%c",obj[i][j]);
            }
            printf("\n");
        }
    }
};
int main()
{
    freopen("prince.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    vector <char> *obj;
    int W,H;
    //printf("Enter W , H>>");
    scanf("%d %d",&W,&H);
    Program p1(H,W);
    p1.add_graph();
    p1.print_graph();
    p1.DFS_Vis();

}
