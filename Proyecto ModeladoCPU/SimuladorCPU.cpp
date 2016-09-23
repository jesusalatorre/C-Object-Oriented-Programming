///JESUS ALATORRE A00819508
///INTERPRETADOR DE CODIGO, EJECUTA
///MODELANDO LOS PROCESOS DE UN CPU

#include <iostream>
#include "Ensamblador.h"
#include "CPU.h"
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string archivo;
    Ensamblador ensamblador;


    cout << "Por favor introduzca el nombre del archivo: " << endl;
    cin >> archivo;

   ensamblador.Interpretar(archivo);

    CPU cpu(archivo);

    cpu.Ejecutar();



    return 0;
}
