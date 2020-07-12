import Foundation

//f(x) = cos(4x^4+x)
func tryg(_ x:Double) -> Double
{
    let x4:Double = pow(x, 4)
    let wynik:Double = cos(4*x4+x)
    return wynik
}

//f(x) = 2x^7 + 4x^3 + 2x + 1
func wielo(_ x:Double) -> Double
{
    let x7:Double = pow(x, 7)
    let x3:Double = pow(x, 3)
    let wynik:Double = 2*x7 + 4*x3 + 2*x + 1
    return wynik
}

//f(x) = ln(x^2 + 2x)
func logarytm(_ x:Double) -> Double
{
    let x2:Double = pow(x, 2)
    let wynik:Double = log(x2 + 2*x)
    return wynik
}


var srodek:Double = 0.0
var srodek1:Double = 0.0
var licznik:Int = 0

print("       METODA BISEKCJI")

print("\nPodaj początek przedziału (a):")
var a = Double(readLine()!)

print("\nPodaj koniec przedziału (b):")
var b = Double(readLine()!)

print("\nPodaj dokładność obliczen (np. 0.01):")
var dokladnosc = Double(readLine()!)


var a1:Double = wielo(a!)
var b1:Double = wielo(b!)

if (a1*b1)<0
{
    while(true)
    {
        srodek = (a! + b!) / 2
        srodek1 = wielo(srodek)

        if(fabs(srodek1) < dokladnosc!)
        {
           break
        }
        
        licznik += 1
        
        if (a1 * srodek1) < 0
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
    print("Brak miejsc zerowych w przedziale. Podaj nowy przedział")
}

print("\nIlość zrealizowanych krokow obliczeń: \(licznik)")
print("\n\n                 WYNIK")
print("Punkt rozwiązania rownania \(srodek)")
print("Wartosc funkcji w punkcjie \(srodek) wynosi \(wielo(srodek))")
