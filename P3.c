#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LONGITUD 100

typedef struct {
    char codigo[MAX_LONGITUD];
    char nombre[MAX_LONGITUD];
    float nota;
} Estudiante;

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
