#include <iostream>

using namespace std;
void enter(int *t,int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"Podaj "<<i<<" element: ";
        cin>>t[i];
    }
}
void sort01(int &k,int n,int *t)
{
    int l=0,p=n-1;
    while(p>l)
    {
        while(t[l]%2==0 && l<p)
        {
            l++;
        }
        while(t[p]%2==1 && l<p)
        {
            p--;
        }
        if(p>l)
        {
            int v=t[l];
            t[l]=t[p];
            t[p]=v;
            l++;
            p--;
        }
    }
    if(t[p]%2==0)
    {
        k=p;
    }
    else
    {
        k=p-1;
    }
}
void QUICKSORT(int *t, int l, int p)
{
    int v=t[(l+p)/2];
    int i,j,x;
    i=l;
    j=p;
    do
    {
        while(t[i]<v)
        {
            i++;
        }
        while(t[j]>v)
        {
            j--;
        }
        if(i<=j)
        {
            x=t[i];
            t[i]=t[j];
            t[j]=x;
            i++;
            j--;
        }
    }while(i<=j);
    if(j>l)
    {
        QUICKSORT(t, l, j);
    }
    if(i<p)
    {
        QUICKSORT(t,i,p);
    }

}
void f(int r,int *t,int k,int &ind, int &dlugo)
{
    int dlugosc=0,max_dlugosc=0,indeks=0,w=0;
    for(int i=0; i<k; i++)
    {

        dlugosc=0;
        w=t[i]+r;
        for(int j=i;t[j]<=w && j<=k; j++)
        {
            dlugosc++;
        }
        if(dlugosc>max_dlugosc)
        {
            max_dlugosc=dlugosc;
            indeks=i;
        }
    }
    dlugo=max_dlugosc;
    ind=indeks;
}
int main()
{
    int n=0,k=0,*t,r,dlugo=0,ind=0;
    do
    {
        cout << "Podaj n: ";
        cin>>n;
    }while(n<1);
    do
    {
        cout<<"Podaj dodatni przedzial: ";
        cin>>r;
    }while(r<1);
    t=new int [n];
    enter(t,n);
    sort01(k,n,t);
    if(k==-1)
    {
        cout<<"Niema liczb parzystych"<<endl;
    }
    else if(k==0)
    {
        cout<<"Jedna liczba nie tworzy przedzial!!!"<<endl;
    }
    else
    {
        QUICKSORT(t,0,k);
        for(int i=0;i<n;i++)
        {
            cout<<t[i]<<"\t";
        }
        cout<<endl;
        f(r,t,k,ind,dlugo);
        cout<<"j="<<ind<<"; ["<<t[ind]<<","<<t[ind]+r<<"]"<<endl;
    }
    return 0;
}
