#include<iostream>

using namespace std;

int main()
{
    int ile_tablic;
    int rozm_tablicy;
    
    cout << "Podaj ilosc tablic" << endl;
    cin >> ile_tablic;
    cout << "Podaj rozmiar tablic" << endl;
    cin >> rozm_tablicy;
    
    int **tab = new int*[ile_tablic];
    for(int j=0; j<ile_tablic; j++)
    {
             tab[j] = new int[rozm_tablicy];
    }
    
    for(int j=0; j<ile_tablic; j++)
    {
            for(int k=0; k<rozm_tablicy; k++)
            {
                    tab[j][k] = k+1;
            }
    }
    cout << endl;
    
    for(int j=0; j<ile_tablic; j++)
    {
            for(int k=0; k<rozm_tablicy; k++)
            {
                    cout << tab[j][k] << endl;
            }
            cout << endl;
    }
    
    
    system("pause");
    return 0;
}
