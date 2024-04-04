#include <stdio.h>
#include <pthread.h>

void *funcionHilo(void *arg) {
    printf("¡Hola desde el hilo!\n");
    pthread_exit(NULL);
}


int main() {
    pthread_t hilo;
    pthread_create(&hilo, NULL, funcionHilo, NULL);
    pthread_join(hilo, NULL);
    return 0;

}
