#ifndef CLASS_Cuenta
#define CLASS_Cuenta
#include <string>
#include <fstream>

using namespace std;

class Cuenta{
private:
    string cliente;
    double saldoAnterior;
    double saldoNuevo;
public:

    ///CONSTRUCTORES
    Cuenta(string cliente, double saldoAnterior, double saldoNuevo){
        this->cliente=cliente;
        this->saldoAnterior=saldoAnterior;
        this->saldoNuevo=saldoNuevo;
    }

    Cuenta(){
        cliente="SIN NUMERO";
        saldoAnterior=0.0;
        saldoNuevo=0.0;
    }


    ///SETS
    void setCliente(string c){
    cliente=c;
    }
    void setSaldoAnterior(double s){
    saldoAnterior=s;
    }
    void setSaldoNuevo(double s){
    saldoNuevo=s;
    }

    ///GETS
    string getCliente(){
    return cliente;
    }
    double getSaldoAnterior(){
    return saldoAnterior;
    }
    double getSaldoNuevo(){
    return saldoNuevo;
    }

    ///LEER / IMPRIMIR

    void leer(ifstream& input){
        input >> cliente >> saldoAnterior >> saldoNuevo;
    }

    void imprimir(){
    cout << "Cliente: " << cliente << endl;
    cout << "Saldo Anterior: " << saldoAnterior << endl;
    cout << "Saldo Nuevo: " << saldoNuevo << endl;
    }

};

class Cheque{
private:
    int numero;
    double cantidad;
    bool status;
public:
    ///CONSTRUCTORES
    Cheque(int num, double cant, bool stat){
        numero=num;
        cantidad=cant;
        status=stat;
    }

    Cheque(){
    numero=0;
    cantidad=0;
    status = false;
    }

    ///SETS
    void setNumero(int num){
    numero=num;
    }
    void setCantidad(double cant){
    cantidad=cant;
    }
    void setStatus(bool stat){
    status=stat;
    }

    ///GETS
    int getNumero(){
    return numero;
    }
    double getCantidad(){
    return cantidad;
    }
    bool getStatus(){
    return status;
    }

    ///LEER / IMPRIMIR
    void leer(ifstream& input){
    input >> numero >> cantidad >> status;
    }

    void imprimir(){
    cout << "Numero de cheque: " << numero << endl;
    cout << "Cantidad: " << cantidad << endl;
    cout << "Status: ";
     if (status){
        cout << "Cobrado" << endl;
     }
    else
        cout << "No cobrado" << endl;
    }


};

class Deposito{
private:
    double cantidad;
public:

    ///CONSTRUCTORES

    Deposito(double cant){
    cantidad=cant;
    }
    Deposito(){
    cantidad=0.0;
    }

    ///SETS

    void setCantidad(double num){
        cantidad=num;
    }

    ///GETS

    double getCantidad(){
    return cantidad;
    }

    ///LEER / IMPRIMIR

    void leer(ifstream& input){
    input >> cantidad;
    }

    void imprimir(){
    cout << cantidad << endl;
    }

};

#endif // CLASS_Cheque
