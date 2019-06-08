#include <iostream>
using namespace std;
int * enter(int *n)
{
    int nn;
    do
    {
        cout<<"Enter n: ";
        cin>>nn;
    }while(nn<1);
    *n=nn;
    int *tab;
    tab=new int [nn];
    for(int i=0;i<nn;i++)
    {
        cout<<"Enter "<<i<<" element: ";
        cin>>tab[i];
    }
    return tab;

}
void INSERTSORT(int n,int *tab)
{
    int i=1,j,p;
    while(i<n)
    {
        j=i-1;
        p=tab[i];
        while(tab[j]>p && j>=0)
        {
            tab[j+1]=tab[j];
            j--;
            tab[j+1]=p;
        }
        i++;
    }
}

void BUBBLESORT(int n,int *tab)
{
    int d=n-1,i;
    while(d>=0)
    {
        i=1;
        while(i<=d)
        {
            if(tab[i-1]>tab[i])
            {
                int p;
                p=tab[i-1];
                tab[i-1]=tab[i];
                tab[i]=p;

             }
            i++;
            }
            d--;

    }
}

void SELECTIONSORT(int n, int *t)
{
  int maxx,k;
  for(int i=n-1;i>=1;i--)
  {
      maxx=0;
      k=0;
      for(int j=1;j<=i;j++)
      {
          if(t[j]>t[maxx])
          {
              maxx=j;

          }
      }
      int p=t[i];
      t[i]=t[maxx];
      t[maxx]=p;

  }
}
void wyswietl(int n, int *t)
{

    for(int i=0;i<n;i++)
    {
        cout<<t[i]<<"\t";
    }
    cout<<endl;
}
int main()
{

    int wybor;
    do{
    cout<<"1.Podanie danych"<<endl;
    cout<<"2.Bubble sort"<<endl;
    cout<<"3.Insert sort"<<endl;
    cout<<"4.Selection sort"<<endl;
    cout<<"5.Wyswietlanie tablicy"<<endl;
    cout<<"6.Konic programu"<<endl;
    do
    {
        cout<<"Twoj wybor: ";
        cin>>wybor;
    }while(wybor<1 || wybor>6);
    int nn=0,n;
    int *t;
    switch (wybor)
    {
            case 1:
                t=enter(&nn);
                n=nn;
                break;
            case 2:
                 BUBBLESORT(n,t);
                 break;
            case 3:
                INSERTSORT(n,t);
                break;
            case 4:
                SELECTIONSORT(n,t);
                break;
            case 5:
                wyswietl(n,t);
                break;

    }
    }while(wybor!=6);

    return 0;
}
