
//Jesus Alatorre A00819508

#ifndef CLASE_Estudiante
#define CLASE_Estudiante

#include <iostream>

using namespace std;

class Estudiante {
private:
    int iId;
    double dColegiatura;
    char cTipoBeca;

public:
    void setiId(int iId){
    this->iId=iId;
    }
    int getiId(){
    return iId;
    }
    void setdColegiatura(double dColegiatura){
    this->dColegiatura=dColegiatura;
    }
    double getdColegiatura(){
    return dColegiatura;
    }
    void setcTipoBeca(char cTipoBeca){
    this->cTipoBeca=cTipoBeca;
    }
    char getcTipoBeca(){
    return cTipoBeca;
    }

    void calculaDescuento(int& iClave, char& cTipoBeca, double& dColegiatura, ostream& disp);

    void printFicha(int& iId, double& dColegiatura, char& cTipoBeca);

    void nuevadColeg(double& dColeg);

Estudiante(int identificador, double pago, char beca){
    iId=identificador;
    dColegiatura=pago;
    cTipoBeca=beca;
}

};

void Estudiante::calculaDescuento(int& iClave, char& cTipoBeca, double& dColegiatura, ostream& disp){
    if (cTipoBeca=='a'||cTipoBeca=='A')
    {
        if (iClave==1){
            disp << "Descuento: " << .05*dColegiatura << endl;
        }
        if (iClave==2){
            disp << "Descuento: " << .08*dColegiatura << endl;
        }
    }
    if (cTipoBeca=='b'||cTipoBeca=='B'){
        disp << "Descuento: " << .1*dColegiatura << endl;
    }
}

void Estudiante::printFicha(int& iId, double& dColegiatura, char& cTipoBeca){
    cout << "Identificacion: " << iId << endl;
    cout << "Colegiatura: " << dColegiatura << endl;
    cout << "Tipo de Estudiante: " << cTipoBeca << endl;
}

void Estudiante::nuevadColeg(double& dColeg)
{
    dColegiatura=dColeg;
}

#endif // HEADER_H_INCLUDED
