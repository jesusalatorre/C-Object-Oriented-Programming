#include <iostream>
#include <math.h>

using namespace std;

double f(double Z){
    double value=pow(2.71828182845904523536,(-1*pow(Z,2)/2))/sqrt(2*3.14159265359);
    return value;
}
int main()
{
    double integral=0;
   double PromedioVida = 8;
   double TiempoViaje = 9;
   double DesvStd = 1;
   int intervalos = 100000;
   double Z=(TiempoViaje-PromedioVida)/DesvStd;
   double incremento = Z/intervalos;
    integral=f(0);
   for(int i=1;i<intervalos-1;i++){
    integral+=2*f(i*incremento);
   }
    integral+=f(Z);
    integral=integral*incremento/2;
    cout << integral+.5;
    return 0;
}
