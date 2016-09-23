#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <math.h>

class Triangulo{
private:
    double dBase, dAltura;
public:
    Triangulo(double base, double altura){
        dBase=base;
        dAltura=altura;
    }
    Triangulo(){
        dBase=1.0;
        dAltura=2.5;
    }

    double Perimetro();
    double Area();

};

double Triangulo::Perimetro(){
    double perimetro = sqrt(pow((dBase/2.0), 2.0)+pow(dAltura, 2.0));
    return perimetro;
}
double Triangulo::Area(){
    double area = dBase*dAltura/2.0;
    return area;
}

class PiramideRectangular{
private:
    double LongitudBase;
    double LongitudCostado;
    Triangulo triangulo;
public:
    PiramideRectangular():triangulo(3.0, 4.0){
        LongitudBase=3.0;
        LongitudCostado=4.0;
    }
    PiramideRectangular(double base, double costado) : triangulo(base, costado){
        LongitudBase=base;
        LongitudCostado=costado;
    }

    double Area();

};

double PiramideRectangular::Area(){

double area=(triangulo.Area()*4)+(LongitudBase*LongitudBase);
return area;
}

#endif // HEADER_H_INCLUDED
