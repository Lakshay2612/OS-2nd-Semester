#include<iostream>
using namespace std;
int main()
{
    int time=0;
    int p[30],bt[30],wt[30],tt[30],pr[30],i,j,pos,temp,n;
    cout<<"\nEnter number of processes : ";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<"\nEnter burst time for process "<<i<<": ";
        cin>>bt[i];
        cout<<"\nEnter priority for process "<<i<<": ";
        cin>>pr[i];
        p[i]=i;
    }
    for(i=1;i<=n;i++)
    {
        pos=i;
        for(j=i+1;j<=n;j++)
        {
            if(pr[j]>pr[pos])
                pos=j;
        }
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
    }
    for(i=1;i<=n;i++)
    {
        wt[i]=time;
        for(j=1;j<=bt[i];j++)
        {
            time++;
            if(j==bt[i])
                tt[i]=time;
        }
    }


    cout<<"\nPROCESS   \tBURST TIME   \tPRIORITY  \tWAITING TIME  \tTURN AROUND TIME";
    for(i=1;i<=n;i++)
    {
        cout<<"\n"<<p[i]<<"\t\t"<<bt[i]<<"\t\t"<<pr[i]<<"\t\t"<<wt[i]<<"\t\t"<<tt[i];
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
