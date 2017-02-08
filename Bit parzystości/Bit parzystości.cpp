// read a file into memory
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <stdlib.h>
#include <string>

using namespace std;

int main () {
  ifstream is ("W3.jpg", std::ifstream::binary);
  if (is) {
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
    int i=0, liczba=0;
    unsigned char symbol;
    char tablica[8];
    
    if((plik = fopen("przed_zaszumieniem.txt","w")) != NULL)
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
//-----------------------------------------------------------------------------------------------------------------------------------------
    int a, j=0, k=0, bit1=0, bit2=0, licznik = 0, licznik2 = 0, calkowita_ilosc_bitow = 0, calkowita_ilosc_bitow2 = 0, losowa = 0;
    char znak, znak2;

    FILE *plik2;
    
    if((plik2 = fopen("przed_zaszumieniem.txt","r")) != NULL)
    {
               while ((znak = fgetc(plik2)) != EOF)
               {
                     if(znak == '1')
                     {
                             licznik+=1;
                     }
                     
                     calkowita_ilosc_bitow+=1;
               }
    }
    
    fclose(plik2);
    
    cout << endl;
    cout << "Przed zaszumieniem:" << endl << endl;
    
    cout << "calkowita ilosc bitow: " << calkowita_ilosc_bitow << endl;
    cout << "ilosc jedynek: " << licznik << endl;
    
    if(licznik % 2 == 0)
    {
               cout << "Wiadomosc ma parzysta liczbe jedynek. Bit parzystosci wynosi 0" << endl;
               bit1=0;
    }
    else
    {
        cout << "Wiadomosc ma nieparzysta liczbe jedynek. Bit parzystosci wynosi 1" << endl;
        bit1=1;
    }
    
    
    char *tab = new char [calkowita_ilosc_bitow];
    int *tab2 = new int [calkowita_ilosc_bitow];
    
    if((plik2 = fopen("przed_zaszumieniem.txt","r")) != NULL)          //kopiowanie bitów z pliku tekstowego do tablicy
    {                                                     //w celu losowej zamiany czêœci z nich
               while ((znak = fgetc(plik2)) != EOF)
               {
                     tab[j] = znak;
                     j++;
               }
               
    }
    
    fclose(plik2);
    
    for(j=0; j<calkowita_ilosc_bitow; j++)                //zerowanie tablicy
    {
          tab2[j] = 0;
    }
    
    /*
    for(j=0; j<calkowita_ilosc_bitow; j++)                //wyœwietlanie tablicy z bitami przed zamian¹
    {
          cout << tab[j];
    }
    */
    
    for(k=0; k<100; k++)                                  //zamina 100 losowych bitów
    {
             if(tab2[losowa] != 1)
             {
                             losowanie:
                             losowa = rand() % calkowita_ilosc_bitow;
                             tab2[losowa] = 1;
                             
                             if(tab[losowa] == '0')
                             {
                                            tab[losowa] = '1';
                             }
                             else
                             {
                                 tab[losowa] = '0';
                             }
             }
             else
             {
                 goto losowanie;
             }
    }
    
    /*
    for(i=0; i<calkowita_ilosc_bitow; i++)                //wyœwietlanie tablicy z bitami po zamianie (jest prawid³owe)
    {
          cout << tab[i];
    }
    */
    
    FILE *plik3;
    
    if((plik3 = fopen("po_zaszumieniu.txt","w")) != NULL)          //zapis wiadomoœci ze 100 zmienionymi bitami
    {                                                     //do nowego pliku tekstowego
               for(j=0; j<calkowita_ilosc_bitow; j++)
               {
                        if(fprintf(plik3, "%c", tab[j]) < 0)
                        return -1;
               }
    }
    else
    {
        return -1;
    }
    
    fclose(plik3);
    
    if((plik3 = fopen("po_zaszumieniu.txt","r")) != NULL)
    {
               while ((znak2 = fgetc(plik3)) != EOF)
               {
                     if(znak2 == '1')
                     {
                             licznik2+=1;
                     }
                     
                     calkowita_ilosc_bitow2+=1;
               }
    }
    
    fclose(plik3);
    
    cout << endl;
    cout << "Po zaszumieniu:" << endl << endl;
    
    cout << "calkowita ilosc bitow: " << calkowita_ilosc_bitow2 << endl;
    cout << "ilosc jedynek: " << licznik2 << endl;
    
    if(licznik2 % 2 == 0)
    {
               cout << "Wiadomosc ma parzysta liczbe jedynek. Bit parzystosci wynosi 0" << endl;
               bit2=0;
    }
    else
    {
        cout << "Wiadomosc ma nieparzysta liczbe jedynek. Bit parzystosci wynosi 1" << endl;
        bit2=1;
    }
    
    cout << endl;
    
    if(bit1 == bit2)
    {
            cout << "Bity parzystosci sa sobie rowne. Nie wykryto bledu." << endl;
    }
    else
    {
        cout << "Bity parzystosci sa rozne. Wykryto blad!" << endl;
    }
    
    cout << endl;
//-----------------------------------------------------------------------------------------------------------------------------------------
}
  system("pause");
  return 0;
}
