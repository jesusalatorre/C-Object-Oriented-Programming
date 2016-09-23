#ifndef CLASE_CPU
#define CLASE_CPU

#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

class CPU{
private:
    int memoria[30];
    ifstream input;
    int IR; int AC; int PC;
    bool HALT;
public:

    ///CONSTRUCTOR

    CPU(string archivo){
    IR=0;
    AC=0;
    PC=0;
    HALT=false;
    int i=0;
    archivo=archivo+".obj";
    input.open(archivo.c_str());

    while (!input.eof()){
        input >> memoria[i];
       i++;
    }
    input.close();

    for (int k=20; k<30; k++){
        memoria[k]=0;
    };

    }


    ///GETS/PRINTS

    int getMemoria(int pos){
    return memoria[pos];
    }
    void printMemoriaCompleta(){
        cout << "Direccion   " << "   Contenido" << endl;
    for (int i=20; i<30; i++){
        cout << i << "  :  " << memoria[i] << endl;
    };
    }

    void printRegistros(){
        cout << "PC: " << PC << " " << " IR: ";
        if (IR<100){
            cout << "0";
        };
         cout << IR << " " << " AC: " << AC << endl;
    }

        ///FUNCIONES DE ENSAMBLADOR

    void funcion_0(int pos){ ///IN
        cout << "Ingresar numero: " << endl;
        cin >> memoria[pos];
    };
    void funcion_1(int pos){ ///OUT
        cout << memoria[pos] << endl;
    };
    void funcion_2(int pos){ ///LDA
        AC=memoria[pos];
    };
    void funcion_3(int pos){ ///STA
        memoria[pos]=AC;
    };
    void funcion_4(int pos){ ///ADD
        AC=AC+memoria[pos];
    };
    void funcion_5(int pos){ ///SUB
        AC=AC-memoria[pos];
    };
    void funcion_6(int pos){ ///JUMP
        PC=pos;
    };
    void funcion_7(int pos){ ///BRAN
    if(AC<0){
        PC=pos;
    };
    };
    void funcion_8(int pos){ ///BRAZ
    if (AC==0){
        PC=pos;
    };
    };

    ///PROCESO DE EJECUCION

    void Ejecutar(){

    while (PC<=30){

        ///INTERPRETACION

        IR = memoria[PC];
        int pos = IR%100;
        int comando = (IR-pos)/100;

        ///DESPLEGAR REGISTROS

        printRegistros();
        printMemoriaCompleta();

        ///EJECUCION DE COMANDOS

        if(comando==0){
            funcion_0(pos);
        };
        if(comando==1){
            funcion_1(pos);
        }
        if(comando==2){
            funcion_2(pos);
        }
        if(comando==3){
            funcion_3(pos);
        }
        if(comando==4){
            funcion_4(pos);
        }
        if (comando==5){
            funcion_5(pos);
        }

        ///CANCELAR AUMENTO DE PC EN COMANDOS QUE LO MODIFICAN(6, 7, y 8)

        if (comando==6){
            funcion_6(pos);
            PC--;
        }
        if(comando==7){
            funcion_7(pos);
            PC--;
        }
        if(comando==8){
            funcion_8(pos);
            PC--;
        }
        if (comando==9){
            input.close();
            break;
        }
        PC++;
    }
    }


};

#endif // CLASE_CPU
