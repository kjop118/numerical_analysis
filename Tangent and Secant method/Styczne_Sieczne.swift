import Foundation

//alternatywna funkcja
/*
func f(_ x:Double) -> Double
{
  return cos(x)
}


func fp(_ x:Double) -> Double
{
  return sin(x)*(-1)
}
*/

// funkcja f(x) = 6x^4+6x^3−11x^2+x−2
func f(_ x:Double) -> Double
{
    let x4:Double = pow(x,4)
    let x3:Double = pow(x,3)
    let x2:Double = pow(x,2)
    return 6*x4 + 6*x3 - 11*x2 + x - 2
}

// pochodna funkcji f'(x) = 24*x^3 + 18*x^2 - 22*x + 1
func fp(_ x:Double) -> Double
{
    let x3:Double = pow(x,3)
    let x2:Double = pow(x,2)
    return 24*x3 + 18*x2 - 22*x + 1
}



//Metoda Newtona (stycznych)
var x1:Double = 0
var f0:Double = 0
var f1:Double = 0
var licznik:Int = 0

print("\nDANE METODA STYCZNYCH\n")
print("Podaj punkt startowy x0:")
var x0 = Double(readLine()!)

print("Podaj dokladnosc epsilon:")
var epsilon = Double(readLine()!)


while (true)
{
    licznik += 1
    
    f0 = f(x0!)
    f1 = fp(x0!)
    x1 = x0!
    x0 = x0! - (f0 / f1) //przyblienie rozwiazania czyli punkt przeciecia stycznej z OX
    f0 = f(x0!)

    if(fabs(f0) < epsilon!)
    {
        break
    }
}

//Metoda siecznych
var y0:Double = 0
var g0:Double = 0
var g1:Double = 0
var g2:Double = 0
var counter:Int = 0

print("\nDANE METODA SIECZNYCH\n")
print("Podaj punkty startowe")
print("y1:")
var y1 = Double(readLine()!)
print("y2:")
var y2 = Double(readLine()!)
print("Podaj dokladnosc epsylon:")
var epsylon = Double(readLine()!)

while(true)
{
    counter += 1
    
    g1 = f(y1!)
    g2 = f(y2!)
    y0 = y2! - (g2 * (y2! - y1!) / (g2 - g1)) //przyblizenie rozwiazania
    g0 = f(y0)

    if(fabs(g0) < epsylon!)
    {
        break
    }
    
    y2 = y1
    y1 = y0

}

print("\n------------------------------------------------- \n")
print("\nWYNIKI\n")
print("Rozwiazywane rownanie: f(x) = 6x^4+6x^3−11x^2+x−2 \n")
print("\nMETODA STYCZNYCH\n")
print("Znalezione rozwiązanie x\(licznik) = \(x0!)")
print("Wartosc funkcji w rozwiazaniu wynosi \(f0)")
print("Wykonano \(licznik) krokow\n")
print("\nMETODA SIECZNYCH\n")
print("Znalezione rozwiązanie y\(counter) = \(y0)")
print("Wartosc funkcji w rozwiazaniu wynosi \(g0)")
print("Wykonano \(counter) krokow\n")
