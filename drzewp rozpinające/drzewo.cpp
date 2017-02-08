#include<iostream>

using namespace std;

class krawedz
{
      public:
      int numer_krawedzi;
      int numer_wierzcholka_poczatek;
      int numer_wierzcholka_koniec;
      int waga_krawedzi;
};

int main()
{
    int liczba_krawedzi, liczba_wierzcholkow, j=0;
    
    cout << "Podaj liczbe krawedzi grafu:" << endl;
    cin >> liczba_krawedzi;
    
    cout << "Podaj liczbe wierzcholkow grafu:" << endl;
    cin >> liczba_wierzcholkow;
    
    krawedz * graf = new krawedz[liczba_krawedzi];
    
    for(int i=0; i<liczba_krawedzi; i++)
    {
            graf[i].numer_krawedzi = i+1;
            cout << "Waga krawedzi numer " << graf[i].numer_krawedzi << " :" << endl;
            cin >> graf[i].waga_krawedzi;
            
            if(j<liczba_wierzcholkow)
            {
            graf[i].numer_wierzcholka_poczatek = graf[i].numer_krawedzi;
                                     
                                     if(graf[i].numer_krawedzi+1 > liczba_wierzcholkow)
                                     {
                                                                 graf[i].numer_wierzcholka_koniec = graf[0].numer_krawedzi;
                                     }
                                     else
                                     {
                                                                 graf[i].numer_wierzcholka_koniec = graf[i].numer_krawedzi+1;
                                     }
            
            j++;
            }
            else
            {
                cout << "Podaj nr. wierzcholkow polaczonych przez krawedz " << graf[i].numer_krawedzi << ":" << endl;
                cin >> graf[i].numer_wierzcholka_poczatek;
                cin >> graf[i].numer_wierzcholka_koniec;
            }
    }
    
    cout << graf[4].numer_wierzcholka_koniec << endl;
    
    system("pause");
    return 0;
}
