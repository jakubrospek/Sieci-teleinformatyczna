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
        while (k<ilosc_wierzcholkow_) // drzewo b�dzie mia�o "ilosc_wierzcholkow_-1" krawedzi
        {
                poczatek = (*graf_)[j].numer_wierzcholka_poczatek; // j=1, wi�c brana jest pod uwag� pierwsza kraw�d� z najmniejsz� wag�
                koniec = (*graf_)[j].numer_wierzcholka_koniec;
                j += 1;
                if (ListaW[poczatek]==0 || ListaW[koniec]==0 || ListaW[poczatek]!=ListaW[koniec]) // warunek sprawdzaj�cy czy dana kraw�d�
                {                                                                                 //  nie ��czy kraw�dzi nale��cych do tego samego drzewa
                        krawedzie_drzewa += 1;
                        (*drzewo_)[krawedzie_drzewa] = (*graf_)[j-1];
                        if (ListaW[poczatek]==0 && ListaW[koniec]!=0)  // warunek dotyczy ewentualnej dodatkowej kraw�dzi grafu nie daj�cej si� zamkn�� w �adnym cyklu
                        {
                                w=poczatek;
                                poczatek=koniec;
                                koniec=w;
                        }
                        
                        if(ListaW[poczatek]==0) // warunek dodaj�cy pocz�tek kraw�dzi do drzewa (chyba �e jest wsp�lnym pocz�tkiem kilku kraw�dzi i ju� zosta� dodany)
                        {
                                        ListaW[poczatek] = poczatek;
                        }

                        if(ListaW[koniec]==0)            // warunek przypisuj�cy ko�cowi kraw�dzu warto�� pocz�tkow�, aby zapobiec p�niejszego dadania kraw�dzi ��cz�cej
                        {                                // wierzcho�ki tego samego drzewa
                                        ListaW[koniec] = ListaW[poczatek];
                        }
                        else
                        {
                                w = ListaW[koniec];                          // poniewa� licznik p�tli for jest liczony od 1 do 5 to w przypadku ko�cowej warto�ci (5)
                                for (int i=1; i<=ilosc_wierzcholkow_; i++)   // wykraczamy poza zakres tablicy gdzie nie ma warto�ci 0 tylko jakie� �mieci i program si� wywala
                                {
                                    if(ListaW[i]==w)
                                    {
                                     ListaW[i] = ListaW[poczatek];           // w tym miejscu elementowi spoza zakresu tablicy przypisujemy warto�� pocz�tkow�
                                    }                                        // tak jak to powinno by� zrobione w powy�szym warunku if
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
