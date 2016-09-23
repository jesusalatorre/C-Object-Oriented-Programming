#ifndef CLASE_Ensamblador
#define CLASE_Ensamblador


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Ensamblador{
private:
    int pos;
    string code, line, mem;
    ifstream input;
    ofstream output;
public:
    Ensamblador (){

    }
    void Interpretar(string file){
    file=file+".asm";
    input.open(file.c_str());
    output.open("archivo.obj");

    while (!input.eof()){
        getline(input, line);
        if (line=="HALT"){
            output << 999;
        }
            else{
        pos=line.find(" ");
        code=line.substr(0,pos);
        mem=line.substr(pos+1);

        if (code=="IN"){
            output << 0 << mem;
        }
        if (code=="OUT"){
            output << 1 << mem;
        }
        if (code=="LDA"){
            output << 2 << mem;
        }
        if (code=="STA"){
            output << 3 << mem;
        }
        if (code=="ADD"){
            output << 4 << mem;
        }
        if (code=="SUB"){
            output << 5 << mem;
        }
        if (code=="JUMP"){
            output << 6 << mem;
        }
        if (code=="BRAN"){
            output << 7 << mem;
        }
        if (code=="BRAZ"){
            output << 8 << mem;
        }
        }
        output << endl;
    }
    output.close();
    input.close();
    }

};

#endif // CLASE_Ensamblador
