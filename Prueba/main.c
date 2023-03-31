#include <stdio.h>

// Definición del enum para días de la semana
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
    // Declaración de una variable de tipo enum
    enum DiasDeLaSemana hoy;

    // Asignación de un valor del enum a la variable
    hoy = Miercoles;

    // Imprime el valor de la variable y su nombre en el enum
    printf("Hoy es %s (%d)\n",
           hoy == Miercoles ? "miércoles" : "otro día",
           hoy);

    return 0;
}
