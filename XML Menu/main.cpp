/*
Jesus Alatorre A00819508
Scans through an XML file full of menu options, prices, and places of origin. Brings back only the Mexican options to the console.
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string line, tag, value;
    string descripcion, tipo, precio;
    int tagSize, tagStart, valueSize;
    ifstream input;

    cout << "Buscando Opciones Mexicanas..." << endl;

    input.open("menu.xml");

    getline(input, line);
    getline(input, line);
    getline(input, line);

    do {
        getline(input, line);
        tagStart = line.find('<');
        line.erase(0, tagStart);

        while (line!= "</platillo>"){
            tagSize=line.find('>');
            tag=line.substr(1, tagSize-1);
            line.erase(0,tagSize+1);
            valueSize=line.find("</");
            value = line.substr(0,valueSize);

            if (tag=="descripcion"){
                descripcion=value;
            }
            if (tag=="tipo"){
                tipo=value;
            }
            if (tag=="precio"){
                precio=value;
            }

            getline(input, line);
            tagStart=line.find('<');
            line.erase(0, tagStart);
        }
        if (tipo=="Mexicana"){
            cout << "Descripcion: " << descripcion <<endl;
            cout << "Tipo: " << tipo << endl;
            cout << "Precio " << precio << endl;
        }

        getline(input, line);
        tagStart = line.find('<');
        line.erase(0, tagStart);
    } while (line.compare("</menu>") != 0);
    input.close();


    return 0;
}
