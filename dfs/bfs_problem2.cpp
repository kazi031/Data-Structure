#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
//vector<char>g[20];
char g[100][100];
bool visit[100][100];
int ans;
int row,col;
int xx[] = {1,-1,0,0};
int yy[] = {0,0,1,-1};
void dfs(int ux,int uy)
{
    ans++;
    for(int i=0;i<4;i++)
    {
        int vx = ux + xx[i];
        int vy = uy + yy[i];
        if(vx<0 || vy<0 || vx>row || vy>col)
            continue;
        if(visit[vx][vy] == 1 || g[vx][vy] == '#')
            continue;
        if(visit[vx][vy] == 0)
        {
            visit[vx][vy] = 1;
            dfs(vx,vy);
        }
    }
}
int main()
{
    int sx,sy;
    scanf("%d %d",&row,&col);
    getchar();
    memset(visit,0,sizeof(visit));
    for(int i=0;i<row;i++)
    {
        scanf("%s",g[i]);
        for(int j=0;j<col;j++)
        {
            //scanf("%s",g[i]);
            if(g[i][j]=='@')
            {
                sx = i;
                sy = j;
            }
        }
    }
    visit[sx][sy] = 1;
    dfs(sx,sy);
    printf("%d",ans);
}
