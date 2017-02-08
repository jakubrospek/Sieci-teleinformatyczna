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
    
  system("pause");
  return 0;
  }
}
