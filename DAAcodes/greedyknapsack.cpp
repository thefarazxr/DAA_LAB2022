/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

void Knapsack(int num,float weight[],float profit[],float capacity)
{
    float x[20],tp=0,remCap;    //tp=>tempProfit
    int i,j;
    
    remCap=capacity;
    for(i=0;i<num;i++)
    x[i]=0.0;
    
    for(i=0;i<num;i++)
    {
        if(weight[i]>remCap)    //if currWt>capacity
        break;
        else
        {
            x[i]=1.0;       //for weight=1 
            tp=tp+profit[i];
            remCap-=weight[i];
        }
    }
    
    if(i<num)       //using fractional weight
    {
        x[i]=remCap/weight[i];
        tp+=(x[i]*profit[i]);
    }
    
    cout<<"\nResult Weight Ditribution=";
    for(i=0;i<num;i++)
    cout<<x[i];
    
    cout<<"Max profit="<<tp;
    
}


int main()
{
float weight[20],profit[20],capacity,ratio[20],temp;
int i,j,num;

cout<<"Enter the number of OBjects:";
cin>>num;

cout<<"\n Enter weights of"<<num<<"objects: ";
for(i=0;i<num;i++)
    cin>>weight[i];
    
cout<<"\n Enter profits of"<<num<<"objects: ";
for(i=0;i<num;i++)
    cin>>profit[i];
    
    cout<<"\n Enter Knapsack Capacity";
    cin>>capacity;

for(i=0;i<num;i++)
 ratio[i]=profit[i]/weight[i];
 
for(i=0;i<num;i++)
{
    for(j=0;j<num-1-i;j++)
    {                       //using BUBBLE SORT!           
        if(ratio[j]<ratio[j+1])
        {
            temp=ratio[j];
            ratio[j]=ratio[j+1];
            ratio[j+1]=temp;
            
            temp=weight[j];
            weight[j]=weight[j+1];
            weight[j+1]=temp;
            
            temp=profit[j];
            profit[j]=profit[j+1];
            profit[j+1]=temp;
        }
    }
}

Knapsack(num,weight,profit,capacity);
    return 0;
}