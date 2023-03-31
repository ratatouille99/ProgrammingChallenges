#include <stdio.h>

// Definici�n del enum para d�as de la semana
enum DiasDeLaSemana {
    Lunes,
    Martes,
    Miercoles,
    Jueves,
    Viernes,
    Sabado,
    Domingo
};

int main() {
    // Declaraci�n de una variable de tipo enum
    enum DiasDeLaSemana hoy;

    // Asignaci�n de un valor del enum a la variable
    hoy = Miercoles;

    // Imprime el valor de la variable y su nombre en el enum
    printf("Hoy es %s (%d)\n",
           hoy == Miercoles ? "mi�rcoles" : "otro d�a",
           hoy);

    return 0;
}
