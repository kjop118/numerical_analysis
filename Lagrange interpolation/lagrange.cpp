#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream plik;
    plik.open("dane.txt",ios::in);

    int ilosc_wezlow;
    cout<<endl<<"Pobieram ilosc wezlow z pliku"<<endl;

    if (plik.good()==false)
    {
        cout<<"Nie udalo sie otworzyc pliku"<<endl;
        exit(0);
    }
    
    plik >> ilosc_wezlow; //zapisuje do zmiennej ilosc wezlow z pliku
    cout<<"Ilosc wezlow wynosi: "<<ilosc_wezlow<<endl<<endl;

    double * tab_x = new double[ilosc_wezlow];
    double * tab_y = new double[ilosc_wezlow];
    double * wynik = new double[ilosc_wezlow];

    cout<<"Pobieram wartosci do obliczen...";

    for(int i = 0; i < ilosc_wezlow; i++)
    {
        plik >> tab_x[i];
        plik >> tab_y[i];

    }
    cout<<endl;

    cout<<"PUNKTY:"<<endl;
    for(int i = 0; i < ilosc_wezlow; i++)
    {
        cout<<"x"<<i<<": "<<tab_x[i]<<"\t";
        cout<<"y"<<i<<": "<<tab_y[i]<<endl;
    }
    cout<<endl;

    double wartosc;
    cout<<"Podaj punkt dla ktorego zostanie obliczona wartosc wielomianu: ";
    cin >> wartosc;

    //OBLICZENIE
    for(int i = 0; i< ilosc_wezlow; i++)
    {
        wynik[i] = tab_y[i]; //to jest moja wartosc f(x)

        //licze wartosc licznika
        for(int j = 0; j < ilosc_wezlow; j++)
        {
            if(tab_x[i] != tab_x[j])
            {
                wynik[i] *= (wartosc - tab_x[j]);
            }
        }

        //licze wartosc mianownika
        for(int j = 0; j < ilosc_wezlow; j++)
        {
            if(tab_x[i] != tab_x[j])
            {
                wynik[i] /= (tab_x[i]- tab_x[j]);
            }
        }
    }

    double suma = 0;
    cout<<"Wartosc wielomianu interpolacji w wybranym punkcie:"<<endl;
    for(int i = 0; i < ilosc_wezlow; i++)
    {
        suma += (wynik[i]);
    }
    cout<<suma<<endl;

    plik.close();

    return 0;
}