
#include <fstream>
#include <iostream>
#include <cstdlib>


using namespace std;


int main()
{
    int wynik=0;
	int dzielnik = 8;
	fstream plik;
	plik.open("po_zaszumieniu.txt", ios::in | ios::binary);
 
	if(plik.good()==true)
	{
		plik.seekg (0, plik.end);
		int length = plik.tellg();
		plik.seekg (0, plik.beg);
		char * bufor = new char [length];
		plik.read (bufor,length);
 
		for (int i = 0; i<length; i++)
		{
			if(i%10==0) wynik=wynik%dzielnik;
			else wynik+=bufor[i];
		}

		wynik=wynik%dzielnik;
	}
	else
	{
		cout<<"blad odczytu pliku"<<endl;
	}

	cout<<wynik<<endl;

	system("PAUSE");
    return 0;
}
