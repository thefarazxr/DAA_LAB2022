
#include <iostream>
#include<stdio.h>
using namespace std;
int inp[10][10],reach[20],n;

void dfs(int v)
{
    int i;
    reach[v]=1;
    for(i=1;i<=n;i++)
    {
        if (inp[v][i]!=0 && !reach[i])
        {
            cout<<"\n"<<v<<" ->"<<i<<endl;
            dfs(i);
        }
    }
}
int main()
{
int i,j,count=0;    
    cout<<"\n Enter the number of vertices:";
    cin>>n;
   
    for(i=1;i<=n;i++)
    {
        reach[i]=0;
    }
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>inp[i][j];
        }
    }
    
    dfs(1);
    cout<<endl;
    for(j=1;j<=n;j++)
    {
        if(reach[j])
            count++;
    }
if(count==n)
cout<<"The graph is CONNECTED!";
else
cout<<"The graph is NOT CONNECTED";
    
    return 0;
}