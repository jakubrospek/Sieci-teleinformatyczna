#include<iostream>

using namespace std;

class Stock
{
      string company;
      int shares;
      int share_val;
      
      public:
             Stock()
             {
                     cout << "Wywolano konstruktor domyslny\n";
              company = "bez nazwy";
              shares = 0;
              share_val = 0;
             }
             ~Stock()
             {
                      cout << "Wywolano destruktor\n";
             }
};
/*
Stock::Stock()
{
              cout << "Wywolano konstruktor domyslny\n";
              company = "bez nazwy";
              shares = 0;
              share_val = 0;
}

Stock::~Stock()
{
               cout << "Wywolano destruktor\n";
}
*/
int main()
{
    //Stock *s = new Stock;
    //delete s;
    {
    Stock s;
}
    //delete &s;
    
    system("pause");
    return 0;
}
