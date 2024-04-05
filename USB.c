#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> // Para mkdir

#define MAX_FILENAME_LENGTH 256
#define MAX_COMMAND_LENGTH 1000

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char usb_path[MAX_FILENAME_LENGTH];
    char command[MAX_COMMAND_LENGTH];

    // Solicitar al usuario el nombre del archivo a eliminar
    printf("Ingrese el nombre del archivo a eliminar: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);

    // Eliminar el carácter de nueva línea ('\n') al final del nombre del archivo
    filename[strcspn(filename, "\n")] = 0;

    // Solicitar al usuario la ruta de la unidad USB
    printf("Ingrese la ruta de la unidad USB (por ejemplo, /media/usb): ");
    fgets(usb_path, MAX_FILENAME_LENGTH, stdin);

    // Eliminar el carácter de nueva línea ('\n') al final de la ruta de la unidad USB
    usb_path[strcspn(usb_path, "\n")] = 0;

    // Construir la ruta completa del archivo
    char file_path[MAX_FILENAME_LENGTH * 2]; // Se duplica el tamaño para garantizar espacio suficiente
    snprintf(file_path, sizeof(file_path), "%s/%s", usb_path, filename);

    // Obtener la ruta del directorio de inicio del usuario
    const char *home_dir = getenv("HOME");
    if (home_dir == NULL) {
        printf("Error: No se pudo obtener la ruta del directorio de inicio del usuario.\n");
        return 1; // Salir con código de error
    }

    // Construir la ruta completa de la carpeta .Trash
    char trash_dir[MAX_FILENAME_LENGTH];
    snprintf(trash_dir, sizeof(trash_dir), "%s/.Trash", home_dir);

    // Crear la carpeta .Trash si no existe
    if (mkdir(trash_dir, 0700) != 0) {
        printf("Error al crear la carpeta .Trash.\n");
        return 1; // Salir con código de error
    }

    // Construir el comando para mover el archivo a la papelera de reciclaje
    snprintf(command, sizeof(command), "mv \"%s\" \"%s\"", file_path, trash_dir);

    // Mover el archivo a la papelera de reciclaje
    printf("Moviendo archivo a la papelera de reciclaje...\n");
    int status = system(command);

    // Verificar si hubo algún error al mover el archivo
    if (status != 0) {
        printf("Error al mover el archivo a la papelera de reciclaje.\n");
        return 1; // Salir con código de error
    }

    printf("Archivo movido a la papelera de reciclaje.\n");

    return 0;
}
