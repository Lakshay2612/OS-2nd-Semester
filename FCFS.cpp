#include <iostream>

using namespace std;
int time=0;
int main()
{
    int b[20],n,i,j,w[20],tw=0,taround[20],tt=0;
    float aww,att;
    cout<<"\nEnter number of processes : ";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<"\nEnter the burst time of process : "<<i<<"=>";
        cin>>b[i];

    }
    for(i=1;i<=n;i++)
    {
        w[i]=time;
       for(j=1;j<=b[i];j++)
       {
           time++;
           if(j==b[i])
            taround[i]=time;
       }
    }
    for(i=1;i<=n;i++)
    {
        tw=tw+w[i];
    }
    aww=float(tw)/n;
    for(i=1;i<=n;i++)
    {
        tt=tt+taround[i];
    }
    att=float(tt)/n;
    cout<<"\nAverage waiting time : "<<aww;
    cout<<"\nAverage turnaround time : "<<att;

}
