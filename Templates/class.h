#ifndef Clase_class
#define Clase_class

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Cochinito{
private:
    T dinero;
public:
    Cochinito<T> (T dinero){
    this->dinero=dinero;
    }
    Cochinito<T>(){
    dinero=50;
    }

   T getDinero(){
    return dinero/3.0;
    }

    void setDinero(T din){
        dinero=din;
    }

      Cochinito <T> operator+(Cochinito<T> &c){
        Cochinito<T> nuevo();
        T agregado = dinero+c.getDinero();
        nuevo.setDinero(agregado);
        return (nuevo.getDinero());
    }



};


#endif // Clase_class
