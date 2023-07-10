#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTUDIANTES 100

typedef struct
{
    char codigo[100];
    char nombre[100];
    char carrera[100];
    float notas[3];
} Estudiante;

float calcularPromedioNotas(Estudiante *estudiantes, int cantidad)
{
    float suma = 0.0;
    for (int i = 0; i < cantidad; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            suma += estudiantes[i].notas[j];
        }
    }
    return suma / (cantidad * 3);
}

int compararEstudiantes(const void *a, const void *b)
{
    const Estudiante *estudianteA = (const Estudiante *)a;
    const Estudiante *estudianteB = (const Estudiante *)b;
    return strcmp(estudianteB->codigo, estudianteA->codigo); // Cambio en la función de comparación para ordenar de mayor a menor
}


int main()
{
    FILE *archivoEntrada = fopen("alumnos.txt", "r");
    FILE *archivoSalida = fopen("listaalumnosnueva.txt", "w+");

    if (archivoEntrada == NULL || archivoSalida == NULL)
    {
        printf("Error al abrir los archivos.\n");
        return 1;
    }

    Estudiante estudiantes[MAX_ESTUDIANTES];
    int cantidadEstudiantes = 0;

    char linea[200]; // Se asume que una línea no excederá los 200 caracteres

    // Leer los datos del archivo
    while (fgets(linea, sizeof(linea), archivoEntrada))
    {
        // Analizar la línea para obtener los campos
        char *token;
        token = strtok(linea, ";"); // Separar la línea por el delimitador ";"

        // Obtener el código del estudiante
        strcpy(estudiantes[cantidadEstudiantes].codigo, token);

        // Obtener el nombre del estudiante
        token = strtok(NULL, ";");
        strcpy(estudiantes[cantidadEstudiantes].nombre, token);

        // Obtener la carrera del estudiante
        token = strtok(NULL, ";");
        strcpy(estudiantes[cantidadEstudiantes].carrera, token);

        // Obtener las notas del estudiante
        for (int i = 0; i < 3; i++)
        {
            token = strtok(NULL, ";");
            estudiantes[cantidadEstudiantes].notas[i] = atof(token);
        }

        cantidadEstudiantes++;
    }

    // Ordenar los estudiantes por código
    qsort(estudiantes, cantidadEstudiantes, sizeof(Estudiante), compararEstudiantes);

    // Calcular el promedio de notas por cada columna
    float promedioNotas1 = 0.0;
    float promedioNotas2 = 0.0;
    float promedioNotas3 = 0.0;

    for (int i = 0; i < cantidadEstudiantes; i++)
    {
        promedioNotas1 += estudiantes[i].notas[0];
        promedioNotas2 += estudiantes[i].notas[1];
        promedioNotas3 += estudiantes[i].notas[2];
    }

    promedioNotas1 /= cantidadEstudiantes;
    promedioNotas2 /= cantidadEstudiantes;
    promedioNotas3 /= cantidadEstudiantes;

    // Escribir los estudiantes ordenados en el archivo de salida
    fprintf(archivoSalida, "Código,Nombre,Carrera,Nota1,Nota2,Nota3\n");
    for (int i = 0; i < cantidadEstudiantes; i++)
    {
        fprintf(archivoSalida, "%s,%s,%s,%.2f,%.2f,%.2f\n", estudiantes[i].codigo, estudiantes[i].nombre, estudiantes[i].carrera,
                estudiantes[i].notas[0], estudiantes[i].notas[1], estudiantes[i].notas[2]);
    }

    // Escribir los promedios de notas en la última fila del archivo de salida
    fprintf(archivoSalida, "Promedio de notas: %.2f,%.2f,%.2f\n", promedioNotas1, promedioNotas2, promedioNotas3);

    // Cerrar los archivos
    fclose(archivoEntrada);
    fclose(archivoSalida);

    printf("Archivo generado correctamente.\n");

    return 0;
}
