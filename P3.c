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
    Estudiante estudiantes[max];
    int cantidadEstudiantes = 0;

    // Leer los datos del archivo
    while (fscanf(archivoEntrada, "%[^,],%[^,],%f\n", estudiantes[cantidadEstudiantes].codigo, estudiantes[cantidadEstudiantes].nombre, &estudiantes[cantidadEstudiantes].nota) == 3) {
        cantidadEstudiantes++;
    }
    // Ordenar los estudiantes por código
    qsort(estudiantes, cantidadEstudiantes, sizeof(Estudiante), compararEstudiantes);

    // Calcular el promedio de notas
    float promedioNotas = calcularPromedioNotas(estudiantes, cantidadEstudiantes);

    // Escribir los estudiantes ordenados en el archivo de salida
    fprintf(archivoSalida, "Código,Nombre,Nota\n");
    for (int i = 0; i < cantidadEstudiantes; i++) {
        fprintf(archivoSalida, "%s,%s,%.2f\n", estudiantes[i].codigo, estudiantes[i].nombre, estudiantes[i].nota);
    }

    // Escribir el promedio de notas en el archivo de salida
    fprintf(archivoSalida, "Promedio de notas, ,%.2f\n", promedioNotas);

    // Cerrar los archivos
    fclose(archivoEntrada);
    fclose(archivoSalida);

    printf("Archivo generado correctamente.\n");

    return 0;
}
    
}
