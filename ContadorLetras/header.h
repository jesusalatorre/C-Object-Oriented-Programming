#ifndef CLASE_ContadorLetras
#define CLASE_ContadorLetras

#include <iostream>
#include <string>

using namespace std;

class ContadorLetras{

private
    int conteoLetras[32];

public
    void preparaString(string& inStr);
    int cuentaPalabras(const string);
    void cuentaCaracteres(const string inStr);
    void imprimeCuenta();
};

void ContadorLetras::preparaString(string& inStr){
    int i;
    for (i=0;i<=inStr.length();i++){
        if ((inStr[i]>=65&&inStr[i]<=90)||(inStr[i]>=97&&inStr[i]<=122)||(inStr[i]==32{
            if(inStr[i]>=65&&inStr[i]<=90){
                inStr[i]=inStr[i]-('A'-'a')
            }
            if (inStr[i]==32){
                    for (int j=1; inStr[i+j]==32;){
                        inStr.erase(i+j, 1);
                        }

                    }
                }
                else
                {
                    inStr.erase(i, 1);
                }
    }
}

#endif // HEADER_H_INCLUDED
