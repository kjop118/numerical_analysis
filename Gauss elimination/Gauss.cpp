#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

//funkcja sluzaca do wypisywania zawartosci macierzy
void pokaz_macierz(int &n, float **tab)
{
     for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            cout<<tab[i][j]<<"     ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

int main()
{
    
    fstream plik;
    plik.open("gauss.txt",ios::in);

    if (plik.good()==false)
    {
        cout<<"** Nie udalo sie otworzyc pliku **"<<endl;
        exit(0);
    }

    cout.precision(4); //ustawiam precyzje do czterech miejsc po przecinku
    cout.setf(ios::fixed);
    int n;
    
    cout<<endl<<"******* Pobieram ilosc wierszy macierzy z pliku ********"<<endl;

    plik >> n;
    cout<<endl<<"          Ilosc wierszy macierzy wynosi: "<<n<<endl<<endl;


    //deklaracja tablicy dynamicznej dla macierzy
    float ** macierz = new float*[n];

    for(int i = 0; i < n ; i++)
        macierz[i] = new float[n+1];

    //deklaracja tablicy dynamicznej dla rozwiazan ukladu rownan
    float *wynik = new float[n];
    
    //pobieram z pliku elementy macierzy
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            plik >> macierz[i][j];
        }
    }

    //wypisywanie macierzy
    cout<<"******************* Powstała macierz *******************"<<endl;
    pokaz_macierz(n, macierz);
    cout<<endl<<endl;


    //wykonuje pivoting
    for(int i = 0; i < n; i++)
    {
        
        for(int x = i+1; x < n; x++)
        {
            cout<<"macierz = "<<macierz[x][i]<<endl;
            if(macierz[i][i] < macierz[x][i])
            {
                for(int j = 0; j <= n; j++)
                {
                    double zmienna = macierz[i][j];
                    macierz[i][j] = macierz[x][j];
                    macierz[x][j] = zmienna;
                    cout<<"********** WYGLĄD MACIERZY W TRAKCIE PIVOTINGU *********"<<endl;
        pokaz_macierz(n, macierz);  
                }
            }
            else cout<<"BEZ ZMIAN"<<endl;
        }  
             
    }

    cout<<"************* WYGLĄD MACIERZY PO PIVOTINGU *************"<<endl;
    pokaz_macierz(n, macierz);


    //wykonywanie algorytmu eliminacji gaussa
    for(int i=0; i < n-1; i++)
    {
        for(int x = i+1; x < n; x++)
        {
            double iloraz = macierz[x][i]/macierz[i][i];
            for(int j=0; j<=n; j++)
            {
                macierz[x][j] = macierz[x][j] - iloraz * macierz[i][j];
                cout<<"**************** OBECNY WYGLĄD MACIERZY ****************"<<endl;
                pokaz_macierz(n, macierz);
            } 
        }
    }
    
    cout<<"************* MACIERZ PO ELIMINACJI GAUSSA *************"<<endl;
    pokaz_macierz(n, macierz);
    
    //Obliczanie wartosci niewiadomych/zmiennych  
    for (int i = n-1; i >= 0; i--)                
    {                      
        wynik[i]=macierz[i][n]; 

        for (int j = i+1; j < n; j++)
        {   
            if (j!= i)
            {       
                wynik[i]=wynik[i]-macierz[i][j]*wynik[j];
            }
        }
        wynik[i] /= macierz[i][i];            
    }

    //wypisanie wartosci niewiadomych
    cout<<endl<<"************** ROZWIAZANIE UKŁADU RÓWNAŃ ***************"<<endl;
    
    for(int i = 0; i < n; i++)
    {
        cout<<"wynik["<<i<<"] = "<<wynik[i]<<endl;
    }
    cout<<endl;

    plik.close();

    return 0;
}