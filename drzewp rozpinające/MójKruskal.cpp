#include<iostream>

using namespace std;

struct krawedz
{
       int numer_wierzcholka_poczatek;
       int numer_wierzcholka_koniec;
       int waga_krawedzi;
};

void Sortuj_krawedzie(krawedz **graf_, int ilosc_krawedzi_)
{
     krawedz temp;
     
     for (int i=1; i<=ilosc_krawedzi_-1; i++)
     {
             for (int j=1; j<=ilosc_krawedzi_-i; j++)
             {
                 if((*graf_)[j].waga_krawedzi > (*graf_)[j+1].waga_krawedzi)
                 {
                                              temp    = (*graf_)[j];
                                              (*graf_)[j]   = (*graf_)[j+1];
                                              (*graf_)[j+1] = temp;
                 }
             }
     }
}

int Kruskal(int ilosc_wierzcholkow_, krawedz **graf_, krawedz **drzewo_)
{
        int * ListaW = new int[ilosc_wierzcholkow_];
        int  j, k, poczatek, koniec, w;
        int krawedzie_drzewa = 0;

        for (int i=1; i<=ilosc_wierzcholkow_; i++)
        {
            ListaW[i] = 0;
        }

        k = 1;
        j = 1;
        while (k<ilosc_wierzcholkow_) // drzewo bêdzie mia³o "ilosc_wierzcholkow_-1" krawedzi
        {
                poczatek = (*graf_)[j].numer_wierzcholka_poczatek; // j=1, wiêc brana jest pod uwagê pierwsza krawêdŸ z najmniejsz¹ wag¹
                koniec = (*graf_)[j].numer_wierzcholka_koniec;
                j += 1;
                if (ListaW[poczatek]==0 || ListaW[koniec]==0 || ListaW[poczatek]!=ListaW[koniec]) // warunek sprawdzaj¹cy czy dana krawêdŸ
                {                                                                                 //  nie ³¹czy krawêdzi nale¿¹cych do tego samego drzewa
                        krawedzie_drzewa += 1;
                        (*drzewo_)[krawedzie_drzewa] = (*graf_)[j-1];
                        if (ListaW[poczatek]==0 && ListaW[koniec]!=0)  // warunek dotyczy ewentualnej dodatkowej krawêdzi grafu nie daj¹cej siê zamkn¹æ w ¿adnym cyklu
                        {
                                w=poczatek;
                                poczatek=koniec;
                                koniec=w;
                        }
                        
                        if(ListaW[poczatek]==0) // warunek dodaj¹cy pocz¹tek krawêdzi do drzewa (chyba ¿e jest wspólnym pocz¹tkiem kilku krawêdzi i ju¿ zosta³ dodany)
                        {
                                        ListaW[poczatek] = poczatek;
                        }

                        if(ListaW[koniec]==0)            // warunek przypisuj¹cy koñcowi krawêdzu wartoœæ pocz¹tkow¹, aby zapobiec póŸniejszego dadania krawêdzi ³¹cz¹cej
                        {                                // wierzcho³ki tego samego drzewa
                                        ListaW[koniec] = ListaW[poczatek];
                        }
                        else
                        {
                                w = ListaW[koniec];                          // poniewa¿ licznik pêtli for jest liczony od 1 do 5 to w przypadku koñcowej wartoœci (5)
                                for (int i=1; i<=ilosc_wierzcholkow_; i++)   // wykraczamy poza zakres tablicy gdzie nie ma wartoœci 0 tylko jakieœ œmieci i program siê wywala
                                {
                                    if(ListaW[i]==w)
                                    {
                                     ListaW[i] = ListaW[poczatek];           // w tym miejscu elementowi spoza zakresu tablicy przypisujemy wartoœæ pocz¹tkow¹
                                    }                                        // tak jak to powinno byæ zrobione w powy¿szym warunku if
                                }
                        }
                        k+=1;
                }
        }

        delete ListaW;
        return krawedzie_drzewa;
}

int main()
{
    int ilosc_wierzcholkow = 0;
    int ilosc_krawedzi = 0;
    int AlgK = 0;
    
    cout << "Podaj ilosc wierzcholkow:" << endl;
    cin >> ilosc_wierzcholkow;
    cout << "Podaj ilosc krawedzi:" << endl;
    cin >> ilosc_krawedzi;
    
    krawedz * graf = new krawedz[ilosc_krawedzi];
    krawedz * drzewo = new krawedz[ilosc_krawedzi];
    
    cout << endl;
    cout << "|Wez.pocz.|Wez.konc.|Waga|" << endl;
    
    for(int i=1; i<=ilosc_krawedzi; i++)
    {
            cin >> graf[i].numer_wierzcholka_poczatek >> graf[i].numer_wierzcholka_koniec >> graf[i].waga_krawedzi;
    }
    
    Sortuj_krawedzie(&graf, ilosc_krawedzi);
    
    AlgK = Kruskal(ilosc_wierzcholkow, &graf, &drzewo);
    
    cout << endl;
    for ( int i=1; i<= AlgK; i++)
    {
        cout << drzewo[i].numer_wierzcholka_poczatek << "------" << drzewo[i].numer_wierzcholka_koniec << " waga: " << drzewo[i].waga_krawedzi << endl;
    }
    cout << endl;
    
    delete graf;
    delete drzewo;
    
    system("pause");
    return 0;
}
