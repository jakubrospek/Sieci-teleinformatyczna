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
    
    krawedz * graf = new krawedz[ilosc_krawedzi];  //tablica krawêdzi grafu
    
    cout << "|w1|w2|waga|" << endl;
    
    for(int i = 0; i<ilosc_krawedzi; i++)
    {
            cin >> graf[i].numer_wierzcholka_poczatek >> graf[i].numer_wierzcholka_koniec >> graf[i].waga_krawedzi;  //opisywanie krawêdzi grafu
    }
    cout << endl;
    
    krawedzie_incydentalne = ilosc_wierzcholkow-1; //maksymalna iloœæ krawêdzi jakie mog¹ mieæ wspólny wierzcho³ek w grafie
    
    wierzcholek * wierzcholki = new wierzcholek[ilosc_wierzcholkow]; //tablica wierzcho³ków grafu, bêdzie zawieraæ nr wierzcho³ka i iloœæ krawêdzi incydentnych;
    
    krawedz **Kr_incydentne = new krawedz*[ilosc_wierzcholkow]; //dynamiczny przydzia³ tablicy tablic;
    for(int j=0; j<ilosc_wierzcholkow; j++)                     //czyli tablicy wierzcho³ków, gdzie ka¿dy wierzcho³ek jest tablic¹ krawêdzi w nim siê skupiaj¹cych;
    {
             Kr_incydentne[j] = new krawedz[krawedzie_incydentalne];
    }
    
    for(int j=0; j<ilosc_wierzcholkow; j++)                         // zerowanie atrybutów tablicy krawêdzi incydentnych dla ka¿dego wierzcho³ka;
    {                                                               // tablica dla ka¿dego wierzcho³ka ma tak¹ sam¹ wielkoœæ - czyli "ilosc_wierzcholkow-1". Jesto to wielkoœæ na wyrost.
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
            wierzcholki[j].ilosc_krawedzi = 0; //zerowanie licznika krawêdzi bie¿¹cego wieszcho³ka
            wierzcholki[j].nr_wierzcholka = j+1; //przypisanie numeru do bie¿¹cego wierzcholka
            for(int i = 0; i<ilosc_krawedzi; i++)
            {
                    if((graf[i].numer_wierzcholka_poczatek == wierzcholki[j].nr_wierzcholka) || (graf[i].numer_wierzcholka_koniec == wierzcholki[j].nr_wierzcholka)) //sprawdzanie czy jakiœ koniec którejkolwiek z karawedzi równa siê numerowi wierzcho³ka.
                    {                                      
                                                           Kr_incydentne[j][wierzcholki[j].ilosc_krawedzi].numer_wierzcholka_poczatek = graf[i].numer_wierzcholka_poczatek; //ka¿da kolejna krawêŸ incydentna dla danego wierzcho³ka ma przypisywan¹ wagê i wierzcholki, które ³¹czy.
                                                           Kr_incydentne[j][wierzcholki[j].ilosc_krawedzi].numer_wierzcholka_koniec = graf[i].numer_wierzcholka_koniec;     //poprostu tworzone s¹ zbiory krawêdzi incycentnych dla ka¿dego wierzcho³ka, z kompletem informacjii na temat ka¿dej z nich.
                                                           Kr_incydentne[j][wierzcholki[j].ilosc_krawedzi].waga_krawedzi = graf[i].waga_krawedzi;
                                                           
                                                           wierzcholki[j].ilosc_krawedzi += 1; //licznik krawêdzi jest  wykorzystywany jako numer elementu tablicy aby unikn¹æ nadpisywania informacjii na temat kolejnej krawêdzi incydentnej, elementowi krawêdzi poprzedniej.               
                    }                                                                          //licznik jest zerowany dopiero w przypadku przejœcia do kolejnego wierzcho³ka.
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
             if((Kr_incydentne[j][k].waga_krawedzi)!=0)     // poniewa¿ w ka¿dy wierzcho³ek ma tablice krawêdzi incydentnych o sta³ym maksymalnym rozmiarze
             {                                              // nale¿y pomijaæ elementy które pozosta³y zerowe
                          Kr_incydentne[j][k].nr_krawedzi = k+1;                             
                          cout << "Krawedz " << Kr_incydentne[j][k].nr_krawedzi << " waga: " << Kr_incydentne[j][k].waga_krawedzi << endl;
             }
            }
    }
    
    Sortuj_krawedzie(&Kr_incydentne, liczba_krawedzi, ilosc_wierzcholkow); // krawêdzie incydentne s¹ sortowane w ramach oddzielnej grupy dla ka¿dego wierzcho³ka
    cout << endl;                                                          // od krawêdzi o najmniejszej wadze do krawêdzi o wadze najwiêkszej
    
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
            if(Kr_incydentne[j][m].waga_krawedzi==0)                            // je¿eli dany element tablicy jest wyzerowany
            {
                                                    m++;                        // to idŸ dalej
                                                    goto sprawdz;
            }
            else
            {
                for(int n=0; n<j; n++)                                          // ta pêtla sprawdza czy dana krawêdŸ o najmniejszej wadze
                {                                                               // nie by³a ju¿ wyœwietlona dla innego(poprzedniego) wierzcho³ka
                        if(((Kr_incydentne[j][m].numer_wierzcholka_poczatek)==(Kr_incydentne[n][m].numer_wierzcholka_poczatek))&&((Kr_incydentne[j][m].numer_wierzcholka_koniec)==(Kr_incydentne[n][m].numer_wierzcholka_koniec)))
                        {
                         licznik += 1; // jesli krawêdŸ by³a ju¿ wyœwietlana to licznik przyjmuje wartoœæ 1
                        }
                }
                if(licznik == 0) // warunek zapobiegaj¹cy ponownemu wyœwietleniu krawêdzi która jest wagowo najmniejsza równie¿ w stosunku do drugiego wierzcholka.
                {
                           cout << Kr_incydentne[j][m].numer_wierzcholka_poczatek << "-------" << Kr_incydentne[j][m].numer_wierzcholka_koniec << endl; // dla ka¿dego wierzcholka wyœwietlana jest tylko jedna krawêdŸ incydentna o najmniejszej wadze
                }                                                                                                                                       // wraz z wierzcho³kami które ³¹czy.
                licznik = 0; // licznik jest zerowany bo w przeciwnym razie ¿adna krawêdŸ nie mog³aby byæ wyswietlona.
            }
    }
    
    cout << endl;
    system("pause");
    return 0;
}
