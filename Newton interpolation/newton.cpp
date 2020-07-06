#include <iostream>
#include <fstream>
using namespace std; 
  

int main() 
{ 
    fstream plik;
    plik.open("newton.txt",ios::in);

    int ilosc_wezlow;
    cout<<endl<<"Pobieram ilosc wezlow z pliku"<<endl;

    if (plik.good()==false)
    {
        cout<<"Nie udalo sie otworzyc pliku"<<endl;
        exit(0);
    }
    
    plik >> ilosc_wezlow; //zapisuje do zmiennej ilosc wezlow z pliku
    cout<<"Ilosc wezlow wynosi: "<<ilosc_wezlow<<endl;

    double tab_x[ilosc_wezlow];
    double tab_y[ilosc_wezlow][ilosc_wezlow]; 

    cout<<endl<<"Pobieram wartosci do obliczen...";

    for(int i = 0; i < ilosc_wezlow; i++)
    {
        plik >> tab_x[i];
        plik >> tab_y[i][0];

    }
    cout<<endl;



    cout<<"PUNKTY:"<<endl;
    for(int i = 0; i < ilosc_wezlow; i++)
    {
        cout<<"x"<<i<<": "<<tab_x[i]<<"\t";
        cout <<"tab_y["<<i<<"][0] = " << tab_y[i][0]<<endl;
    }
    cout<<endl;


    //obliczam ilorazy roznicowe kazdego rzedu
    
    for (int i = 1; i < ilosc_wezlow; i++) 
    { 
        for (int j = 0; j < ilosc_wezlow - i; j++) 
        {
            tab_y[j][i] = tab_y[j + 1][i - 1] - tab_y[j][i - 1]; 
            tab_y[j][i] /= (tab_x[j+i]-tab_x[j]);
        }
    }  
    cout<<endl;


    //Pokazanie zawartosci tablicy dwuwymiarowej

    cout<<"Wspolczynniki wielomianu interpolacyjnego:"<<endl;
    for (int i = 0; i < ilosc_wezlow; i++) 
    { 
        cout << "tab_x["<<i<<"] = "<< tab_x[i]<<" ::  "; 
 
        for (int j = 0; j < ilosc_wezlow - i; j++)
        {
            cout << "tab_y["<<i<<"]["<<j<<"] = " << tab_y[i][j]<<"   ";
        }
       cout<<endl;
    } 
  
    double value; 
    cout<<endl<<"Podaj punkt dla ktorego zostanie obliczona wartosc wielomianu: ";
    cin >> value;
    
    double suma = tab_y[0][0]; //poczatkowo w zmiennej suma znajduje sie pierwszy 
    double iloraz = 1;

    //Obliczam wielomian interpolacji
    for (int i = 1; i < value + 1; i++)
    { 
        iloraz *= (value - tab_x[i-1]);
        suma += iloraz * tab_y[0][i];    
    }
 
    cout <<endl<<"Wartosc wielomianu w wezle "<<value<<" wynosi: "<<suma<<endl<<endl; 
    plik.close();

    return 0; 
} 
