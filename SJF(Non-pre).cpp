#include <iostream>

using namespace std;
int time=0;
int main()
{
    int b[20],p[20],n,i,j,wt[20],tw=0,taround[20],tt=0,total=0,pos,temp;
    float aww,att;
    cout<<"\nEnter number of processes : ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter the burst time of process : "<<i+1<<"=>";
        cin>>b[i];
        p[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(b[j]<b[pos])
            {
                pos=j;
            }

        }
        temp=b[i];
        b[i]=b[pos];
        b[pos]=temp;
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;//waiting time for first process will be zero
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=b[j];
        total+=wt[i];
    }
    aww=(float)total/n;
    total=0;
    cout<<"\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURN AROUND TIME";
    //calculating turn around time
    for(i=0;i<n;i++)
    {
        taround[i]=b[i]+wt[i];
        total+=taround[i];
        cout<<"\nP"<<p[i]<<"\t\t"<<b[i]<<"\t\t"<<wt[i]<<"\t\t"<<taround[i];

    }
    att=(float)total/n;
    cout<<"\nAverage waiting time : "<<aww;
    cout<<"\nAverage turnaround time : "<<att;

}

