#include <stdio.h>
#include <string.h>
#include<malloc.h>
#include <stdlib.h>

// typedef char** string;
typedef enum { false, true } bool;

int main(int argc, char **argv[]) {
    int arrLength = 0;
    char* array = malloc(sizeof(char));

    printf("Enter the length of the array: ");
    scanf("%d", &arrLength);

    for (int i = 0; i < arrLength; i++)
    {
        char* estudiante = malloc(sizeof(char));
        char* promedio = malloc(sizeof(char));

        printf("Ingresa el nombre %d: ", i);
        scanf("%s", estudiante);

        printf("Ingresa el promedio %d: ", i);
        scanf("%s", promedio);

        strcat(array, estudiante);
        strcat(array, "|");
        strcat(array, promedio);

        if(i == arrLength-1) {
            strcat(array, "\0");
            break;
        }
        strcat(array, ",");
        free(estudiante);
        free(promedio);
    }

    int puntero = 0;
    for(int i = 0; i < arrLength; i++) {
        int promedio = 0;
        char* estudiante = malloc(sizeof(char));
        char* tempPromedio = malloc(sizeof(char));
        bool isNumber = false;
            
        for(int j = puntero; j < strlen(array); j++) {
            if(array[j] == ',') {
                puntero = j + 1;
                isNumber = false;
                break;
            } else if(array[j] == '|') {
                j++;
                isNumber = true;
            }
            if(isNumber) {
                strncat(tempPromedio, &array[j], 1);
            } else {
                strncat(estudiante, &array[j], 1);
            }
        }
        promedio = atoi(tempPromedio);
        if(promedio > 60) {
            printf("El/La estudiante %s Aprobo con promedio de: %d\n", estudiante, promedio);
        }
        free(estudiante);
        free(tempPromedio);
    }


    return 0;
}
