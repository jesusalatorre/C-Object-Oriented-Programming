///JESUS ALATORRE A00819508

#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <string.h>

class Liebre{
private:
    int posicion;
    int roll;
public:
    Liebre(int pos){
        posicion=pos;
    }

    void avanzar(int roll){
        if (roll==0||roll==1){ ///dormir
            posicion=posicion;
        }
        if (roll==3||roll==2){ ///gran salto
                posicion=posicion+9;
        }
        if (roll==4){ ///gran resbalon
            posicion=posicion-12;

        }
        if (roll==5||roll==6||roll==7){///pequeno salto
            posicion=posicion+1;
        }
        if (roll==8||roll==9){///pequeno resbalon
            posicion=posicion-1;
        }

        if (posicion<0){
            posicion=0;
        }
    }
    int getPosicion(){
        return posicion;
    }
};

class Tortuga{
private:
    int posicion;
    int roll;
public:
    Tortuga(int pos){
        posicion=pos;
    }
    void avanzar(int roll){
        if (roll<=4){///avanza 3
            posicion=posicion+3;
        }
        if (roll==5||roll==6){///resbalon
            posicion=posicion-6;
        }
        if (roll==7||roll==8||roll==9){///avanza 1
            posicion=posicion+1;
        }
        if (posicion<0){
            posicion=0;
        }
    }
    int getPosicion(){
        return posicion;
    }
};

class Carrera{
private:
    bool flag;
    char pista[70];
    int i;
public:
    Carrera(){
        for (i=0; i<70; i++){
            pista[i]='-';
        }
        flag=false;
    }
    char* getPista(){
        return pista;
        }
    void sigueCarrera(int posliebre, int postortuga){
        for (i=0; i<70; i++){///wipe
            if (pista[i]=='L'||pista[i]=='T'||pista[i]=='A'){
                pista[i]='-';
            }
        }

        if(posliebre==postortuga){
            pista[posliebre]='A';
        }

       else if (posliebre>=70&&postortuga<70){
            flag=true;
            pista[postortuga]='T';

        }
        else if(postortuga>=70&&posliebre<70){
        flag=true;
        pista[posliebre]='L';

    }
    else if(posliebre<70&&postortuga<70){
        pista[posliebre]='L';
        pista[postortuga]='T';
    }
    }
    bool getFlag(){
        return flag;
    }

};

#endif // HEADER_H_INCLUDED
