#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;
#define Precision 6;
#define Intervalue 10;
double a, b, tolerance, xr;
//a-b => intervalo, tolerancia=> criterio para finalizar las iteraciones, xr=> punto medio
void tab(double a, double b);
void Graphicboot();
void boot();
void PrintValues(double a, double b, double xr, double f_a, double f_b, double f_xr);
void validate(double a, double b);
double F(double x);
int main()
{
    boot();
    cin.get();
    cin.get();
    return 0;
}


void boot()
{
    cout << setprecision(6);
    cout << "\n Calculo de las raices de una funcion aplicando el metodo de la  biseccion\n";
    cout << "\n Ingrese el intervalo inicial " << endl;
    cout << "\n a= ";
    cin >> a;
    cout << "\n b= ";
    cin >> b;
    tab(a, b);
    cout << "\n Escoja el intervalo adecuado " << endl;
    cout << "\n a= ";
    cin >> a;
    cout << "\n b= ";
    cin >> b;
    validate(a, b);
}

void tab(double a, double b)
{
    int points = Intervalue + 1;
    double ancho = (b - a) / Intervalue;
    cout << "\n\tx \tf(x)" << endl;
    for (int i = 0; i < points; i++)
    {
        cout << "\t" << a << "\t" << F(a) << endl;
        a += ancho;
    }
}
//funcion exponencial
double F(double x)
{
    return exp(-1 * x) - cos(3 * x) - 0.5;
}

void validate(double a, double b)
{
    if (F(a) * F(b) > 0)
    {
        cout << "No se puede aplicar el metodo de biseccion" << endl;
        cout << " porque f(" << a << ") y f(" << b << ")  tienen el mismo signo " << endl;
    }
    else
    {
        cout << "\nIngrese la tolerancia = ";
        cin >> tolerance;
        cout << "\n\n a\t b\t x\t\t f(a)\t\t f(b)\t\t f(x)\n\n";
        do
        {
            xr = (a + b) / 2.0;
            PrintValues(a, b, xr, F(a), F(b), F(xr));
            if (abs(F(xr)) <= tolerance)
            {
                cout << "Para la tolerancia de " << tolerance << " la raiz de f es  " << xr << endl;
                break;
            }
            else
            {
                if (F(xr) * F(a) > 0)
                {
                    a = xr;
                }
                else if (F(xr) * F(b) > 0)
                {
                    b = xr;
                }
            }
        } while (1);
    }
}

void PrintValues(double a, double b, double xr, double f_a, double f_b, double f_xr)
{
    cout << a << "\t" << b << "\t" << xr << "\t"
         << "\t" << f_a << "\t" << f_b << "\t" << f_xr << endl;
}


void Graphicboot()
{
    
}