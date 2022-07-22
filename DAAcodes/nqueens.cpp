/******************************************************************************
COMPARING (j,x[j]) <==> (k,i)

*******************************************************************************/
#include <iostream>
#include <math.h>
using namespace std;
int x[30],count1=0;

void printSol(int n)
{
    int i,j;
    count1++;
    cout<<"\nSolution #"<<count1<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i]==j)
            cout<<" Q ";
            else
            cout<<" - ";
        }
        cout<<endl;
    }
}



int place(int k,int i)
{
    int j;
    for(j=1;j<=k-1;j++)
    {
        if(x[j]==i ||( abs(x[j]-i)==abs(j-k) ) )
        return 0;
    }    
        return 1;
    
}

void queen(int k,int n)
{
    int i,val;
    for(i=1;i<=n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==n)
            printSol(n);
            else
            queen(k+1,n);
        }
    }
}

int main()
{
    int i,n;
    cout<<"Enter the number of Queens:";
    cin>>n;
    
    queen(1,n);
    cout<<"\nTotal solutionas="<<count1<<endl;

    return 0;
}