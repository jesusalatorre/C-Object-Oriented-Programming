#include <iostream>
#include "header.h"
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream input;
    int i=0, j=0, k=0;
    double acumCheque=0, acumDepositos=0;
    double cantidad, saldo;
    bool flag;
    Cheque *cheque[100];
    Cheque *nocobrado[100];
    Deposito *deposito[100];

    cout << "Iniciando proceso..." << endl;

    Cuenta Jesus;

    input.open("chequera.txt");
    Jesus.leer(input);
    input.close();

    input.open("cheques.txt");
    while (input.eof()==false){
    cheque[i] = new Cheque;
    cheque[i]->leer(input);
    flag=cheque[i]->getStatus();
    if (flag==1){
        acumCheque+=cheque[i]->getCantidad();
        i++;
    }
    else {
        nocobrado[k]=cheque[i];
        k++;

    }

    }


    input.close();

    input.open("depositos.txt");

    while (input.eof()==false){
        input >> cantidad;
        deposito[j] = new Deposito(cantidad);
        acumDepositos+=deposito[j]->getCantidad();

        j++;

    }
    input.close();

    saldo=acumDepositos-acumCheque;

    Jesus.setSaldoNuevo(saldo);

    cout << "Total de cheques cobrados: " << i << endl;
    cout << "Total de depositos realizados: " << j << endl;
    cout << "Nuevo saldo de la cuenta: " << Jesus.getSaldoNuevo() << endl << endl;

    cout << "Cheques cobrados: " << endl;
    for (int l=0; l<i; l++){
        cheque[l]->imprimir();
    }
    cout << endl << "Cheques no cobrados: " << endl;
    for (int m=0; m<k; m++){
        nocobrado[m]->imprimir();
    }


    return 0;
}
