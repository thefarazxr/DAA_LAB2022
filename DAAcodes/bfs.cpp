#include <stdio.h>
#include<iostream>
using namespace std;
int inp[10][10],qu[10],visited[20],i,j,n,f=0,r=-1;

void bfs(int v)
{
    visited[v]=1;
    cout<<v<<"-> ";
    
    while(1)
    {
        for(i=1;i<=n;i++)
        {
            if(inp[v][i]!=0 && visited[i]==0)
            {
                visited[i]=1;
                qu[++r]=i;
            }
        }
        
        if(f>r)
        break;
        
        v=qu[f++];
        cout<<v<<"-> ";
    }
}

int main()
{
    cout<<"\nEnter the number of vertices:";
    cin>>n;
    
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        
    }
    
    cout<<"Enter in  matrix form:\n";
    for (i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>inp[i][j];
            
        }
    }
    
 int v;   
    cout<<"\nEnter the start verted:";
    cin>>v;
    cout<<"\n The nodes which are reachable are:\n";
    bfs(v);
    
    return 0;
}
