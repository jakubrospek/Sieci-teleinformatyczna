#include<iostream>

using namespace std;

struct paczka
{
       int etykieta;
       int indeks;
};

int main()
{
    /*
    int w =5;
    int k = 5;
    int i;
    int tab[5] = {1,2,3,4,5};
    int* wsk = &tab[3];
    
    for(i=0; i<5; i++)
    {
             cout << tab[i] << endl;
    }
    cout << endl;
    
    cout << *wsk << endl; */
   /* 
    struct paczka tab[5];
    
    for(int i=0; i<5; i++)
    {
            tab[i].indeks = 1;
            tab[i].etykieta = i;
    }
    cout << endl << endl;
    
    for(int i=0; i<5; i++)
    {
           cout << tab[i].indeks << endl;
    }
    cout << endl << endl;
    
    for(int i=0; i<5; i++)
    {
           cout << tab[i].etykieta << endl;
    }
    */
    //-------------------------------------------------- moja zajebista funkcja losuj¹ca!
    int liczba = 0, licz = 0;
    int tab1[5], tab2[5], wylosowane[5];
    
    srand(time(NULL));
    for(int i=0; i<5; i++) //liczba losowañ
    {
            losuj:
            liczba = rand() % 5;
            tab1[i] = tab2[liczba];      // tu miejsce na przepisywanie dwuwymiarowej tablicy
            
            for(int j=0; j<licz; j++)
            {
                    if(liczba!=wylosowane[j])
                    {                      
                    }
                    else
                    {
                        goto losuj;
                    }
            }
            
            wylosowane[licz] = liczba;
            licz++;
            
    }
    
    for(int z=0; z<licz; z++)
    {
            cout << wylosowane[z] << endl;
    }
//-----------------------------------------------------------------------------------
    
    system("pause");
    return 0;
}
