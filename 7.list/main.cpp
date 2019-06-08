#include <iostream>
#include <windows.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////
struct LISTA
{
    struct LISTA *nast;
    int x;
};
///////////////////////////////////////////////////////////////////////////
struct LISTA *dodaj(struct LISTA *list)
{
    int szukany,element;
    cout<<"Podaj element ,ktory chcesz wstawic: ";
    cin>>element;
    cout<<"Podaj element wartosc elemntu ,za ktory chcesz wstawic: ";
    cin>>szukany;
    struct LISTA *new_element=new LISTA;
    struct LISTA *temp=NULL;
    new_element->x=element;
    new_element->nast=NULL;
    if(list==NULL)
    {
        list=new_element;
    }
    else
    {
        temp=list;
        while(temp->x!=szukany)
        {
            if(temp->nast==NULL)
            {
                temp->nast=new_element;
                return list;
            }
            else
            {
                temp=temp->nast;
            }
        }
        new_element->nast=temp->nast;
        temp->nast=new_element;
    }
    return list;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
struct LISTA *usun(struct LISTA *list)
{

    if(list==NULL)
    {
        cout<<"Lista jest pusta,nie moge nic usunac!"<<endl<<endl;
        return list;
    }
    int us;
    cout<<"Podaj wartosci elementow, ktorych chcesz usunac:";
    cin>>us;
    while(list!=NULL && list->x==us)
    {
        list=list->nast;
    }
    struct LISTA* current = list;
    struct LISTA* temp = current;

    while(current != NULL)
    {
        if(current->x == us)
        {
            temp->nast = current->nast;
            delete current;
        }
        else
        {
            temp = current;
        }
        current = current->nast;
    }
    fflush(stdin);
    getchar();
    return list;

};
//////////////////////////////////////////////////////////////////////////
void wydruk(struct LISTA *list)
{
    struct LISTA *temp=list;
    if(temp==NULL)
    {
        cout<<"Lista jest pusta"<<endl;
    }
    else
    {
        cout<<"Lista:\t";
        do
        {
            cout<<temp->x<<"\t";
            temp=temp->nast;
        }while(temp!=NULL);
    }
    cout<<endl;
};
/////////////////////////////////////////////////////////////////////////////

int main()
{
    int choice,element;
    struct LISTA *list=NULL;

    do{
        cout<<"1.Dodanie elementu za element o podanej wartosci(jezeli elementu o podanejwartosci nie ma na liscie, nale¿y dolaczyc element na koncu listy)"<<endl;
        cout<<"2.Usuniecie wszystkich (jezeli jest wiecej niz jeden) elementow o podanej przez uzytkownika wartosci)"<<endl;
        cout<<"3.Wydruk listy od poczatku"<<endl;
        cout<<"4.Koniec"<<endl;
        cout<<endl<<"Twoj wybor: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            list=dodaj(list);
            break;
        case 2:
            list=usun(list);
            break;
        case 3:
            wydruk(list);
            break;
        }
    }while(choice!=4);
    return 0;
}
