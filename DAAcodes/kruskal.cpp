// KRUSKAL's ALgorithm!
#include <iostream>
#include<stdio.h>
using namespace std;

int a[20][20];
int p[20];
int ne=1;
void Union(int,int);
int find(int);
int mincost=0,cmin=999;

int main()
{
    int i,j,n,v1,v2,u,v;
    cout<<"Numb of vertices:";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        p[i]=-1; //p-> denotes parent
    }
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==0)
                a[i][j]=999;
        }
    }
    
    cout<<"\nMin Cost ST= \n";
    while(ne<n) //in MinST noOFEdges=(V-1)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[i][j]<cmin)
                {
                    v1=i;v2=j;
                    cmin=a[i][j];
                }
            }
        }
        //from all combinations we get a cmin wrep. v1,v2;
            u=find(v1);
            v=find(v2);
            if(u!=v)
            {
                Union(u,v);
                mincost+=a[v1][v2];
                cout<<"("<<v1<<","<<v2<<" =>"<<a[v1][v2]<<endl;
                ne++;
            }
            cmin=999;
            a[v1][v2]=999;
            a[v2][v1]=999;
    }
        cout<<"\nMinCOst="<<mincost<<endl;
        return 0;
}
    
    
    void Union(int m,int n)
    {
        p[m]=n;
    }
    
    int find(int i)
    {
        while(p[i]!=-1)
        {
            i=p[i];
        }
        return i;
    }
