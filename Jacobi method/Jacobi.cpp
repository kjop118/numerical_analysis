#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


void pokaz_macierz(int &n, float **tab)
{
     for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout<<tab[i][j]<<"     ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
 
float miara_bledu(float x1[], int n)
{
    float blad = 0;
    
    for(int i = 0; i < n-1; i++)
    {
        blad = blad + ((x1[i]-x1[i+1])*(x1[i]-x1[i+1]));
    }
    blad = sqrt(blad);
    return blad;
}
 
int main()
{
    fstream plik;
    plik.open("jacobi.txt",ios::in);

    if (plik.good()==false)
    {
        cout<<"** Nie udalo sie otworzyc pliku **"<<endl;
        exit(0);
    }

    cout.precision(4); //ustawiam precyzje do czterech miejsc po przecinku
    cout.setf(ios::fixed);
    int n, iteracje;

    cout<<endl<<"********************* Pobieram ilosc wierszy macierzy z pliku **********************"<<endl;

    plik >> n;
    cout<<endl<<"                        Ilosc wierszy macierzy wynosi: "<<n<<endl<<endl;


    //deklaracja tablicy dynamicznej dla macierzy
    float ** macierz = new float*[n];
    float **A = new float*[n]; 
    float *D = new float[n];
    float *x1 = new float[n];
    float *x2 = new float[n];

    for(int i = 0; i < n ; i++)
    {
        macierz[i] = new float[n];
        A[i] = new float[n];
    }    

    //deklaracja tablicy dynamicznej dla rozwiazan ukladu rownan
    float *b = new float[n];


    //pobieram z pliku elementy macierzy
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            plik >> A[i][j];
        }
        
        plik >> b[i];
    }

    //licze wartości na przekątnej macierzy D^(-1)
    for(int i = 0; i < n; i++)
    {        
        D[i]= 1/A[i][i];
    }

    float x[n];
    int sprawdzam = 0;
    //sprawdzam czy macierz jest diagonalnie słabo dominująca
    
    cout<<"****** Sprawdzam czy macierz podana ponizej jest diagonalnie słabo dominująca ******"<<endl;
    pokaz_macierz(n, A);
    
    for(int i=0; i<n; i++)
    {
        x[i]=0;
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            {
                x[i] = x[i]+A[i][j];
            }

        }

        if(A[i][i] >= x[i])
            sprawdzam++;
        
        if(A[i][i] > x[i])
            sprawdzam++;
    }
    
    cout<<"                         Liczba spełnionych warunkow: "<<sprawdzam<<endl; 
    
    if(sprawdzam > n)
    {   
        cout<<"               Macierz spełniła minimalną liczbę ("<<n+1<<") warunkow"<<endl;
        cout<<"                  Macierz jest diagonalnie słabo dominująca\n"<<endl;
    }
    else
    {
        cout<<"               Macierz nie spełniła minimalnej liczby ("<<n+1<<") warunkow"<<endl;
        cout<<"                  Macierz NIE jest diagonalnie słabo dominująca\n"<<endl;
    }
    
    //licze macierz = -D^(-1)*L+U
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (i == j)
                macierz[i][j] = 0;
            else
                macierz[i][j] = - (A[i][j] * D[i]);
        }
    }

    for (int i=0; i<n; i++)
    {
        x1[i] = 0;
    }
    
    float dokladnosc, blad;

    cout<<"Podaj ilosc iteracji (np. 1000): "; cin >> iteracje;
    cout<<"Podaj poziom dokładności obliczeń (np.0.01): "; cin >> dokladnosc;
    
    int ilosc_iteracji = 0;
    for (int i=0; i<iteracje; i++) 
    {
        for (int j=0; j<n; j++) 
        {
            x2[j] = D[j]*b[j];

            for (int k=0; k<n; k++)
                x2[j] += macierz[j][k]*x1[k];
        }

        for (int j=0; j<n; j++)
            x1[j] = x2[j];

        ilosc_iteracji++;

        blad = miara_bledu(x1, n);
        if (blad < dokladnosc)
            break;
    }
    
    cout<<endl<<"*************************** ROZWIAZANIE UKŁADU RÓWNAŃ ******************************"<<endl;
    cout<<"                      Ilość wykonanych iteracji wynosi: "<<ilosc_iteracji<<endl;
    cout<<"                   Poziom osiągniętego błedu wynosi: "<<blad<<endl;
    cout<<"                    Poziom założonego błedu wynosi: "<<dokladnosc<<endl;
    
    for(int i=0; i<n; i++) 
    {
        cout<<"wynik["<<i<<"] = "<<x1[i]<<"\n";
    }   
    
    plik.close();
    return 0;
 
}
