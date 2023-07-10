#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

typedef struct {
    char codigo[max];
    char nombre[max];
    float nota;
} Estudiante;
float calcularPromedioNotas(Estudiante* estudiantes, int cantidad) {
    float suma = 0.0;
    for (int i = 0; i < cantidad; i++) {
        suma += estudiantes[i].nota;
    }
    return suma / cantidad;
}
// Función de comparación para qsort
int compararEstudiantes(const void* a, const void* b) {
    const Estudiante* estudianteA = (const Estudiante*)a;
    const Estudiante* estudianteB = (const Estudiante*)b;
    return strcmp(estudianteA->codigo, estudianteB->codigo);
}

int main() {
    FILE* archivoEntrada = fopen("input.txt", "r");
    FILE* archivoSalida = fopen("output.txt", "w");

    if (archivoEntrada == NULL || archivoSalida == NULL) {
        printf("Error al abrir los archivos.\n");
        return 1;
    }
}
