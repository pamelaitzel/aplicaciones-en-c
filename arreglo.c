#include <stdio.h>

int main() {
    int vector[10];
    int i = 0;

    // Asigna el valor 10 a cada posición del arreglo
    while (i < 10) {
        vector[i] = 10;
        i++;
    }

    // Muestra todas las posiciones del arreglo
    printf("Contenido del vector:\n");
    i = 0; // Reinicia la variable i
    while (i < 10) {
        printf("Posición %d: %d\n", i, vector[i]);
        i++;
    }

    return 0;
}
