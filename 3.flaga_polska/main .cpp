#include <iostream>
using namespace std;
struct student
{
    int indeks;
    float ocena;
};
void pobieranie(int n,struct student* studenci)
{

    for(int i = 0; i < n; i++)
    {
        cout << "Podaj nr indeksu studenta " << i << ": ";
        cin >> studenci[i].indeks;
        do
        {
            cout << "Podaj ocene dla studenta z indeksem " << studenci[i].indeks << ": ";
            cin >> studenci[i].ocena;
        }while(studenci[i].ocena>5 || studenci[i].ocena<2);
    }
}
void sort01(int &k,int n,struct student* studenci)
{
    int l=0,p=n-1;
    while(p>l)
    {
        while(studenci[l].ocena>2 && l<p)
        {
            l++;
        }
        while(studenci[p].ocena==2 && l<p)
        {
            p--;
        }
        if(p>l)
        {
            float ocena=studenci[l].ocena;
            float indeks=studenci[l].indeks;
            studenci[l].ocena=studenci[p].ocena;
            studenci[l].indeks=studenci[p].indeks;
            studenci[p].ocena=ocena;
            studenci[p].indeks=indeks;
        }
    }
    if(studenci[p].ocena>=3)
    {
        k=p;
    }
    else
    {
        k=p-1;
    }
}
void wyswietlanie(int k1,int k2,struct student * studenci)
{
    for(int j=k1;j<=k2;j++)
    {
        cout<<studenci[j].indeks<<"\t"<<studenci[j].ocena;
        cout<<endl;
    }

    cout<<endl;
}
int main()
{
    int n,k=-1;
    do
    {
        cout<<"Podaj ilosc studentow:";
        cin>>n;
    }while(n<1);
    struct student * studenci = new student[n];
    pobieranie(n,studenci);
    sort01(k,n,studenci);
    cout<<"Zdali egzamin:\n";
    wyswietlanie(0,k,studenci);
    cout<<"Nie Zdali egzamin:\n";
    wyswietlanie(k+1,n-1,studenci);
    return 0;
}
