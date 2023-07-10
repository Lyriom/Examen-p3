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
    
    printf("Hello world");

    return 0;
}
