#include<iostream>
using namespace std;
int main()
{
    int time=0;
    int p[30],bt[30],arr[30],wt[30],tt[30],i,tq,remain,rt[30],n,flag=0;

    cout<<"\nEnter number of processes : ";
    cin>>n;
    remain=n;
    for(i=1;i<=n;i++)
    {
        cout<<"\nEnter burst time for process "<<i<<": ";
        cin>>bt[i];
        cout<<"\nEnter arrival time for process "<<i<<": ";
        cin>>arr[i];
        p[i]=i;
        rt[i]=bt[i];
    }
    cout<<"\nEnter time quantum : ";
    cin>>tq;
    cout<<"\n\tPROCESS\t\tARRIVAL TIME\tBURST TIME\tWAITING TIME\t\tTURN AROUND TIME";
    for(time=0,i=1;remain!=0;)
    {
         if(rt[i]<=tq&&rt[i]>0)
         {
             time+=rt[i];
             rt[i]=0;
            flag=1;
         }
         else if(rt[i]>0)
         {
             rt[i]-=tq;
             time+=tq;
         }
         if(rt[i]==0&&flag==1)
         {
             remain--;
             wt[i]=time-arr[i]-bt[i];
             tt[i]=time-arr[i];
             cout<<"\n\tP"<<p[i]<<"\t\t"<<arr[i]<<"\t\t\t"<<bt[i]<<"\t\t\t"<<wt[i]<<"\t\t\t"<<tt[i];
flag=0;
         }
         if(i==n)
         i=1;
         else if(arr[i+1]<=time)
         i++;
         else
         i=1;


    }
    int totaltt=0,totalwt=0;
    float avgtt,avgwt;
    for(i=1;i<=n;i++)
    {
        totaltt+=tt[i];
        totalwt+=wt[i];

    }
    avgtt=(float)totaltt/n;
    avgwt=(float)totalwt/n;
    cout<<"\nAverage waiting time : "<<avgwt;
    cout<<"\nAverage turn around time : "<<avgtt;
}


