#include <stdio.h>

int main() {
    int i = 1;

    while (i <= 500) {
        int cuadrado = i * i;
        int cubo = i * i * i;
        printf("Número: %d, Cuadrado: %d, Cubo: %d\n", i, cuadrado, cubo);
        i++;
    }

    return 0;
}
