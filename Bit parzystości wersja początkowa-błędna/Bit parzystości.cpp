#include <fstream>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <bitset>
 
 
using namespace std;
 
int main()
{
    
//--------------------------------------------------------------------------------------------------------------------------------- 

    ifstream plik;
    string napis;
    plik.open("W3.jpg");
    getline(plik, napis);
    plik.close();
 
    int a, b, i=0, j=0, licznik = 0, licznik2 = 0, calkowita_ilosc_bitow = 0, calkowita_ilosc_bitow2 = 0, losowa = 0;
    char znak, znak2;
    b = napis.length();
 
    ofstream bity1;
    bity1.open ("bity1.txt");
    for(a=0;a<b;a++)
    {
      bity1 << bitset<CHAR_BIT>(napis[a]);
    }
    
    bity1.close();
 
//----------------------------------------------------------------------------------------------------------------------------------    
    /*ofstream bity2;
    bity2.open ("bity2.txt");
    for(a=0;a<b;a++)
    {
      bity2 << bitset<CHAR_BIT>(napis[a]);
    }
    
    bity2.close();*/
    
    FILE *plik2;
    
    if((plik2 = fopen("bity1.txt","r")) != NULL)
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
    }
    else
    {
        cout << "Wiadomosc ma nieparzysta liczbe jedynek. Bit parzystosci wynosi 1" << endl;
    }
    
    system("pause");
    char tab[calkowita_ilosc_bitow];
    int tab2[calkowita_ilosc_bitow];
    
    if((plik2 = fopen("bity1.txt","r")) != NULL)          //kopiowanie bitów z pliku tekstowego do tablicy
    {                                                     //w celu losowej zamiany czêœci z nich
               while ((znak = fgetc(plik2)) != EOF)
               {
                     tab[i] = znak;
                     i++;
               }
               
    }
    
    fclose(plik2);
    
    for(i=0; i<calkowita_ilosc_bitow; i++)                //zerowanie tablicy
    {
          tab2[i] = 0;
    }
    
    /*
    for(i=0; i<calkowita_ilosc_bitow; i++)                //wyœwietlanie tablicy z bitami przed zamian¹
    {
          cout << tab[i];
    }
    */
    
    for(j=0; j<100; j++)                                  //zamina 100 losowych bitów
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
    
    if((plik3 = fopen("bity2.txt","w")) != NULL)          //zapis wiadomoœci ze 100 zmienionymi bitami
    {                                                     //do nowego pliku tekstowego
               for(i=0; i<calkowita_ilosc_bitow; i++)
               {
                        if(fprintf(plik3, "%c", tab[i]) < 0)
                        return -1;
               }
    }
    else
    {
        return -1;
    }
    
    fclose(plik3);
    
    if((plik3 = fopen("bity2.txt","r")) != NULL)
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
    }
    else
    {
        cout << "Wiadomosc ma nieparzysta liczbe jedynek. Bit parzystosci wynosi 1" << endl;
    }
    
    cout << endl;
    
    system("pause");
}
