/*
Jesus Alatorre A00819508
Takes in numbers from an input file and places commas in the appropriate spots if they are more than 3 digits long.
*/

#include <iostream>
#include <string>
#include <fstream>



using namespace std;

int main()
{
    ifstream input;
    ofstream output;
    string numero; string salida = ""; string tres = "";
    int largo;
    int i;

    input.open("numeros.txt");
    output.open("numeros2.txt");

    while (!input.eof()){

        input >> numero;

        largo=numero.length();

        while(largo>3){

            tres=numero.substr(largo-3);

            salida=','+tres+salida;

            numero.erase(largo-3);

            largo-=3;

        }

        salida=numero+salida;

        output << salida << endl;

        salida = "";



    }


    input.close();

    output.close();

    return 0;
}
