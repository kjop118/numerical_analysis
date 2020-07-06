## Opis programu
Program oblicza rozwiązanie równania za pomocą interpolacji Lagrange'a. 
W osobnym pliku (dane.txt) znajdują się niezbędne dane, na których program wykonuje obliczenia. 

## Zawartość pliku dane.txt

| 4     | ilość węzów |
| -2.0    | 3.0    | współrzędne x0 i y0  |
| 1.0     | 1.0    | współrzędne x1 i y1  |
| 2.0     | -3.0   | współrzędne x2 i y2  |
| 4.0     | 8.0    | współrzędne x3 i y3  |


## Działanie programu

Program otwiera plik, z którego pobiera dane
1. Pobiera ilość węzłów
2. W pętli pobiera wartości w danym węźle

Następnie tworzone są trzy tablice dynamiczne w zależności od ilości wierzchołków:
*  do pierwszej tablicy będzie zapisywał wartości w X
*  do drugiej tablicy będzie zapisywał wartości w Y
*  trzecia tablica służy do obliczania wyniku

Zapisane wartości wyświetlane są na ekranie.

Następnie program prosi użytkownika o podanie punktu, w którym będą wykonywane obliczenia.

Wykonanie obliczeń odbywa się w zagnieżdżonej pętli
1. W pierwszej pętli oblicza wartość licznika
2. W drugiej pętli oblicza wartość mianownika
3. Z głównej pętli otrzymuje tyle wyników ile wynosiła liczba wierzchołków

W ostatniej pętli sumowane są wyniki otrzymane z pętli powyżej


Otrzymany wynik jest szukaną wartością wielomianu interpolacji

