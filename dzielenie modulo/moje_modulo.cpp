#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
    int w1 = 0, w2 = 0;
	int dzielnik = 10;
	fstream plik1, plik2;
	plik1.open("przed_zaszumieniem.txt", ios::in | ios::binary);
 
	if(plik1.good()==true)
	{
		plik1.seekg (0, plik1.end);
		int length = plik1.tellg();
		plik1.seekg (0, plik1.beg);
		char * bufor1 = new char [length];
		plik1.read (bufor1,length);
 
		for (int i=0; i<length; i++)
		{
                         w1+=bufor1[i];
		}
		w1=w1%dzielnik;
	}
	else
	{
		cout << "blad odczytu pliku" << endl;
	}
    
    cout << endl;
    cout << "Wynik operacjii modulo przed zaszumieniem: " << w1 << endl;
//------------------------------------------------------------------------------------------------------------------------------------------	

	plik2.open("po_zaszumieniu.txt", ios::in | ios::binary);
 
	if(plik2.good()==true)
	{
		plik2.seekg (0, plik2.end);
		int length = plik2.tellg();
		plik2.seekg (0, plik2.beg);
		char * bufor2 = new char [length];
		plik2.read (bufor2,length);
 
		for (int i=0; i<length; i++)
		{
                         w2+=bufor2[i];
		}
		w2=w2%dzielnik;
	}
	else
	{
		cout << "blad odczytu pliku" << endl;
	}
	
	
	cout << "Wynik operacjii modulo po zaszumieniu: " << w2 << endl;
	cout << endl << endl;
	
	if(w1 == w2)
	{
          cout << "Wartosci sa sobie rowne. Nie wykryto bledu." << endl;
    }
    else
    {
        cout << "Wartosci sa rozne. Wykryto blad!" << endl;
    }
	
	cout << endl;
	system("pause");
    return 0;
}
