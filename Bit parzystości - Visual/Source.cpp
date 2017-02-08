#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace System;
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

int main(array<System::String ^> ^args)
{
    int wynik=0;
	stringstream zamienione;
	fstream plik;
	plik.open("plik.txt", ios::in | ios::binary);
 
	if(plik.good()==true)
	{
		plik.seekg (0, plik.end);
		int length = plik.tellg();
		plik.seekg (0, plik.beg);
		char * bufor = new char [length];
		plik.read (bufor,length);
 
		for (int i=0; i<length; i++)
		{
			wynik+=suma(bufor[i]);
			wynik=wynik%2;
			cout<<bufor[i];
		}
		cout<<endl<<endl<<endl<<"bit parzystosci = "<<wynik<<endl<<endl;

			//zabu¿enie
		float zabuzenie=0.01; //zadeklaruj jak du¿e ma byæ zabu¿enie
		int ile = length*zabuzenie;
		char * newbufor = new char [length];
		newbufor=bufor;
		for (int i = 0; i<ile; i++)
		{
			int j = ktory(length);
			int potega = rand()%9;
			newbufor[j]=(bufor[j]+pow(2,potega));
			zamienione<<"bit "<<j<<" bajt "<<potega<<endl;
		}
		
		wynik = 0;

		for (int i=0; i<length; i++)
		{
			wynik+=suma(newbufor[i]);
			wynik=wynik%2;
			cout<<newbufor[i];
		}
		cout<<endl<<endl<<endl<<"bit parzystosci = "<<wynik<<endl;
		cout<<endl<<"zabuzonych bitow = "<<ile<<" sa to: "<<zamienione<<wynik<<endl;
	}
	else
	{
		cout<<"blad odczytu pliku"<<endl;
	}


	system("PAUSE");
    return 0;
}