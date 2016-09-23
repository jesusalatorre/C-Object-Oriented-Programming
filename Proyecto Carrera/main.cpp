///JESUS ALATORRE A00819508
///SIMULA CARRERA

#include <iostream>
#include "header.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

int generator(){
    int roll=rand() % 10;
    return roll;
}

int main()
{
    bool empate;
    srand(time(0));
    Tortuga tortuga(0);
    Liebre liebre(0);
    Carrera carrera;
    cout << " Tortuga: T, Liebre: L, Ambos: A " << endl << endl;
    cout << "PUM!!!" << endl << "Y ARRANCAN!!!" << endl << endl;

        cout << carrera.getPista() << endl;

    while(!carrera.getFlag()){

        liebre.avanzar(generator());

        tortuga.avanzar(generator());

        carrera.sigueCarrera(liebre.getPosicion(), tortuga.getPosicion());


        cout << endl;
        cout << carrera.getPista()<< endl;
                if(tortuga.getPosicion()>=70&&liebre.getPosicion()>=70){
            empate=true;
        }

        if (tortuga.getPosicion()==liebre.getPosicion()&&empate==false){

            cout << "OUCH!!!" << endl;

        }
    }


    if(!empate){
            if (liebre.getPosicion()>tortuga.getPosicion()){
                cout << "La liebre gana. Que mal." << endl;
            }
            else{
                cout << "LA TORTUGA GANA!!! YAY!!!" << endl;
            }
            }
    else{
        cout << "Es un empate." << endl;
    }



    return 0;
}
