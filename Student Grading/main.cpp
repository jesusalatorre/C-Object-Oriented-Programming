#include <iostream>
#include <fstream>
#include <string>

using namespace std;

///CREATES OUTPUT FILE THAT CONTAINS STUDENT AVERAGES BASED ON HOW MANY HOMEWORKS THEY DID AND WHAT THEY GOT ON THEM

int main()
{
    ofstream outfile;
    int alumnos, i, k, completadas, calificacion;
    string matricula;
    float promedio, sum;

    cout << "Ingrese numero de alumnos que seran guardados/procesados: " << endl;
    cin >> alumnos;

    outfile.open("CALIFICACIONES.txt");

    for (i=0;i<alumnos;i++){
        cout << "Ingrese matricula: ";
        cin >> matricula;
        cout << endl;
        outfile << matricula << "   ";

        cout << "Ingrese cantidad de tareas completadas: " ;
        cin >> completadas;
        cout << endl;

        sum=0;

        for (k=0; k<completadas; k++){
            cout << "Ingrese calificacion: ";
            cin >> calificacion;
            cout << endl;
            sum =sum+calificacion;
        }

        promedio= float (sum/completadas);
        outfile << promedio << endl;

    }

    outfile.close();

    return 0;
}
