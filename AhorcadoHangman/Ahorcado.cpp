#include <string>
#include <iostream>
#include "Ahorcado.h"
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

///Todas las palabras tienen 7 caracteres

int main(){
   Ahorcado *ahorcado;
   string seguir, palabra;
   char letra;
   int pal = 0;  ///Indice de la palabra a adivinar
   int i=0, k=0;
   srand(time(0));
   int num;
   bool flag=false;

   ifstream Input;

   Input.open("palabras.txt");

   while (Input.eof()==false){
        getline(Input, palabra);
        if(palabra.length()>15){
            i--;
        }
        i++;
   }

   Input.close();

   string palabras[i];
   int order[i];

 while (k<i){
    num = rand() % i;
    for (int l = 0; l<k; l++){
        if (order[l]==num){
            flag=true;
            break;
        }
    }
    if (flag==false){
        order[k]=num;
        k++;
    }
    flag=false;
 }


   Input.open("palabras.txt");

  for (int j =0; j<i;){
    getline(Input, palabra);
    if (palabra.length()<=15){
    palabras[j]=palabra;
    j++;
    }
  }

   do {

      palabra = palabras[order[pal]];  ///Toma la siguiente palabra del arreglo
      pal++;
      ahorcado = new Ahorcado(palabra);
      cout << "Adivina la palabra!" << endl;
      ahorcado->muestraEscenario();
      while (ahorcado->continuarJuego()) {
         cout << "Dame una letra: ";
         cin >> letra;
         ahorcado->validaIntento(letra);
         ahorcado->muestraEscenario();
      }
      if(ahorcado->ganoJuego())
         cout << "Felicidades!!! Adivinaste la palabra!!!"<< endl;
      else
         cout << "Lo siento. La palabara era: " << palabra << endl;
          if (pal==i){
                cout << "Bien jugado!" << endl;
        break;
      }
      cout << "\nDeseas jugar de nuevo? s/n"<< endl;
      cin >> seguir;
      delete ahorcado; ///Destruye la instancia de ahorcado

   } while(seguir == "s");

   return 0;
}

