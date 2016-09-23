///Jesus Alatorre A00819508
///Proyecto 1
///GENERA DOCUMENTACION DEL ARCHIVO QUE SEA INGRESADO
///SIEMPRE Y CUANDO CUMPLA CON EL FORMATO PRESENTADO EN
///EL ARCHIVO "factorial".

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string filename;
    ifstream input;
    ofstream output;
    string line;
    string tag;
    string info;
    int len, pos1, pos2;

    cout << "Escriba el nombre del archivo (sin extension) que sera documentado: " << endl;
    cin >> filename;

    len=filename.length();

    filename=filename+".cpp";

    input.open(filename.c_str());

    filename=filename.erase(len)+".html";

    output.open(filename.c_str());

    filename=filename.erase(len);

    output << "<!DOCTYPE html>" << endl << "<html>" << endl << "<head>" << endl << "<title>" << endl;
    output << "Documentacion del archivo " << filename << ".cpp" << endl << "</title>" << endl << "</head>" << endl << "<body>" << endl;


    do {
        getline(input, line);

        if(line.compare("/**")==1){



            do{
                pos1=line.find('@');

                if (pos1==0){
                line=line.substr(pos1);
                pos2=line.find(' ');
                tag=line.substr(0,pos2);
                info=line.substr(pos2);

                if (tag=="@progName"){
                    output << "<h2>" << endl << "Programa: " << info << "<br>" << endl << "</h2>" << endl;
                }
                if (tag=="@author"){
                    output << "<strong>" << "Autor: " << "</strong>" << info << "<br>" << endl;
                }
                if (tag=="@date"){
                    output << "<strong>" << "Fecha de elaboracion: " << "</strong>" << info << "<br>" << endl;
                }
                if (tag=="@funcName"){
                    output << "<h3>" << endl << "<hr>" << "<br>" << info << "<br>" << endl << "</h3>" << endl;
                }
                if (tag=="@desc"){
                    output << "<strong>" << "Descripcion: " << "</strong>" << info << "<br>" << endl;
                }
                if (tag=="@param"){
                    output << "<strong>" << "Parametro: " << "</strong>" << info << "<br>" << endl;
                }
                if (tag=="@return"){
                    output << "<strong>" << "Valor de retorno: " << "</strong>" << info << "<br>" << endl;
                }

                tag="";
                info="";
                };
            }
            while(line.compare("*/")!=1);
        }
    }
    while (!input.eof());

    output << "</body>" << endl << "</html>" << endl;

    input.close();

    output.close();


    return 0;
}
