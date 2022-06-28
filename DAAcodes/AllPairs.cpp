/******************************************************************************
All Pairs FLOYD

*******************************************************************************/
#include <iostream>
using namespace std;
int min(int a,int b)
{
    if(a<b)
        return a;
    else
    return b;
}

void floyd(int cost[10][10],int n)
{
    int i,j,k; 
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);  
            }
        }
    }
}


int main()
{
    int cost[10][10],i,j,n;
    
    cout<<"Number of vertices=";
    cin>>n;
    cout<<"\nAdj matrix=";
    for(i=1;i<=n;i++)
    {
            for(j=1;j<=n;j++)
            {
                cin>>cost[i][j];
                if(i!=j && cost[i][j]==0)
                    cost[i][j]=999;
            }
    }
    cout<<"\n I/P data MATRIX =\n";
    for(i=1;i<=n;i++)
    {
            for(j=1;j<=n;j++)
            {
                cout<<cost[i][j]<<"  ";
            }
        cout<<endl;
    }
    
    floyd(cost,n);
    
 cout<<"\n All-Shortest Path  MATRIX =\n";
    for(i=1;i<=n;i++)
    {
            for(j=1;j<=n;j++)
            {
                cout<<cost[i][j]<<"  ";
            }
        cout<<endl;
    }
    return 0;
}