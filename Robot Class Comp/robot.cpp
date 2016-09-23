#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Camara{

private:
    string lens;
    string type;
public:
    Camara(string lens, string type){
        this->lens=lens;
        this->type=type;
    }
    string getType(){
        return type;
    }
    string getLens(){
        return lens;
    }
    friend ostream& operator << (ostream& out, const Camara &pCamara) {
      out << pCamara.type << " " << pCamara.lens;
      return out;
   }

};

class Brazo {

private:
    string material;
    string length;
public:
    Brazo(string material, string length){
        this->material=material;
        this->length=length;
    }
    string getMaterial(){
        return material;
    }
    string getLength(){
        return length;
    }
    friend ostream& operator << (ostream& out, const Brazo pBrazo){
        out << pBrazo.length << " " << pBrazo.material;
        return out;
    }

};

class Pierna {

private:
    string material;
    string length;
public:
    Pierna(string material, string length){
        this->material=material;
        this->length=length;
    }
    string getMaterial(){
        return material;
    }
    string getLength(){
        return length;
    }

    friend ostream& operator << (ostream& out, const Pierna pPierna){
        out << pPierna.length << " " << pPierna.material;
        return out;
    }
};

class Robot{

private:
    Pierna pierna;
    Brazo brazo;
    Camara camara;
    string proposito;
    string nombre;
    string color;
public:
    Robot(string pnombre, string pproposito, string pcolor, const Pierna ppierna, const Brazo pbrazo, const Camara pcamara):
        nombre(pnombre), proposito(pproposito), color(pcolor), pierna(ppierna), brazo(pbrazo), camara(pcamara){}

    string getProposito(){
        return proposito;
    }
    string getNombre(){
        return nombre;
    }
    string getColor(){
        return color;
    }

    friend ostream& operator << (ostream& out, const Robot probot){
    out << probot.nombre << ", " << probot.color << ", " << probot.proposito << " " << probot.camara << " " << probot.brazo << " " << probot.pierna;
    return out;
    }
};



int main()
{
    Robot r_1("Roberto Roboto", "Limpieza", "Blanco", Pierna("Ceramica", "104cm"), Brazo("Ceramica", "80cm"), Camara("12Mpx", "Nikkon"));
    Robot r_2("XML-Serie#-12983x", "Destruccion", "Gris", Pierna("Acero", "115cm"), Brazo("Acero/Plomo", "95cm"), Camara("30Mpx", "Canon"));

    cout << r_1 << endl;
    cout << r_2 << endl;
    return 0;
}
