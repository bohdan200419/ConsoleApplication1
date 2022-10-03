#include "ZavdClass.h"
#include "stdafx.h"
using namespace std;



double ZavdClass::Fn_b(double x, double y, double z)
{
    double b1 = 1+pow(abs(y-x),2)/pow(abs(z-1),1.34);
    double b2 = pow((z-x),2)/pow(sin(z),2);
    double b3 = pow(abs(y-z),3)/pow(cos(y),2);
    return b1 + b2 + b3;
}
double ZavdClass::Fn_a(double x, double y, double z, double Fn_b)
{
    double a1 = pow((x+y),2);
    double a2 = x+pow(z,3)/pow((pow(Fn_b,2)+y),2);
    double a3 = 1+exp(-(x-y))+pow(abs(z),0.34);
    return a1+(a2/a3);
}

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    double x = 0.48 * 3;
    double y = 0.47 * 3;
    double z = -1.32 * 3;
    cout << endl;
    ZavdClass n;
    double j = 0.2;
    cout << "--------------------Завдання №1--------------------" << endl;
    cout << "Результат виразу B:" << n.Fn_b(x,y,z) << endl;
    cout << "Результат виразу А:" << n.Fn_a(x, y, z, n.Fn_b(x, y, z)) << endl;
    cout << "---------------------Завдання №2---------------------" << endl;
    for (double i = -1; i <= 1; i += j)
    {
        ZavdClass a;

        cout << "Вираз A:" << a.Fn_a( i, y, z, a.Fn_b( i, y, z)) << "\t" << "Вираз B:" << a.Fn_b( i, y, z) << "\t" << endl;
    }
} 
