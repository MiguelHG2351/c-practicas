#include <stdio.h>
#include <string.h>
#include<malloc.h>
#include <stdlib.h>

// Como funciona esta cosa?
// el arreglo guarda info de la sig manera:
// estudiante|promedio
// luego para agregar otro estudiante se agrega una coma
// estudiante|promedio,estudiante2|promedio2

// no funciono :,v
// typedef char** string;

typedef enum { false, true } bool;

int main(int argc, char **argv[]) {
    int arrLength = 0;
    char* array = malloc(sizeof(char)); // tipo de dato string :D

    printf("Enter the length of the array: ");
    scanf("%d", &arrLength); // pide el tamaño del arreglo

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
        // esos strcat daran:
        // estudiante|promedio

        if(i == arrLength-1) {
            // el \0 es para que termine el string
            // una forma segura de indicarle el final de arreglo
            // cuando usamos punteros (creo recordar que era así xD)
            strcat(array, "\0");
            break;
        }
        // si aún no termina el ciclo entonces agregamos
        // una coma para agregar le sig estudiante
        strcat(array, ",");
        // liberamos la memoria
        free(estudiante);
        free(promedio);
    }

    // el puntero funcionara como el index
    // al econtrar una coma guardara la posición de esa coma
    // y la variable j ya no inciara en 0
    // sino en el último punto guardado
    int puntero = 0;
    for(int i = 0; i < arrLength; i++) {

        int promedio = 0;
        char* estudiante = malloc(sizeof(char));
        char* tempPromedio = malloc(sizeof(char));
        bool isNumber = false;
        // si actualmente esta recorriendo un numero
        // entonces es true
            
        for(int j = puntero; j < strlen(array); j++) {
            if(array[j] == ',') {
                puntero = j + 1;
                isNumber = false;
                // al llegar aquí quiere decir que va a recorrer
                // otro estudiante entonces terminamos el ciclo
                break;
            } else if(array[j] == '|') {
                // encontramos el promedio del estudiante
                j++;
                isNumber = true;
            }
            if(isNumber) {
                strncat(tempPromedio, &array[j], 1);
            } else {
                strncat(estudiante, &array[j], 1);
            }
        }

        // convertimos de string a int
        promedio = atoi(tempPromedio);

        // validamos
        if(promedio > 60) {
            // y listooooooooooo
            printf("El/La estudiante %s Aprobo con promedio de: %d\n", estudiante, promedio);
        }
        free(estudiante);
        free(tempPromedio);
    }


    return 0;
}
