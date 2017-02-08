#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <stdlib.h>
#include <string>

using namespace std;

struct paczka
{
       int etykieta;
       char znaki;
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
    
    int i=0, liczba=0, j=0, k=0, l=0, m=0;
    int licznik_jedynek = 0, calkowita_ilosc_bitow = 0;
    int licznik_jedynek2 = 0, calkowita_ilosc_bitow2 = 0;
    int licznik_jedynek3 = 0, calkowita_ilosc_bitow3 = 0;
    unsigned char symbol;
    char tablica[8],znak;
    
    FILE *plik;
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
    
    if((plik = fopen("dane.txt","r")) != NULL)
    {
               while ((znak = fgetc(plik)) != EOF)
               {
                     if(znak == '1')
                     {
                             licznik_jedynek+=1;
                     }
                     calkowita_ilosc_bitow+=1;
               }
    }
    fclose(plik);
    
    cout << "Ilosc bitow danych wejsciowych: " << calkowita_ilosc_bitow << endl;
    cout << endl;
    
    int rozmiar_paczki = 0, rozmiar_paczki_w_bitach = 0;
    int ilosc_paczek = 0, mod = 0, temp = 0;
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
             cout << "Rozmiar ostatniej paczki: " << mod << endl << endl;
    
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
             cout << "Rozmiar ostatniej paczki: " << mod << endl << endl;
    }
    
    //tablica danych wejœciowych
    
    struct paczka **tablica_danych_in = new struct paczka *[ilosc_paczek];
    for(j=0; j<ilosc_paczek; j++)
    {
                    tablica_danych_in[j] = new struct paczka[rozmiar_paczki_w_bitach];
    }
    
    //tablica pomieszanych paczek
            
    struct paczka **tablica_danych_out = new struct paczka *[ilosc_paczek];
    for(j=0; j<ilosc_paczek; j++)
    {
             tablica_danych_out[j] = new struct paczka[rozmiar_paczki_w_bitach];
    }
    
    // tablica posortowanych paczek
            
    struct paczka **tablica_danych_posortowana = new struct paczka *[ilosc_paczek];
    for(j=0; j<ilosc_paczek; j++)
    {
             tablica_danych_posortowana[j] = new struct paczka[rozmiar_paczki_w_bitach];
    }
//--------------------------------------------------------------------------------------------------------------------------------------
                                                                                                                                      
    j=0; k=0;
             
             
            if((plik = fopen("dane.txt","r")) != NULL)          //kopiowanie bitów z pliku tekstowego do tablicy
            {
             while ((znak = fgetc(plik)) != EOF)
             {
                   if(k<rozmiar_paczki_w_bitach)
                   {
                                     tablica_danych_in[j][k].znaki = znak;
                                     tablica_danych_in[j][k].etykieta = j;
                                     k++;
                   }
                   else if(j<ilosc_paczek)
                   {
                       j++;
                       k=0;
                   }           
             }  
            }
            fclose(plik);
            
            // losowe mieszanie paczek
            int wylosowana_liczba = 0, licz = 0, wylosowane[ilosc_paczek];
            
            srand(time(NULL));
            for(j=0; j<ilosc_paczek; j++)
            {
                    losuj:
                    wylosowana_liczba = rand() % ilosc_paczek;
                    for(k=0; k<rozmiar_paczki_w_bitach; k++)
                    {
                             tablica_danych_out[j][k].znaki = tablica_danych_in[wylosowana_liczba][k].znaki;
                             tablica_danych_out[j][k].etykieta = tablica_danych_in[wylosowana_liczba][k].etykieta;
                    }
                    
                    for(l=0; l<licz; l++)
                    {
                            if(wylosowana_liczba!=wylosowane[l])
                            {                      
                            }
                            else
                            {
                                goto losuj;
                            }
                    }
                    wylosowane[licz] = wylosowana_liczba;
                    licz++;
            }
            
            FILE *plik2;
            if((plik2 = fopen("kolejnosc paczek po mieszaniu.txt","w")) != NULL)
            {
                     for(j=0; j<ilosc_paczek; j++)
                     {
                              //cout << wylosowane[j] << endl;
                              if(fprintf(plik2, "%d\\", wylosowane[j])<0)
                              return -1;
                     }
            }
            else
            {
                return -1;
            }
            fclose(plik2);
            
            FILE *plik3;
            if((plik3 = fopen("dane po mieszaniu paczek.txt","w")) != NULL)
            {
                     for(j=0; j<ilosc_paczek; j++)
                     {
                              if(mod!=0 && j==ilosc_paczek-1)
                              {
                                        for(k=0; k<mod; k++)
                                        {
                                                 if(tablica_danych_out[j][k].znaki != ' ')
                                                 {
                                                 if(fprintf(plik3, "%c", tablica_danych_out[j][k].znaki) < 0)
                                                 return -1;
                                                 }
                                        }
                              }
                              else
                              {
                                        for(k=0; k<rozmiar_paczki_w_bitach; k++)
                                        {
                                                 if(tablica_danych_out[j][k].znaki != ' ')
                                                 {
                                                 if(fprintf(plik3, "%c", tablica_danych_out[j][k].znaki) < 0)
                                                 return -1;
                                                 }
                                        }
                              }
                     } 
            }
            else
            {
                return -1;
            }    
            fclose(plik3);
            
            if((plik3 = fopen("dane po mieszaniu paczek.txt","r")) != NULL)
            {
               while ((znak = fgetc(plik3)) != EOF)
               {
                     if(znak == '1')
                     {
                             licznik_jedynek2+=1;
                     }
                     calkowita_ilosc_bitow2+=1;
               }
            }
            fclose(plik3);
            
            cout << "ilosc bitow po mieszaniu: " << calkowita_ilosc_bitow2 << endl;
            
            // sortowanie paczek
            
            for(j=0; j<ilosc_paczek; j++)
            {
                     m=0;
                     szukaj:
                     if(tablica_danych_in[j][0].etykieta == tablica_danych_out[m][0].etykieta)
                     {
                      for(k=0; k<rozmiar_paczki_w_bitach; k++)
                      {
                       tablica_danych_posortowana[j][k].znaki = tablica_danych_out[m][k].znaki;
                       tablica_danych_posortowana[j][k].etykieta = tablica_danych_out[m][k].etykieta;    
                      }
                     }
                     else
                     {
                         m++;
                         goto szukaj;    
                     }
            }
            
            FILE *plik4;
            if((plik4 = fopen("kolejnosc paczek po posortowaniu.txt","w")) != NULL)
            {
                     for(j=0; j<ilosc_paczek; j++)
                     {
                              if(fprintf(plik4, "%d\\", tablica_danych_posortowana[j][0].etykieta)<0)
                              return -1;
                     }
            }
            else
            {
                return -1;
            }
            fclose(plik4);
            
            FILE *plik5;
            if((plik5 = fopen("dane po posortowaniu paczek.txt","w")) != NULL)
            {
                     for(j=0; j<ilosc_paczek; j++)
                     {
                              if(mod!=0 && j==ilosc_paczek-1)
                              {
                                        for(k=0; k<mod; k++)
                                        {
                                                 if(tablica_danych_posortowana[j][k].znaki != ' ')
                                                 {
                                                 if(fprintf(plik5, "%c", tablica_danych_posortowana[j][k].znaki) < 0)
                                                 return -1;
                                                 }
                                        }
                              }
                              else
                              {
                                        for(k=0; k<rozmiar_paczki_w_bitach; k++)
                                        {
                                                 if(tablica_danych_posortowana[j][k].znaki != ' ')
                                                 {
                                                 if(fprintf(plik5, "%c", tablica_danych_posortowana[j][k].znaki) < 0)
                                                 return -1;
                                                 }
                                        }
                              }
                     } 
            }
            else
            {
                return -1;
            }    
            fclose(plik5);
            
            if((plik5 = fopen("dane po posortowaniu paczek.txt","r")) != NULL)
            {
               while ((znak = fgetc(plik5)) != EOF)
               {
                     if(znak == '1')
                     {
                             licznik_jedynek3+=1;
                     }
                     calkowita_ilosc_bitow3+=1;
               }
            }
            fclose(plik5);
            
            cout << "ilosc bitow po sortowaniu: " << calkowita_ilosc_bitow3 << endl << endl;
            
            if(calkowita_ilosc_bitow2 == calkowita_ilosc_bitow3)
            {
                                      cout << "Rozmiar danych jest prawidlowy. Nie wykryto bledu." << endl << endl;
            }
            else
            {
                cout << "Rozmiar danych jest nieprawidlowy. Wykryto blad!" << endl << endl;
            }
            
           delete[] tablica_danych_in;
           delete[] tablica_danych_out;
           delete[] tablica_danych_posortowana;
            
}
    system("pause");
    return 0;
}
