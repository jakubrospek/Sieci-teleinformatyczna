#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <cmath>
//using namespace System;
using namespace std;
 
int suma(char a)
{
	int efekt = 0;
	while (a>0)
	{
		if (a%2){efekt+=1;}
		a=floor(a/2);
		return efekt%2;
	}
}

int ktory(int rozmiar)
{	
	srand(time(0));
	return rand()%(rozmiar+1);
}

char xory(char a, char b)
{
     if(a==b) return 0;
     else return 1;
}

int main()
{
    int n=3, i, j;
    char crc[4]={0,1,1,0};
	stringstream zamienione;
	fstream plik;
	plik.open("po_zaszumieniu.txt", ios::in | ios::binary);
 
	if(plik.good()==true)
	{
		plik.seekg (0, plik.end);
		int length = plik.tellg();
		plik.seekg (0, plik.beg);
		char * bufor = new char [length];
		plik.read (bufor,length);
        char * tablica = new char [length*8+n];
		for (i=0; i<length; i++)
		{
			for(j=7; j>=0; j--)
			{
                     tablica[(i*8)+j]=bufor[i]%2;
                     bufor[i]=floor(bufor[i]/2);
            }
		}
		for(i=n; i>=0; i--) {tablica[length*8+i]=0;}
		for (i=0; i<((length*8)-1); i++)
		{
            if(tablica[i]!=0)
            {
                for(j=0; j<4; j++)
                tablica[i]=xory(tablica[i],crc[j]);            
            }
        }

			//zabu¿enie
		float zabuzenie=0.01; //zadeklaruj jak du¿e ma byæ zabu¿enie
		int ile = length*zabuzenie;
		char * newbufor = new char [length*8+n];
		newbufor=tablica;
		
		for (i = 0; i<ile; i++)
		{
			int j = ktory(length*8);
			int potega = rand()%9;
			newbufor[j]=(tablica[j]+pow(2.0,potega));
			zamienione<<"bit "<<j<<" bajt "<<potega<<endl;
		}

		for (i=0; i<length; i++)
		{
			for(j=7; j>=0; j--)
			{
                     tablica[(i*8)+j]=bufor[i]%2;
                     bufor[i]=floor(bufor[i]/2);
            }
		}
		for(i=n; i>=0; i--) {tablica[length*8+i]=0;}
		for (i=0; i<((length*8)-1); i++)
		{
            if(tablica[i]!=0)
            {
                for(j=0; j<4; j++)
                tablica[i]=xory(tablica[i],crc[j]);            
            }
        }
        
		cout<<"zabuzonych bitow = \1"<<ile<<endl;
		for(i=n; i>=0; i--) {cout<<tablica[length*8+i];}
		cout<<endl;
	}
	else
	{
		cout<<"blad odczytu pliku"<<endl;
	}


	system("PAUSE");
    return 0;
}
