#include<iostream>

using namespace std;

int main()
{
    string dzielnik1;
    
    cout << "Podaj dzielnik:" << endl;
    cin >> dzielnik1;
    
    int i=0, j=0, k=0, l=0, dlugosc = dzielnik1.length(), dodane_wyzerowane_bity = dlugosc - 1;
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
             //cout << dzielnik2[i];
             //cout << endl;
    }
    
    int tab[17]={1,1,0,1,0,0,1,1,1,0,1,1,1,0,/*|*/0,0,0};
    
    
    
    while(i<17-4)
    {
               if(tab[i] == 1)
               {
             
                         cout << i << "===" << endl;
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
    
    for(i=0; i<17; i++)
             {
                      cout << tab[i];
             }
             
             cout << endl;
    
    
    system("pause");
    return 0;
}
