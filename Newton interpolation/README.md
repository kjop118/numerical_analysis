## Opis programu
Program oblicza rozwiązanie równania za pomocą interpolacji Newton'a w dowolnym punkcie. 
Dane niezbędne do wykonania przez program obliczeń znajdują się w pliku **newton.txt**

## Zawartość pliku **newton.txt**

| 5    | ilość węzłów |                     |
|------|--------------|---------------------|
| 0 | 0          | argument i wartość w pierwszym węźle |
| 2  | 8         | argument i wartość w drugim węźle |
| 3  | 27         | argument i wartość w trzecim węźle|
| 5 | 125        | argument i wartość w czwartym węźle |
| 6 | 216        | argument i wartość w piątym węźle|


## Działanie programu

Program otwiera plik, z którego pobiera dane. 

1. Program pobiera potrzebne dane z pliku **newton.txt**
2. Tworzy jednowymiarową tablice z argumentami (tab_x) oraz dwuwymiarową tablicę z wartościami (tab_y)
3. W zagnieżdżonej pętli oblicza ilorazy różnicowe każdego rzędu:
    - oblicza wartość licznik w danym rzędzie dla danego argumentu
    - liczy mianownik i dzieli licznik przez mianownik
4. Wyświetla współczynniki wielomianu interpolacyjnego
5. Prosi użytkownika o podanie punktu, w którym będzie obliczał wartość wielomianu
6. W pętli liczy wartość wielomianu w punkcie
    - liczy iloczyny 
    - następnie każdy obliczony iloczyn sumuje według wzoru Newtona
7. Wypisuje wartość wielomianu w punkcie
