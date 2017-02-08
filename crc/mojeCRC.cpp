#include<iostream>

using namespace std;

int main()
{
    string dzielnik1;
    
    cout << "Podaj dzielnik:" << endl;
    cin >> dzielnik1;
    
    int i=0, j=0, k=0, l=0, m=0, n=0, dlugosc = dzielnik1.length(), dodane_wyzerowane_bity = dlugosc - 1;
    int calkowita_ilosc_bitow = 0, wartosc = 0, licznik = 0;
    char znak, znak2;
    int *dzielnik2 = new int [dlugosc];
    
    for(l=0; l<dlugosc; l++)
    {
             if(dzielnik1[l] == '1')
             {
                             dzielnik2[l] = 1;
             }
             else
             {
                 dzielnik2[l] = 0;
             }
    }
    
    FILE *plik1, *plik2;
    
    if((plik1 = fopen("przed_zaszumieniem.txt","r")) != NULL)
    {
               while ((znak = fgetc(plik1)) != EOF)
               {
                     calkowita_ilosc_bitow+=1;
               }
    }
    
    fclose(plik1);
    
    int rozmiar_tablicy = calkowita_ilosc_bitow + dodane_wyzerowane_bity;
    int stop = rozmiar_tablicy-dlugosc;
    int *tab = new int [rozmiar_tablicy];
    int *tab2 = new int [rozmiar_tablicy];
    
    for(m=0; m<rozmiar_tablicy; m++)                //zerowanie tablicy
    {
          tab[m] = 0;
    }

    if((plik1 = fopen("przed_zaszumieniem.txt","r")) != NULL)          //kopiowanie bitów z pliku tekstowego do tablicy
    {                                                     //w celu losowej zamiany czêœci z nich
               while ((znak = fgetc(plik1)) != EOF)
               {
                     if(znak == '1')
                     {
                             tab[n] = 1;
                             n++;
                     }
                     else
                     {
                         tab[n] = 0;
                         n++;
                     }
               }
               
    }
    else
    {
        return -1;
    }
    
    fclose(plik1);
    
    while(i<stop)
    {
               if(tab[i] == 1)
               {
                         for(j=0; j<dlugosc; j++)
                         {
                                  if(tab[i] == dzielnik2[j])
                                  {
                                            tab[i] = 0;
                                            i++;
                                  }
                                  else
                                  {
                                            tab[i] = 1;
                                            i++;
                                  }
                         }
                         i = 0;
                         k++;
                         i = i + k;
             }
             else
             {
                    i = 0;
                    k++;
                    i = i + k;
             }
    }
    
    cout << endl;
    cout << "CRC przed zaszumieniem:" << endl;
    cout << endl;
    
    for(i=calkowita_ilosc_bitow; i<rozmiar_tablicy; i++)
    {
                                 cout << tab[i];
    }
             
    cout << endl;
//-----------------------------------------------------------------------------------------------------------------------------------------
    i=0, j=0, k=0, l=0, m=0, n=0;
    
    for(m=0; m<rozmiar_tablicy; m++)                //zerowanie tablicy
    {
          tab2[m] = 0;
    }
    
    if((plik2 = fopen("po_zaszumieniu.txt","r")) != NULL)          //kopiowanie bitów z pliku tekstowego do tablicy
    {                                                     //w celu losowej zamiany czêœci z nich
               while ((znak2 = fgetc(plik2)) != EOF)
               {
                     if(znak2 == '1')
                     {
                             tab2[n] = 1;
                             n++;
                     }
                     else
                     {
                         tab2[n] = 0;
                         n++;
                     }
               }
               
    }
    else
    {
        return -1;
    }
    
    fclose(plik2);
    
    while(i<stop)
    {
               if(tab2[i] == 1)
               {
                         for(j=0; j<dlugosc; j++)
                         {
                                  if(tab2[i] == dzielnik2[j])
                                  {
                                            tab2[i] = 0;
                                            i++;
                                  }
                                  else
                                  {
                                            tab2[i] = 1;
                                            i++;
                                  }
                         }
                         i = 0;
                         k++;
                         i = i + k;
             }
             else
             {
                    i = 0;
                    k++;
                    i = i + k;
             }
    }
    
    cout << endl;
    cout << "CRC po zaszumieniu:" << endl;
    cout << endl;
    
    for(i=calkowita_ilosc_bitow; i<rozmiar_tablicy; i++)
    {
                                 cout << tab2[i];
    }
             
    cout << endl << endl;
    
    for(i=calkowita_ilosc_bitow; i<rozmiar_tablicy; i++)
    {
                                 if(tab[i] == tab2[i])
                                 {
                                            licznik+=1;
                                 }
                                 else
                                 {
                                     licznik+=0;
                                 }
    }
    
    if(licznik == dodane_wyzerowane_bity)
    {
               cout << "Wartosci CRC sa rowne. Nie wykryto bledu" << endl;
    }
    else
    {
               cout << "Wartosci CRC sa rozne. Wykryto blad!" << endl;
    }
    cout << endl;
    
    delete[] tab2;
    delete[] tab;
    system("pause");
    return 0;
}
