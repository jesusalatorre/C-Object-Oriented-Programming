#ifndef CLASS_Robot
#define CLASS_Robot

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Robot{
private:
    ifstream input;
    char **lab;
    char casilla='I';
    int tam;
    int posx, ultimax, penultimax;
    int posy, ultimay, penultimay;
    int i;
    int k;
    int cambio;
    bool detectarEsquina;
public:
    Robot(string archivo){
        input.open(archivo.c_str());
        input >> tam;
        input >> posy;
        posx=0;
        ultimax=posx;
        ultimay=posy;

        lab = new char*[tam];
        for (i=0;i<tam;i++){
            lab[i]=new char [tam];
        }
        for (i=0; i<tam; i++){
            for (k=0; k<tam; k++){
                input >> lab[i][k];
                if (lab[i][k]=='-'){
                    lab[i][k]=' ';
                }
            }
        }
        input.close();
        mostrarLaberinto();
    }
    void mostrarLaberinto(){
        cout << "-Mostrando Laberinto-" << endl;
        for(i=0; i<tam; i++){
            for (k=0; k<tam; k++){
                if (lab[i][k]=='v'||lab[i][k]=='-'){
                    cout << ' ';
                }
                else{
                cout << lab[i][k];
                }
            }
            cout << endl;
        }
    }
    char Mover(){
        lab[posy][posx]=casilla;
        ///BUSCANDO SALIDA
            ///a la derecha
            if (lab[posy][posx+1]=='S'){
                posx=posx+1;
            }
            ///a la izquierda
            else if(lab[posy][posx-1]== 'S'){
                posx=posx-1;
            }
            ///abajo
            else if(lab[posy+1][posx]=='S'){
                posy=posy+1;
            }
            ///arriba
            else if(lab[posy-1][posx]=='S'){
                posy=posy-1;
            }
        ///BUSCANDO RUTA NO VIAJADA
            ///a la derecha
           else if (posx!=tam-1&&lab[posy][posx+1]==' '){
                posx=posx+1;
            }
            ///a la izquierda
            else if(posx!=0&&lab[posy][posx-1]== ' '){
                posx=posx-1;
            }
            ///arriba
            else if(posy!=0&&lab[posy-1][posx]==' '){
                posy=posy-1;
            }
            ///abajo
            else if(posy!=tam-1&&lab[posy+1][posx]==' '){
                posy=posy+1;
            }
        ///BUSCANDO RUTA VIAJADA
            ///a la derecha
            else if (lab[posy][posx+1]=='v'&&posx!=tam-1){
                posx=posx+1;
            }
            ///abajo
            else if(lab[posy+1][posx]=='v'&&posy!=tam-1){
                posy=posy+1;
            }
            ///a la izquierda
            else if(lab[posy][posx-1]== 'v'&&posx!=0){
                posx=posx-1;
            }
            ///arriba
            else if(lab[posy-1][posx]=='v'&&posy!=0){
                posy=posy-1;
            }
            ///VERIFICANDO PASILLO
            ///En caso de equivocarse de camino dos veces en una interseccion con 3 caminos,
            ///el punto de interseccion (ahora marcado con una '-') tendra que ser alcanzado para determinar la ruta que falta.
            ///El robot ya no enontrara ni ' ' ni 'v' para viajar, asi que tendra que repetir su ultima movida hasta encontrar salida.
            else {
                    posx=posx+ultimax-penultimax;
                    posy=posy+ultimay-penultimay;
                    ///DESHACIENDO INTENTOS DE ATRAVESAR PAREDES
                    if (lab[posy][posx]=='X'){
                        posx=posx+penultimax-ultimax;
                        posy=posy+penultimay-ultimay;
                    }
            }
            ///GUARDANDO CAMINO
                penultimax=ultimax;
                penultimay=ultimay;
                ultimax=posx;
                ultimay=posy;
                casilla=lab[posy][posx];
            ///MARCANDO CAMINO
                if (lab[penultimay][penultimax]==' '){
                    lab[penultimay][penultimax]='v';
            ///VERIFICANDO FINAL DE PASILLO
                ///PASILLO HORIZONTAL (TAPADO ARRIBA Y ABAJO)
                if(lab[penultimay+1][penultimax]=='X'&&lab[penultimay-1][penultimax]=='X'){
                    if(lab[penultimay][penultimax+1]=='X'||lab[penultimay][penultimax-1]=='X'){
                        lab[penultimay][penultimax]='-';
                    }
                }
                    ///PASILLO VERTICAL (TAPADO IZQUIERDA Y DERECHA)
                if(lab[penultimay][penultimax+1]=='X'&&lab[penultimay][penultimax-1]=='X'){
                    if(lab[penultimay+1][penultimax]=='X'||lab[penultimay-1][penultimax]=='X'){
                        lab[penultimay][penultimax]='-';
                    }
                }
            ///VERIFICANDO ESQUINAS EN ESPACIOS ABIERTOS
                ///ABAJO-DERECHA
                else if((lab[penultimay+1][penultimax]=='X'&&lab[penultimay][penultimax+1]=='X')&&lab[penultimay-1][penultimax-1]!='X'){
                    lab[penultimay][penultimax]='-';
                }
                ///ABAJO-IZQUIERDA
                else if((lab[penultimay+1][penultimax]=='X'&&lab[penultimay][penultimax-1]=='X')&&lab[penultimay-1][penultimax+1]!='X'){
                    lab[penultimay][penultimax]='-';
                }
                ///ARRIBA-DERECHA
                else if((lab[penultimay-1][penultimax]=='X'&&lab[penultimay][penultimax+1]=='X')&&lab[penultimay+1][penultimax-1]!='X'){
                    lab[penultimay][penultimax]='-';
                }
                ///ARRIBA-IZQUIERDA
                else if((lab[penultimay-1][penultimax]=='X'&&lab[penultimay][penultimax-1]=='X')&&lab[penultimay+1][penultimax+1]!='X'){
                    lab[penultimay][penultimax]='-';
                }
            }
            else if (lab[penultimay][penultimax]=='v'){
                lab[penultimay][penultimax]='-';
            }
            ///COLOCANDO ROBOT
            lab[posy][posx]='R';
            return casilla;
        }
        void destruir(){
            delete [] *lab;
            delete [] lab;
        }
};
#endif // CLASS_Robot
