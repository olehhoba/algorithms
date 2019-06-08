#include <iostream>
#include <iomanip>
using namespace std;
struct NODE
{
    int key;
    struct NODE *left;
    struct NODE *right;
};
/////////////////////////////////////////////////////////////////////
struct NODE *new_node(int el)
{
    struct NODE *temp=new NODE;
    temp->key=el;
    temp->left=temp->right=NULL;
    return temp;
}
////////////////////////////////////////////////////////
struct NODE *add(struct NODE *root,int el)
{
    if(root==NULL)
    {
        return new_node(el);
    }
    if(el < root->key)
    {
        root->left=add(root->left,el);
    }
    else if(el > root->key)
    {
        root->right=add(root->right,el);
    }
    return root;
};
//////////////////////////////////////////////////////////////////
struct NODE *search(struct NODE *root,int el)
{
    if(root==NULL || root->key==el)
    {
        return root;
    }
    else if(root->key < el)
    {
        return search(root->right,el);
    }
    else
    {
        return search(root->left,el);
    }
}
////////////////////////////////////////////////////////////////////////

struct NODE *f(struct NODE *root)
{
    struct NODE *te=root;
    while(te && te->left!=NULL)
    {
        te=te->left;
    }
    return te;
};
/////////////////////////////////////////////////////////////////////
struct NODE *rem(int el,struct NODE *root)
{
    if(root==NULL)
    {
        return root;
    }

    if(el < root->key)
    {
        root->left=rem(el,root->left);
    }
    else if(el > root->key)
    {
        root->right=rem(el,root->right);
    }
    else
    {
        if(root->left==NULL)
        {
            struct NODE *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            struct NODE *temp=root->left;
            delete root;
            return temp;
        }

        struct NODE *temp=f(root->right);
        root->key=temp->key;
        root->right=rem(root->key,root->right);
    }
    return root;
};

/////////////////////////////////////////////////////////////////////

void space(int numb)
{
    for(int i = 0; i < numb; i++)
    {
        std::cout << " ";
    }
}

/////////////////////////////////////////////////////////////////////
void print(struct NODE* root,int lv,const int& mid_sp,const int& w,int& counter)
{
    lv--;
    if(root != NULL)
    {
        if(lv != 0)
        {
            print(root->left, lv, mid_sp,w, counter);
            print(root->right, lv, mid_sp,w, counter);
        }
        else
        {
            for(int i = 0; i < counter; i++)
            {
                space(w);
                space(mid_sp);
            }
            counter = 0;
            std::cout << std::setw(w) << root->key;
            space(mid_sp);
        }
    }

    else
    {
        int q = 1;
        for(int i = 0; i < lv+1; i++)
        {
            if(i != 0)
                q *= 2;
        }
        counter += q;
    }
}

//////////////////////////////////////////////////////////////////////////

void rev(struct NODE *root, int i, int &l_m)
{
    if(root!=NULL)
    {
        if(i > l_m)
        {
            l_m = i;
        }
        rev(root->left, i+1, l_m);
        rev(root->right, i+1, l_m);
        i--;
    }
}

///////////////////////////////////////////////////////////////////////////

struct NODE *min_value(struct NODE* root)
{
    struct NODE* cur = root;
    while (cur && cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur;
}

////////////////////////////////////////////////////////////////////


int main()
{
    struct NODE *root=NULL;
    int choice,
        el,
        l_m=-1,
        counter=0,
        l_sp,
        m_sp;
    const int w = 4;
    while(1)
    {
        cout<<"1.Dodanie elementu do drzewa"<<endl;
        cout<<"2.Przeglodanie drzewa w porzadku inorder"<<endl;
        cout<<"3.Wyszukiwanie elementu w drzewie(TAK-NIE)"<<endl;
        cout<<"4.Usuwanie elementu"<<endl;
        cout<<"5.Wyjscie"<<endl;
        cout<<"Twoj wybor:";
        cin>>choice;

        switch (choice)
        {
        case 1:

            cout<<"Podaj element ktory chcesz dodac:";
            cin>>el;
            if(search(root,el)==NULL)
            {
                root=add(root,el);
                cout<<"Dodano "<<el<<endl;
                fflush(stdin);
                getchar();
            }
            else
            {
                cout<<"Juz jest taki element nie moge jego dodac"<<endl;
                fflush(stdin);
                getchar();
            }
            break;
        case 2:
            l_m = 0;
            rev(root, 0, l_m);
            for(int i = 0; i <= l_m; i++)
            {
                l_sp = 0, m_sp = 0;
                counter = 0;
                for(int j = 0; j <l_m-i; j++)
                {
                    l_sp=2*l_sp+w/2;
                    m_sp=l_sp*2;
                }
                space(l_sp);
                print(root,i+1,m_sp,w,counter);
                std::cout << '\n';
            }
            break;
        case 3:
            cout<<"Podaj element ktory chcesz szukac:";
            cin>>el;
            if(search(root,el)==NULL)
            {
                cout<<"Elementu o wartosci "<<el<<" nie znaleziono"<<endl;
                fflush(stdin);
                getchar();
            }
            else
            {
                cout<<"Znalazlem "<<el<<endl;
                fflush(stdin);
                getchar();
            }
            break;
        case 4:
            cout<<"Podaj element,ktory chcesz usunac:";
            cin>>el;
            if(search(root,el)!=NULL)
            {
                root=rem(el,root);
                cout<<"Usunieto "<<el<<endl;
            }
            else
            {
                cout<<"Niema takiego elementu.Nie moge usunac!";
            }
            break;
        case 5:
            exit(0);
            break;
        default:
            cout<<"Wybierz cos innego"<<endl;
            break;
        }
    }
    return 0;
}
