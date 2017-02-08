#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <stdlib.h>
#include <string>
#include <math.h>

using namespace std;

struct paczka
{
       int numer_paczki;
       int rozmiar;
};

int main ()
{
  ifstream is ("W3.jpg", std::ifstream::binary);
  if(is)
  {
    // get length of file:
    is.seekg (0, is.end);
    int length = is.tellg();
    is.seekg (0, is.beg);

    // allocate memory
    char * buffer = new char [length];

    // read data as a block:
    is.read (buffer,length);
    is.close();
    
    FILE *plik;
    int i=0, liczba=0, j=0, k=0;
    unsigned char symbol;
    char tablica[8];
    
    if((plik = fopen("dane.txt","w")) != NULL)
    {
             // print content:
             for(i=0; i<length; i++)
             {
                      symbol = buffer[i];
                      liczba = symbol;
                      itoa(liczba,tablica,2);
                      
                      if(fprintf(plik, "%s", tablica)<0)
                      return -1;
                      liczba=0;
             }
    }
    else
    {
        return -1;
    }
    fclose(plik);
    
    delete[] buffer;
    
    cout << "Dane zostaly zapisane do pliku" << endl;
    cout << endl;
    
    char znak;
    int licznik_jedynek = 0, calkowita_ilosc_bitow = 0;
    
    FILE *plik2;
    
    if((plik2 = fopen("dane.txt","r")) != NULL)
    {
               while ((znak = fgetc(plik2)) != EOF)
               {
                     if(znak == '1')
                     {
                             licznik_jedynek+=1;            //licznik jedynek jest tutaj raczej zbedny
                     }
                     
                     calkowita_ilosc_bitow+=1;
               }
    }
    
    fclose(plik2);
    
    cout << "Calkowita ilosc bitow: " << calkowita_ilosc_bitow << endl;
    cout << endl;
    
    int rozmiar_paczki = 0, rozmiar_paczki_w_bitach = 0;
    int ilosc_paczek = 0, mod = 0;
    char opcja;
    
    cout << "Wybierz jednostke:" << endl << "m - megabajty" << endl << "b - bajty" << endl;
    cin >> opcja;
    
    if(opcja == 'm')
    {
    
             cout << "Podaj rozmiar paczek w MB:" << endl;
             cin >> rozmiar_paczki;
             cout << endl;
    
             rozmiar_paczki_w_bitach = rozmiar_paczki * (1024*1024) * 8;                // ta zmienna pos³u¿y jako licznik
                                                                                 // w pêtli wczytuj¹cej bity do bloku pamiêci
             
             mod = calkowita_ilosc_bitow % rozmiar_paczki_w_bitach;              // rozmiar ostatniej paczki
             ilosc_paczek = calkowita_ilosc_bitow / rozmiar_paczki_w_bitach;
             if(mod != 0)
             {
                    ilosc_paczek++;
             }
             cout << "Ilosc paczek: " << ilosc_paczek << endl;
             cout << "Rozmiar paczki w bitach: " << rozmiar_paczki_w_bitach << endl;
             cout << "Rozmiar ostatniej paczki: " << mod << endl;
    
    }
    else
    {
             cout << "Podaj rozmiar paczek w B:" << endl;
             cin >> rozmiar_paczki;
             cout << endl;
    
             rozmiar_paczki_w_bitach = rozmiar_paczki * 8;                // ta zmienna pos³u¿y jako licznik
                                                                                 // w pêtli wczytuj¹cej bity do bloku pamiêci
             
             mod = calkowita_ilosc_bitow % rozmiar_paczki_w_bitach;              // rozmiar ostatniej paczki
             ilosc_paczek = calkowita_ilosc_bitow / rozmiar_paczki_w_bitach;
             if(mod != 0)
             {
                    ilosc_paczek++;
             }
             cout << "Ilosc paczek: " << ilosc_paczek << endl;
             cout << "Rozmiar paczki w bitach: " << rozmiar_paczki_w_bitach << endl;
             cout << "Rozmiar ostatniej paczki: " << mod << endl;
    }
    
    char **tablica_danych = new char *[ilosc_paczek];
    for(j=0; j<ilosc_paczek; j++)
    {
            tablica_danych[j] = new char[rozmiar_paczki_w_bitach];
            //for(int k=0; k<rozmiar_paczki_w_bitach; k++)
            //tablica_danych[j][k] = '0';
    }
             
    
    
//--------------------------------------------------------------------------------------------------------------------------------------    
    j=0; k=0;
             
             
            if((plik2 = fopen("dane.txt","r")) != NULL)          //kopiowanie bitów z pliku tekstowego do tablicy
            {
             while ((znak = fgetc(plik2)) != EOF)
             {
                   if(k<rozmiar_paczki_w_bitach)
                   {
                                     tablica_danych[j][k]=znak;
                                     k++;
                   }
                   else if(j<ilosc_paczek)
                   {
                       j++;
                       k=0;
                   }       
                       
             }
               
               //cout << znak << endl;
               
            }
    
            fclose(plik2);
            
            
            
    struct paczka tab_wsk[ilosc_paczek];
    for(j=0; j<ilosc_paczek; j++)
    {
         tab_wsk[j].numer_paczki = j;
         tab_wsk[j].rozmiar = strlen(tablica_danych[j]);
    }
    
    //cout << tablica_danych[1][1317983] << endl;
    //cout << tab_wsk[1].rozmiar << endl;
    
    // losowa zamiana paczek:
    
    int * tablica_indeksow = new int [ilosc_paczek];
    
         
         for(int l=0; l<ilosc_paczek; l++)
         {
                 tablica_indeksow[l];
         }
    
    for(int l=0; l<ilosc_paczek; l++)
    {
            cout << tablica_indeksow[l] << endl;
    }





        
}
    system("pause");
    return 0;
}
