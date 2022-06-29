/******************************************************************************
SingleSource Shortest Dist.
*******************************************************************************/
#include <iostream>
#define INFINITY 999
using namespace std;


void dijkstra(int n,int v,int cost[10][10],int dist[10])
{
    int i,u,count,w,flag[10],min;
    for(i=1;i<=n;i++)
    {
        flag[i]=0;
        dist[i]=cost[v][i];//direct dist. w/ IMMEDIATE neighbours
    }
    
    count=2;    //after forming one Edge i.e 2nodes
   
    while(count<=n) //repeat till it covers all nodes
    {
        min=INFINITY;
        for(w=1;w<=n;w++)
        {
            if(dist[w]<min && !flag[w]) //find least dist and flag==0
            {
                min=dist[w];
                u=w;
            }
        }
        
        flag[u]=1;      //u denoted MIN-DIST route!
        count++;
        
        for(w=1;w<=n;w++)
        {
            if( ((dist[u]+cost[u][w])<dist[w]) && !flag[w]) //get indirect dist using MIN-dist
                {
                    dist[w]=dist[u]+cost[u][w];
                }
        }
        
    }
}

int main()
{
    int i,j,v,n,cost[10][10],dist[10];
    cout<<"\n Enter number of node=";
    cin>>n;
    cout<<"\n ENter cost matrix:\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>cost[i][j];
            if(cost[i][j]==0)
                cost[i][j]=INFINITY;
        }
    }
    cout<<"\nEnter SOURCE Vertex:";
    cin>>v;
    dijkstra(n,v,cost,dist);
    
    for(i=1;i<=n;i++)
    if(i!=v)
    cout<<v<<" ->"<<i<<"   Cost="<<dist[i]<<endl;
    return 0;
}