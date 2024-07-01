#include <stdio.h>
#include <stdlib.h>

// Declaración de la función que crea un archivo
void create_file(const char *filename, const char *content);

int main() {
    // Nombre del archivo y contenido
    const char *filename = "example.txt";
    const char *content = "Este es el contenido del archivo.";

    // Llamada a la función para crear el archivo
    create_file(filename, content);

    return 0;
}

// Definición de la función que crea un archivo
void create_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    // Escribir el contenido en el archivo
    fprintf(file, "%s", content);

    // Cerrar el archivo
    fclose(file);
}