/******************************************************************************
TSP BruteForce
*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int a[5][5];
    cout<<"Adj matrix with 4 vertices:\n";
    for(int i=1;i<5;i++)
    {
        for(int j=1;j<5;j++)
        {
            cin>>a[i][j];
        }
    }
    //brutely chekcing for all combinations of 1 - - - 1
    int temp[6][5]={
                    {1,2,3,4,1},{1,2,4,3,1},
                    {1,3,2,4,1},{1,3,4,2,1},
                    {1,4,3,2,1},{1,4,2,3,1}
                    };
                    
    int mincost=999999;
    int minr=0;
    
    for(int i=0;i<6;i++)
    {
        int cost=0;
        int flag=1;
        for(int j=0;j<4;j++) //adds up the 4pairs in the route! <5 elemnts forming 4 seq pairs>
        {
            if(a[temp[i][j]][temp[i][j+1]]!=0)
            {
                cost+=a[temp[i][j]][temp[i][j+1]];
            }
            else
            {
                flag=0;break;
            }
        }
        
        if(flag)
        {
            if(cost<mincost)
            {
                mincost=cost;
                minr=i;
            }
        }
    }
    cout<<"Min cost path=\n";
    for(int k=0;k<5;k++)
    {
        cout<<temp[minr][k]<<"-->";
    }
    cout<<"\n Minimum Cost= "<<mincost;
    
    return 0;
}