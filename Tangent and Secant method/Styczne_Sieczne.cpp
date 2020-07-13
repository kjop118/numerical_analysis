#include <iostream>
#include <math.h>

using namespace std;

//alternatywna funkcja
/*
double f(double x)
{
  return cos(x);
}


double fp(double x)
{
  return sin(x)*(-1);
}
*/

// funkcja f(x) = 6x^4+6x^3−11x^2+x−2
double f(double x)
{
  double x4 = pow(x,4);
  double x3 = pow(x,3);
  double x2 = pow(x,2);
  return 6*x4 + 6*x3 - 11*x2 + x - 2;
}

// pochodna funkcji f'(x) = 24*x^3 + 18*x^2 - 22*x + 1
double fp(double x)
{
  double x3 = pow(x,3);
  double x2 = pow(x,2);
  return 24*x3 + 18*x2 - 22*x + 1;
}

int main()
{

  cout.precision(8); //ustawiam precyzje do czterech miejsc po przecinku
  cout.setf(ios::fixed);

  //Metoda Newtona (stycznych)
  double x0, epsilon, x1,f0,f1;
  int licznik = 0;
  
  cout << "\nDANE METODA STYCZNYCH\n";
  cout <<"Podaj punkt startowy x0 = ";
  cin >> x0;
  cout <<"Podaj dokladnosc epsilon = ";
  cin >> epsilon;

  while (true)
  {
    licznik++;
    f0 = f(x0);  
    f1 = fp(x0);    
    x1 = x0;
    x0 = x0 - (f0 / f1); //przyblienie rozwiazania czyli punkt przeciecia stycznej z OX
    f0 = f(x0);

    if(fabs(f0) < epsilon)  break; 
  }

  //Metoda siecznych
  double y0, y1, y2, g0, g1, g2, epsylon;
  int counter = 0;

  cout << "\nDANE METODA SIECZNYCH\n";
  cout << "Podaj punkty startowe\n";
  cout << "y1 = "; cin >> y1;
  cout << "y2 = "; cin >> y2;
  cout <<"Podaj dokladnosc epsylon = "; cin >> epsylon;

  while(true)
  {
    counter++;
    g1 = f(y1); 
    g2 = f(y2); 
    y0 = y2 - (g2 * (y2 - y1) / (g2 - g1)); //przyblizenie rozwiazania
    g0 = f(y0);
 
    if(fabs(g0) < epsylon)  break;
    y2 = y1; 
    y1 = y0; 

  }

  cout << "\n------------------------------------------------- \n";
  cout << "\nWYNIKI\n";
  cout << "Rozwiazywane rownanie: f(x) = 6x^4+6x^3−11x^2+x−2 \n";
  cout << "\nMETODA STYCZNYCH\n";
  cout << "Znalezione rozwiązanie x"<<licznik<<" = " << x0 << endl;
  cout << "Wartosc funkcji w rozwiazaniu wynosi "<< f0 << endl;
  cout << "Wykonano "<<licznik<<" krokow\n"<<endl;
  cout << "\nMETODA SIECZNYCH\n";
  cout << "Znalezione rozwiązanie y"<<counter<<" = " << y0 << endl;
  cout << "Wartosc funkcji w rozwiazaniu wynosi "<< g0 << endl;
  cout << "Wykonano "<<counter<<" krokow\n"<<endl;

  return 0;
} 