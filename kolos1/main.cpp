#include <iostream>

using namespace std;
struct samochod
{
    int rocznik;
    string marka;
    int cena;
};
void pobieranie(int k, struct samochod * samochody)
{
    for(int i=0; i<k; i++)
    {
        cout<<"Podaj rocznik "<<i+1<<" samochodu: ";
        cin>>samochody[i].rocznik;
        cout<<"Podaj makre "<<i+1<<" samochodu: ";
        cin>>samochody[i].marka;
        cout<<"Podaj cene "<<i+1<<" samochodu: ";
        cin>>samochody[i].cena;
    }
}
void sort01(int k, int &ost, struct samochod * samochody)
{
    int l=0,p=k-1;
    while(p>l)
    {
        while(samochody[l].cena<30000 && l<p)
        {
            l++;
        }
        while(samochody[p].cena>=30000 && l<p)
        {
            p--;
        }
        if(p>l)
        {

            swap(samochody[l],samochody[p]);
        }
        if(samochody[p].cena<30000)
        {
            ost=p;
        }
        else
        {
            ost=p-1;
        }
    }
}
void selection_sort(int pocz,int n, struct samochod * samochody)
{
    int k;
    for(int i=pocz; i<n-1; i++)
    {
        k=i;
        for(int j=i+1; j<n-1; j++)
        {
            if(samochody[j].rocznik>samochody[k].rocznik)
            {
                k=j;
            }
        }
        swap(samochody[i].rocznik,samochody[k].rocznik);
        swap(samochody[i].marka,samochody[k].marka);
        swap(samochody[i].cena,samochody[k].cena);
    }
}
int marka(int pocz,int kon, struct samochod *  samochody,string mark)
{
    int ile=0;
    for(int i=pocz; i<kon; i++)
    {
        string m=samochody[i].marka;
        if(m==mark)
        {
            ile++;
        }
    }
    return ile;
}
int main()
{
    int k,ost;
    do
    {
        cout<<"Podaj ilosc samochodow: ";
        cin>>k;
    }while(k<1);
    struct samochod * samochody= new samochod [k];
    pobieranie(k,samochody);
    sort01(k,ost,samochody);
    for(int i=0; i<k; i++)
    {
        cout<<samochody[i].cena<<"\t\t"<<samochody[i].marka<<"\t\t"<<samochody[i].rocznik<<endl;
    }
    cout<<endl<<endl;
    selection_sort(ost+1,k,samochody);
    for(int i=0; i<k; i++)
    {
        cout<<samochody[i].cena<<"\t\t"<<samochody[i].marka<<"\t\t"<<samochody[i].rocznik<<endl;
    }
    //cout<<"Podaj marke ktora chcesz sprawdzic: ";
    string mark;
    //cin>>mark;
    //int ile_marki=marka(0,ost+1,samochody,mark);
    //cout<<ile_marki<<" jest samochodow o cenie nie wyzszej od 30 000 "<<mark<<" marki"<<endl;
    int rozn=k-1-ost;
    if(rozn>=1)
    {
        cout<<"Rocznik najtanszego samochodu >30000"<<samochody[ost+1].rocznik<<endl;
        if(rozn>=2)
        {
            cout<<"Rocznik 2 najtanszego samochodu >30000 "<<samochody[ost+2].rocznik<<endl;
            if(rozn>=3)
            {
                cout<<"Rocznik 3 najtanszego samochodu >30000 "<<samochody[ost+3].rocznik<<endl;
            }
        }
    }
    return 0;
}
