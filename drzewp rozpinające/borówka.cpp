#include<iostream>

using namespace std;

struct krawedz
{
       int numer_wierzcholka_poczatek;
       int numer_wierzcholka_koniec;
       int waga_krawedzi;
       int nr_krawedzi;
};

struct wierzcholek
{
       int nr_wierzcholka;
       int ilosc_krawedzi;
};

void Sortuj_krawedzie(krawedz ***Kr_incydentne_, int krawedzie_incydentalne_, int ilosc_wierzcholkow_)
{
     krawedz temp;
     
     for(int l=0; l<ilosc_wierzcholkow_; l++)
     {
     for (int i=0; i<krawedzie_incydentalne_-1; i++)
     {
             for (int j=0; j<krawedzie_incydentalne_-i; j++)
             {
                 if((*Kr_incydentne_)[l][j].waga_krawedzi > (*Kr_incydentne_)[l][j+1].waga_krawedzi)
                 {
                                              temp    = (*Kr_incydentne_)[l][j];
                                              (*Kr_incydentne_)[l][j]   = (*Kr_incydentne_)[l][j+1];
                                              (*Kr_incydentne_)[l][j+1] = temp;
                 }
             }
     }
     }
}

int main()
{
    
    int ilosc_wierzcholkow = 0;
    int ilosc_krawedzi = 0, krawedzie_incydentalne =0;
    int liczba_krawedzi=0;
    int m=0, licznik=0;
    
    cout << "Podaj ilosc wierzcholkow:" << endl;
    cin >> ilosc_wierzcholkow;
    cout << "Podaj ilosc krawedzi:" << endl;
    cin >> ilosc_krawedzi;
    
    krawedz * graf = new krawedz[ilosc_krawedzi];  //tablica kraw�dzi grafu
    
    cout << "|w1|w2|waga|" << endl;
    
    for(int i = 0; i<ilosc_krawedzi; i++)
    {
            cin >> graf[i].numer_wierzcholka_poczatek >> graf[i].numer_wierzcholka_koniec >> graf[i].waga_krawedzi;  //opisywanie kraw�dzi grafu
    }
    cout << endl;
    
    krawedzie_incydentalne = ilosc_wierzcholkow-1; //maksymalna ilo�� kraw�dzi jakie mog� mie� wsp�lny wierzcho�ek w grafie
    
    wierzcholek * wierzcholki = new wierzcholek[ilosc_wierzcholkow]; //tablica wierzcho�k�w grafu, b�dzie zawiera� nr wierzcho�ka i ilo�� kraw�dzi incydentnych;
    
    krawedz **Kr_incydentne = new krawedz*[ilosc_wierzcholkow]; //dynamiczny przydzia� tablicy tablic;
    for(int j=0; j<ilosc_wierzcholkow; j++)                     //czyli tablicy wierzcho�k�w, gdzie ka�dy wierzcho�ek jest tablic� kraw�dzi w nim si� skupiaj�cych;
    {
             Kr_incydentne[j] = new krawedz[krawedzie_incydentalne];
    }
    
    for(int j=0; j<ilosc_wierzcholkow; j++)                         // zerowanie atrybut�w tablicy kraw�dzi incydentnych dla ka�dego wierzcho�ka;
    {                                                               // tablica dla ka�dego wierzcho�ka ma tak� sam� wielko�� - czyli "ilosc_wierzcholkow-1". Jesto to wielko�� na wyrost.
            for(int k=0; k<krawedzie_incydentalne; k++)
            {
                     Kr_incydentne[j][k].numer_wierzcholka_poczatek = 0;
                     Kr_incydentne[j][k].numer_wierzcholka_koniec = 0;
                     Kr_incydentne[j][k].waga_krawedzi = 0;
                     Kr_incydentne[j][k].nr_krawedzi = 0;
            }
    }
    
    for(int j = 0; j<ilosc_wierzcholkow; j++)
    {
            wierzcholki[j].ilosc_krawedzi = 0; //zerowanie licznika kraw�dzi bie��cego wieszcho�ka
            wierzcholki[j].nr_wierzcholka = j+1; //przypisanie numeru do bie��cego wierzcholka
            for(int i = 0; i<ilosc_krawedzi; i++)
            {
                    if((graf[i].numer_wierzcholka_poczatek == wierzcholki[j].nr_wierzcholka) || (graf[i].numer_wierzcholka_koniec == wierzcholki[j].nr_wierzcholka)) //sprawdzanie czy jaki� koniec kt�rejkolwiek z karawedzi r�wna si� numerowi wierzcho�ka.
                    {                                      
                                                           Kr_incydentne[j][wierzcholki[j].ilosc_krawedzi].numer_wierzcholka_poczatek = graf[i].numer_wierzcholka_poczatek; //ka�da kolejna kraw� incydentna dla danego wierzcho�ka ma przypisywan� wag� i wierzcholki, kt�re ��czy.
                                                           Kr_incydentne[j][wierzcholki[j].ilosc_krawedzi].numer_wierzcholka_koniec = graf[i].numer_wierzcholka_koniec;     //poprostu tworzone s� zbiory kraw�dzi incycentnych dla ka�dego wierzcho�ka, z kompletem informacjii na temat ka�dej z nich.
                                                           Kr_incydentne[j][wierzcholki[j].ilosc_krawedzi].waga_krawedzi = graf[i].waga_krawedzi;
                                                           
                                                           wierzcholki[j].ilosc_krawedzi += 1; //licznik kraw�dzi jest  wykorzystywany jako numer elementu tablicy aby unikn�� nadpisywania informacjii na temat kolejnej kraw�dzi incydentnej, elementowi kraw�dzi poprzedniej.               
                    }                                                                          //licznik jest zerowany dopiero w przypadku przej�cia do kolejnego wierzcho�ka.
            }
    }
    
    cout << "Ilosc krawedzi incydentnych dla poszczegolnych wierzcholkow:" << endl;
    cout << endl;
    
    for(int j = 0; j<ilosc_wierzcholkow; j++)
    {
            cout << "Nr wierzcholka: " << wierzcholki[j].nr_wierzcholka << " ilosc kraw. " << wierzcholki[j].ilosc_krawedzi << endl;
    }
    cout << endl;
    
    cout << "Rozklad wag dla poszczegolnych krawedzi: " << endl;
    cout << endl;
    
    for(int j = 0; j<ilosc_wierzcholkow; j++)
    {
            cout << "Wierzcholek " << j+1 << endl;
            liczba_krawedzi = 0;
            liczba_krawedzi = wierzcholki[j].ilosc_krawedzi;
            for(int k=0; k<liczba_krawedzi; k++)
            {
             if((Kr_incydentne[j][k].waga_krawedzi)!=0)     // poniewa� w ka�dy wierzcho�ek ma tablice kraw�dzi incydentnych o sta�ym maksymalnym rozmiarze
             {                                              // nale�y pomija� elementy kt�re pozosta�y zerowe
                          Kr_incydentne[j][k].nr_krawedzi = k+1;                             
                          cout << "Krawedz " << Kr_incydentne[j][k].nr_krawedzi << " waga: " << Kr_incydentne[j][k].waga_krawedzi << endl;
             }
            }
    }
    
    Sortuj_krawedzie(&Kr_incydentne, liczba_krawedzi, ilosc_wierzcholkow); // kraw�dzie incydentne s� sortowane w ramach oddzielnej grupy dla ka�dego wierzcho�ka
    cout << endl;                                                          // od kraw�dzi o najmniejszej wadze do kraw�dzi o wadze najwi�kszej
    
    cout << "Posortowane krawedzie (wedlug wag):" << endl;
    cout << endl;
    
    for(int j = 0; j<ilosc_wierzcholkow; j++)
    {
            cout << "Wierzcholek " << j+1 << endl;
            for(int k=0; k<krawedzie_incydentalne; k++)
            {
             if((Kr_incydentne[j][k].waga_krawedzi)!=0)
             {
                          cout << "Krawedz " << Kr_incydentne[j][k].nr_krawedzi << " waga: " << Kr_incydentne[j][k].waga_krawedzi << endl;
             }
            }
    }
    cout << endl;
    
    cout << "Minimalne drzewo rozpinajace:" << endl;
    cout << endl;
    
    for(int j = 0; j<ilosc_wierzcholkow; j++)
    {
            m=0;
            sprawdz:
            if(Kr_incydentne[j][m].waga_krawedzi==0)                            // je�eli dany element tablicy jest wyzerowany
            {
                                                    m++;                        // to id� dalej
                                                    goto sprawdz;
            }
            else
            {
                for(int n=0; n<j; n++)                                          // ta p�tla sprawdza czy dana kraw�d� o najmniejszej wadze
                {                                                               // nie by�a ju� wy�wietlona dla innego(poprzedniego) wierzcho�ka
                        if(((Kr_incydentne[j][m].numer_wierzcholka_poczatek)==(Kr_incydentne[n][m].numer_wierzcholka_poczatek))&&((Kr_incydentne[j][m].numer_wierzcholka_koniec)==(Kr_incydentne[n][m].numer_wierzcholka_koniec)))
                        {
                         licznik += 1; // jesli kraw�d� by�a ju� wy�wietlana to licznik przyjmuje warto�� 1
                        }
                }
                if(licznik == 0) // warunek zapobiegaj�cy ponownemu wy�wietleniu kraw�dzi kt�ra jest wagowo najmniejsza r�wnie� w stosunku do drugiego wierzcholka.
                {
                           cout << Kr_incydentne[j][m].numer_wierzcholka_poczatek << "-------" << Kr_incydentne[j][m].numer_wierzcholka_koniec << endl; // dla ka�dego wierzcholka wy�wietlana jest tylko jedna kraw�d� incydentna o najmniejszej wadze
                }                                                                                                                                       // wraz z wierzcho�kami kt�re ��czy.
                licznik = 0; // licznik jest zerowany bo w przeciwnym razie �adna kraw�d� nie mog�aby by� wyswietlona.
            }
    }
    
    cout << endl;
    system("pause");
    return 0;
}
