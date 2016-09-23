///Jesus Alatorre A00819508
///Resuelve laberintos
#include <iostream>
#include "Robot.h"
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    char casilla;
    string enter;
    Robot robot("laberinto.txt");
    cout << endl << endl << "Presione ENTER para iniciar..." << endl;
    getline(cin, enter);
    do{
        system("cls");
        casilla=robot.Mover();
        robot.mostrarLaberinto();
        cout << endl << endl << "Presione ENTER para continuar..." << endl;
        getline(cin, enter);
    }
    while(casilla!='S');
    cout << "El robot encontro la salida!" << endl;
    robot.destruir();
    return 0;
}
