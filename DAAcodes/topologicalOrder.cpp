#include <iostream>
using namespace std;

int a[10][10],indegree[10],n;

void find_indegree()
{
    int i,j,sum;
    for(j=1;j<=n;j++)
    { sum=0;
        for(i=1;i<=n;i++)
        {
            sum+=a[i][j];
        }
        indegree[j]=sum;
    }  
    
    //  for(i=1;i<=n;i++)
    //  cout<<indegree[i];
}
void toplogy()
{
    int i,u,v,t[10],s[10],top=-1,k=0;
    find_indegree();
    for(i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        s[++top]=i;
    }
    
    while(top!=-1)
    {
        u=s[top--];
        //cout<<u;
        t[k++]=u;
        for(v=1;v<=n;v++)
        {
            if(a[u][v]==1)
            {
                indegree[v]--;
                if(indegree[v]==0)
                    s[++top]=v;
            }
        }
    }
   
    cout<<"toplogical sequence=\n";
    for(i=0;i<n;i++)
    cout<<t[i]<<"-->";
}
 
int main()
{   int i,j;
    cout<<"Enter no. of nodes=";
    cin>>n;
    cout<<"\nEnter adj matrix:\n";
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>a[i][j];
    
    toplogy();
    return 0;
}