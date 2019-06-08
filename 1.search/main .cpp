#include <iostream>
using namespace std;
int* enter(int *nn,int *s)
{
    int n;
    do
    {
        cout<<"Enter n: ";
        cin>>n;
    }while(n<1);
    int *tab=new int [n];
    for(int i=0;i<n;i++)
    {
        if(i>0)
        {
            do
            {
            cout<<"Enter "<<i<<" element: ";
            cin>>tab[i];
            }while(tab[i]<=tab[i-1]);
        }
        else
        {
            cout<<"Enter "<<i<<" element: ";
            cin>>tab[i];
        }

    }
    *nn=n;
    int searching;
    cout<<"Enter the number you are searching: ";
    cin>>searching;
    *s=searching;
    return tab;
}
int  liniowo(int n,int *t,int searching)
{
    int nr=0;
    while(nr<n && searching!=t[nr])
    {
        nr=nr+1;
    }
    if(searching==t[nr])
    {
        return nr;
    }
    else
    {
        return -1;
    }
}
int  bisekcyjnie(int n,int *t,int searching)
{
    int l=0,p=n,s;
    while(p>l)
    {
        s=(l+p)/2;
        if(searching>t[s])
        {
            l=s+1;
        }
        else
        {
            p=s;
        }
    }
    if(searching==t[p])
    {
        return p;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n=0,searching=0;
    int * tab=enter(&n,&searching);
    int w;
    cout<<"Liniowo: "<<endl;
    w=liniowo(n,tab,searching);
    if(w!=-1)
    {
        cout<<"The number you are looking for is at the number "<<w+1<<endl;
    }
    else
    {
        cout<<"The number is not found"<<endl;
    }
    cout<<"Bisekcyjnie nierekurencyjnie: "<<endl;
    int e=bisekcyjnie(n,tab,searching);
    if(e!=-1)
    {
        cout<<"The number you are looking for is at the number "<<e+1<<endl;
    }
    else
    {
        cout<<"The number is not found"<<endl;
    }

    return 0;
}
