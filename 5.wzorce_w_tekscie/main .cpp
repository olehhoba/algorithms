#include <iostream>
#include <string>
#include <vector>
using namespace std;
string text,wzorzec;
void boyer_moore_2(std::vector<int>& wystapienia3,string text,string wzorzec)
{
    int dlugosc_wzorzec=wzorzec.size();
    int dlugosc_text=text.size();
    vector<int>wyst(255,-1);
    for (int i = 0; i < dlugosc_wzorzec; i++)
    {
        wyst[static_cast<int>(wzorzec[i])] = i;
    }
    int k = 0;
    while (k <= (dlugosc_text - dlugosc_wzorzec))
    {
        int p=dlugosc_wzorzec - 1;
        while (p >= 0 && wzorzec[p] == text[k + p])
        {
            p--;
        }

        if (p < 0)
        {
            wystapienia3.push_back(k);
            k+=(k+dlugosc_wzorzec<dlugosc_text)?dlugosc_wzorzec-wyst[text[k+dlugosc_wzorzec]]:1;
        }

        else
        {
            k+=std::max(1,p-wyst[text[k + p]]);
        }
    }
}

void boyer_moore(vector<int>& wystapienia2, string text,string wzorzec)
{
    for(int i=wzorzec.size()-1; i<text.size(); i++)
    {
        int z=0;
        for(int j=0; j<wzorzec.size(); j++)
        {
            if(text[i]==wzorzec[j])
            {
                z++;
            }
        }
        if(z>0)
        {
            z=0;
            for(int k=0;k<wzorzec.size();k++)
            {
                if(text[i-k]==wzorzec[wzorzec.size()-k-1])
                {
                    z++;
                }
            }
            if(z==wzorzec.size())
            {
                wystapienia2.push_back(i-wzorzec.size()+1);
                i+=wzorzec.size()-1;
            }
        }
        else
        {
            i+=wzorzec.size()-1;
        }
    }
}

void naiwny(std::vector<int>& wystapienia,string text,string wzorzec)
{
    for(int i=0;i<text.size();i++)
    {
        if(text[i]==wzorzec[0])
        {
            int z=0;
            for(int j=1;j<wzorzec.size();j++)
            {
                if(text[i+j]==wzorzec[j])
                {
                    z++;
                }
            }
            if(z==wzorzec.size()-1)
            {
                wystapienia.push_back(i);
                i+=wzorzec.size()-1;
            }
        }
    }
}

int main()
{
    int q;
    std::vector<int>wystapienia;
    vector<int>wystapienia2;
    vector<int>wystapienia3;
    int ilosc_wystapien=0;
    cout << "Podaj tekst:" ;
    fflush(stdin);
    getline(cin,text);
    cout<<"Podaj wzorzec:";
    getline(cin,wzorzec);
    do {
    cout<<"1.Algorytm naiwny!!!\n";
    cout<<"2.Algorytm Boyer Moore!!!\n";
    cout<<"3.Algorytm Boyer Moore(2 wersja)!!!\n";
    cout<<"4.Wyjdz!!!\n";
    cout<<"Twoj wybor:";
    cin>>q;
    switch (q)
    {
        case 1:
            naiwny(wystapienia,text,wzorzec);
            cout<<"Algorytm naiwny:\n";
            if(wystapienia.size()==0)
            {
                    cout<<"Nie znalazlem wzorca '"<<wzorzec<<"' tekscie '"<<text<<"'"<<endl;
            }
            else
            {
                cout<<"Wzorzec '"<<wzorzec<<"' wystepuje w tekscie '"<<text<<"' "<<wystapienia.size()<<" razy"<<endl;
                cout<<"Wzorce zaczynaja sie w tekscie pod takimi nomerami[";
                for(int i=0;i<wystapienia.size();i++)
                {
                    if(i!=wystapienia.size()-1)
                    {
                        cout<<wystapienia[i]<<",";
                    }
                    else
                    {
                        cout<<wystapienia[i]<<"]\n";
                    }
                }

            }
            wystapienia.clear();
            break;
        case 2:
            boyer_moore(wystapienia2,text,wzorzec);
            cout<<"Algorytm BOYER-MOOREA:\n";
            if(wystapienia2.size()==0)
            {
                    cout<<"Nie znalazlem wzorca '"<<wzorzec<<"' tekscie '"<<text<<"'"<<endl;
            }
            else
            {
                cout<<"Wzorzec '"<<wzorzec<<"' wystepuje w tekscie '"<<text<<"' "<<wystapienia2.size()<<" razy"<<endl;
                cout<<"Wzorce zaczynaja sie w tekscie pod takimi nomerami[";
                for(int i=0;i<wystapienia2.size();i++)
                {
                    if(i!=wystapienia2.size()-1)
                    {
                        cout<<wystapienia2[i]<<",";
                    }
                    else
                    {
                        cout<<wystapienia2[i]<<"]\n";
                    }
                }

            }
            wystapienia2.clear();
            break;
         case 3:
            boyer_moore_2(wystapienia3,text,wzorzec);
            cout<<"Algorytm BOYER-MOOREA(wersja 2):\n";
            if(wystapienia3.size()==0)
            {
                    cout<<"Nie znalazlem wzorca '"<<wzorzec<<"' tekscie '"<<text<<"'"<<endl;
            }
            else
            {
                cout<<"Wzorzec '"<<wzorzec<<"' wystepuje w tekscie '"<<text<<"' "<<wystapienia3.size()<<" razy"<<endl;
                cout<<"Wzorce zaczynaja sie w tekscie pod takimi nomerami[";
                for(int i=0;i<wystapienia3.size();i++)
                {
                    if(i!=wystapienia3.size()-1)
                    {
                        cout<<wystapienia3[i]<<",";
                    }
                    else
                    {
                        cout<<wystapienia3[i]<<"]\n";
                    }
                }

            }
            wystapienia3.clear();
            break;
        case 4:
                 exit(0);
                 break;
        default:
            cout<<"Zrob wybor jeszcze raz!!!"<<endl;
    }
    }while(q!=4);
    return 0;
}
