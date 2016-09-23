
//Jesus Alatorre A00819508

#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    double dColegiatura;
    int iId, iClave;
    char cTipo;

    cout << "Teclea el ID del estudiante" << endl;
    cin >> iId;

    cout << "Teclee su colegiatura" << endl;
    cin >> dColegiatura;

    cout <<"Teclea el tipo de estudiante" << endl;
    cin >> cTipo;

    Estudiante Juan(iId, dColegiatura, cTipo);

    cout << "Tecla la clave para los impuestos " << endl;
    cin >> iClave;

    Juan.calculaDescuento(iClave,cTipo,dColegiatura,cout);
    Juan.printFicha(iId,dColegiatura,cTipo);

    cout << "Teclea la nueva colegiatura de estudiante: ";
    cin >> dColegiatura;

    Juan.nuevadColeg(dColegiatura);

    return 0;
}
