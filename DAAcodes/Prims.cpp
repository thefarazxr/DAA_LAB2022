/******************************************************************************
PRIM'S ALGO
*******************************************************************************/
#include <iostream>
using namespace std;
int n,i,j,a,b,u,v,ne=1,k,l,minval=999,minj;
int cost[10][10],t[10][2],near[15],mincost=0,mini=999,visited[10]={0};

int main()
{
cout<<"\n Enter no of nodes:";
cin>>n;
cout<<"\n ENter Adjacency Matrix:\n";

for(i=1;i<=n;i++)
{
    for(j=1;j<=n;j++)
    {
        cin>>cost[i][j];
    if(cost[i][j]==0)
        cost[i][j]=999;
    }
}

for(i=1;i<=n;i++)
{
    for(j=1;j<=n;j++)
    {
        if(cost[i][j]<mini)
        {
            k=i;
            l=j;
            mini=cost[i][j];
        }
    }
}
mincost=cost[k][l];
t[1][1]=k;
t[1][2]=l;

for(i=1;i<=n;i++)
{
    if(cost[i][l]<cost[i][k])
    near[i]=l;
    else
    near[i]=k;
}
near[k]=near[l]=0;//make them 0 after joining!

for(i=2;i<=n-1;i++)
{
    for(j=1;j<=n;j++)
    {
        if(near[j]!=0 &&cost[j][near[j]]<minval)
        {
            minval=cost[j][near[j]];
            minj=j;
        }
    }
    t[i][1]=minj;
    t[i][2]=near[minj];
    
    mincost+=cost[minj][near[minj]];
    near[minj]= 0;
    
    for(k=1;k<=n;k++)
    {
        if(near[k]!=0&& cost[k][near[k]]>cost[k][minj])
        near[k]=minj;
    }
    minval=999;
}

cout<<"\n MIn cost="<<mincost;
cout<<"\n Min Spanning Tree=\n";
for(i=1;i<n;i++)
{
    cout<<"\n"<<t[i][1]<<"\t"<<t[i][2];
}
    return 0;
}
