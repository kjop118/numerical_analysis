#include <iostream>
#include <math.h>

using namespace std;


//f(x) = cos(4x^4+x)
double funkcja_trygonometryczna(double x)
{
	double x4 = pow(x, 4);
    double wynik = cos(4*x4+x);
	return wynik;
} 

//f(x) = 2x^7 + 4x^3 + 2x + 1 
double funkcja_wielomianowa(double x)
{
    double x7 = pow(x, 7);
    double x3 = pow(x, 3);
    double wynik = 2*x7 + 4*x3 + 2*x + 1;
    return wynik;
}

//f(x) = ln(x^2 + 2x) 
double funkcja_logarytmiczna(double x)
{
    double x2 = pow(x, 2);
    double wynik = log(x2 + 2*x);
    return wynik;
}

int main() 
{    
    double a, b, a1, b1, dokladnosc, srodek, srodek1;
    double licznik = 0; 
    cout.precision(4); //ustawiam precyzje do czterech miejsc po przecinku
    cout.setf(ios::fixed);

    poczatek:
    cout<<endl<<"       METODA BISEKCJI"<<endl;
    cout<<"Podaj początek przedziału (a): "; cin >> a;
    cout<<"Podaj koniec przedziału (b): "; cin >> b;
    cout<<"Podaj dokładność obliczen (np. 0.01): "; cin >> dokladnosc;

    //Obliczam wartości funkcji na granicy przedziałow
	a1 = funkcja_wielomianowa(a);
	b1 = funkcja_wielomianowa(b);	
	
	if(a1 * b1 < 0)
    {
         for(;;)
        {
            srodek = (a + b) / 2;
            srodek1 = funkcja_wielomianowa(srodek);

            if(fabs(srodek1) < dokladnosc)
               break; 

            licznik++;
            if(a1 * srodek1 < 0)
            {
                b = srodek;
                b1 = srodek1;
            }
            else
            {
                a = srodek; 
                a1 = srodek1;
            }
        }
    }
    else
    {
        cout << "Brak miejsc zerowych w przedziale. Podaj nowy przedział"<<endl;
        goto poczatek;
    }

    cout << endl << "Ilość zrealizowanych krokow obliczeń: " << licznik <<endl;
    cout << endl << "                 WYNIK" << endl;
    cout << "Punkt rozwiązania rownania "<<srodek<<endl;
    cout << "Wartosc funkcji w punkcjie "<<srodek<<" wynosi: "<<funkcja_wielomianowa(srodek)<<endl<<endl;
    
    return 0;
}