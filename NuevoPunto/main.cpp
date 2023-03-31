#include <iostream>
#include "Punto.h"

using namespace std;

int main(){

    Punto nuevo;

    nuevo.fijarX(3);
    nuevo.fijarY(5);

    cout<<nuevo.leerX();

    return 0;
}
