#ifndef AHORCADO
#define AHORCADO

#include <string>
#include <iostream>
using namespace std;

///Asume que la palabra tiene 7 caracteres
///La cantidad de intentos no importa, mientras no se cometan 7 fallos
class Ahorcado{
private:
   string palabra;    ///La palabra a adivinar
   string intentadas; ///Cuantas letras se han intentado
   string xs;         ///Muestra letras X en las letras aun no adivinadas
   int encontradas;   ///Total de letras encontradas hasta el momento
   int fallos;        ///Total de fallos hasta el momento
   int i;
public:
   Ahorcado(string palabra);
   bool ganoJuego(); ///Ya se adivinaron todas las letras?
   bool continuarJuego();
   void validaIntento(char letra);
   void muestraEscenario();
};

Ahorcado::Ahorcado(string palabra){
   this->palabra = palabra;
   xs = "";

   for(i=0; i<palabra.length(); i++){
        xs+= "X";
   }
   encontradas = 0;
   intentadas = "";
   fallos = 0;
}

void Ahorcado::muestraEscenario(){
   string escenario[] = {"","  O", "  O\n /", "  O\n /|", "  O\n /|\\", "  O\n /|\\ \n  |", "  O\n /|\\ \n  | \n /", "  O\n /|\\ \n  | \n / \\"};
   cout << escenario[fallos]<< endl;
   cout << "Encontradas: " << xs << endl;
   cout << "Intentadas: " << intentadas << endl;
}

void Ahorcado::validaIntento(char letra){
   int pos;
   int encontro = 0; ///Cuantas letras ha encontrado en la palabra
   intentadas += letra;
   while((pos = palabra.find(letra)) != -1){ ///Busca letra en la palabra desde el principio de la palabra
      xs[pos] = letra;      ///Substituyela en lugar de la X por la letra encontrada
      palabra[pos] = '-';   ///Elimina la letra adivinada por el jugador
      encontro++;
      encontradas++;        ///Total de letras encontradas en la palabra
   }
   if (encontro==0)
      fallos++; ///No encontro la letra, incrementar el numero de fallos
}

bool Ahorcado::continuarJuego(){ ///El juego termina cuando se adivine la palabra completa o se cometan 7 errores
   if( (fallos < 7) && (encontradas < palabra.length()) )
      return true;
   return false;
}

bool Ahorcado::ganoJuego(){ ///El jugador gano el juego cuando se hayan adivinado las 7 letras de la palabra
   if(encontradas == palabra.length())
     return true;
     else
   return false;
}

#endif //AHORCADO
