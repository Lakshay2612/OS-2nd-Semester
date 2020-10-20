#include<iostream>
using namespace std;
int main()
{
    int time=0,smallest;
    int arr[30],p[30],bt[30],wt[30],tt[30],pr[30],rt[30],i,j,pos,temp,n;
    cout<<"\nEnter number of processes : ";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<"\nEnter burst time for process "<<i<<": ";
        cin>>bt[i];
        cout<<"\nEnter priority for process "<<i<<": ";
        cin>>pr[i];
        cout<<"\nEnter arrival time for process "<<i<<": ";
        cin>>arr[i];
        p[i]=i;
        rt[i]=bt[i];
    }
    pr[0]=0;
    int remain =n;
    for(time=0;remain!=0;time++)
        {
            smallest=0;
                for(i=1;i<=n;i++)
                {
                    if(arr[i]<=time && pr[i]>pr[smallest] && rt[i]>0)
                        {
                            smallest=i;
                        }
                }
            rt[smallest]--;
                if(rt[smallest]==0)
                {
                    remain--;

                    wt[smallest]=time+1-arr[smallest]-bt[smallest];
                    tt[smallest]=time+1-arr[smallest];
                }
        }
    cout<<"\nPROCESS   \tARRIVAL TIME   \tBURST TIME   \tPRIORITY  \tWAITING TIME  \tTURN AROUND TIME";
    for(i=1;i<=n;i++)
    {
        cout<<"\n"<<p[i]<<"\t\t"<<arr[i]<<"\t\t"<<bt[i]<<"\t\t"<<pr[i]<<"\t\t"<<wt[i]<<"\t\t"<<tt[i];
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
