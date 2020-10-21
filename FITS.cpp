#include<iostream>
using namespace std;

void first_fit(int pr[],int np,int hsize[],int nh)
{
    int inf=0,exf=0,flag[30]={0},i,j;
    for(i=1;i<=np;i++)
    {
        for(j=1;j<=nh;j++)
        {
            if(flag[j]==0&&pr[i]<=hsize[j])
            {
                flag[j]=1;
                inf+=hsize[j]-pr[i];
                cout<<"\n"<<pr[i]<<" KB process mapped to "<<hsize[j]<<" KB hole ";
                break;
            }
        }
        if(j==nh+1)
            cout<<"\nNo space for process number "<<i<<" which requires "<<pr[i]<<" KB";

    }
    for(i=1;i<=nh;i++)
    {
        if(flag[i]==0)
            exf+=hsize[i];

    }
    cout<<"\n\nPROCESSES::";
    for(i=1;i<=np;i++)
        cout<<"  "<<pr[i];

    cout<<"\n\nMEMORY HOLES::";
    for(i=1;i<=nh;i++)
        cout<<"  "<<hsize[i];
    cout<<"\n\nTOTAL SUM OF INTERNAL FRAGMENTATION : "<<inf;
    cout<<"\n\nTOTAL SUM OF EXTERNAL FRAGMENTATION : "<<exf;

}
void best_fit(int pr[],int np,int hsize[],int nh)
{
    int temp1[30],inf=0,exf=0,flag[30]={0},i,j;
    for(i=1;i<=nh;i++)
        temp1[i]=hsize[i];
    for(i=1;i<=nh-1;i++)
        {
            for(j=1;j<=nh-1;j++)
            {
                if(hsize[j]>hsize[j+1])
                    {
                    int temp=hsize[j];
                    hsize[j]=hsize[j+1];
                    hsize[j+1]=temp;
                    }
            }
        }//For sorting the holes according to their sizes
    for(i=1;i<=np;i++)
    {

        for(j=1;j<=nh;j++)
        {
            if(flag[j]==0&&pr[i]<=hsize[j])
            {
                flag[j]=1;
                inf+=hsize[j]-pr[i];
                cout<<"\n"<<pr[i]<<" KB process mapped to "<<hsize[j]<<" KB hole ";
                break;
            }
        }
        if(j==nh+1)
            cout<<"\nNo space for process number "<<i<<" which requires "<<pr[i]<<" KB";

    }
    for(i=1;i<=nh;i++)
    {
        if(flag[i]==0)
            exf+=hsize[i];

    }
    cout<<"\n\nPROCESSES::";
    for(i=1;i<=np;i++)
        cout<<"  "<<pr[i];

    cout<<"\n\nMEMORY HOLES::";
    for(i=1;i<=nh;i++)
        cout<<"  "<<temp1[i];
    cout<<"\n\nTOTAL SUM OF INTERNAL FRAGMENTATION : "<<inf;
    cout<<"\n\nTOTAL SUM OF EXTERNAL FRAGMENTATION : "<<exf;

}
void worst_fit(int pr[],int np,int hsize[],int nh)
{
    int inf=0,exf=0,flag[30]={0},temp1[30],i,j;
    for(i=1;i<=nh;i++)
        temp1[i]=hsize[i];
    for(i=1;i<=nh-1;i++)
        {
            for(j=1;j<=nh-1;j++)
            {
                if(hsize[j]<hsize[j+1])
                    {
                    int temp=hsize[j];
                    hsize[j]=hsize[j+1];
                    hsize[j+1]=temp;
                    }
            }
        }//For sorting the
    for(i=1;i<=np;i++)
    {
        for(j=1;j<=nh;j++)
        {
            if(flag[j]==0&&pr[i]<=hsize[j])
            {
                flag[j]=1;
                inf+=hsize[j]-pr[i];
                cout<<"\n"<<pr[i]<<" KB process mapped to "<<hsize[j]<<" KB hole ";
                break;
            }
        }
        if(j==nh+1)
            cout<<"\nNo space for process number "<<i<<" which requires "<<pr[i]<<" KB";

    }
    for(i=1;i<=nh;i++)
    {
        if(flag[i]==0)
            exf+=hsize[i];

    }
    cout<<"\n\nPROCESSES::";
    for(i=1;i<=np;i++)
        cout<<"  "<<pr[i];

    cout<<"\n\nMEMORY HOLES::";
    for(i=1;i<=nh;i++)
        cout<<"  "<<temp1[i];
    cout<<"\n\nTOTAL SUM OF INTERNAL FRAGMENTATION : "<<inf;
    cout<<"\n\nTOTAL SUM OF EXTERNAL FRAGMENTATION : "<<exf;

}

int main()
{
    int p[30],h[30];
    int n,m;
    cout<<"\nEnter number of processes : ";
    cin>>n;
    cout<<"\nEnter number of holes : ";
    cin>>m;
    for(int i=1;i<=n;i++)
    {
        cout<<"\nEnter size of process number "<<i<<" in KB : ";
        cin>>p[i];
    }
    for(int i=1;i<=n;i++)
    {
        cout<<"\nEnter size of hole number "<<i<<" in KB : ";
        cin>>h[i];
    }
    int ch;
    do
    {
        cout<<"\n======MEMORY MANAGEMENT ALGORITHMS=======";
        cout<<"\n1. FIRST FIT \t 2.BEST FIT \t 3.WORST FIT \t 4.EXIT ";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
            {
                case 1: first_fit(p,n,h,m);
                        break;
                case 2: best_fit(p,n,h,m);
                        break;
                case 3: worst_fit(p,n,h,m);
                        break;
                case 4: cout<<"\nExiting ";
                        exit(0);
                        break;
                default: cout<<"\nEnter a valid choice ";
                        break;
            }
    }while(ch!=4);

}
