#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE *fichero;
    char nombre[50];
    int edad;
    float altura;
    char respuesta;




#define MAX 1000

    do {
        // Preguntar al usuario su nombre, edad y altura
        printf("Ingrese su nombre: ");
        fflush(stdin); //Limpia el buffer
        fgets(nombre, MAX, stdin); //
        fflush(stdin); //Limpia el buffer

        /*scanf("%s", nombre);*/

        printf("Ingrese su edad: ");
        scanf("%d", &edad);

        printf("Ingrese su altura: ");
        scanf("%f", &altura);

        // Abrir el fichero en modo de escritura (si no existe, se crea; si existe, se sobrescribe)
        fichero = fopen("datos.txt", "w");

        // Verificar si el fichero se ha abierto correctamente
        if (fichero == NULL) {
            printf("Error al abrir el fichero.\n");
            return 1;  // Salir del programa con código de error
        }

        // Escribir los datos en el fichero
        fprintf(fichero, "Nombre: %s", nombre); //Por la funcion gets me mete un/0 que es un salto de linea
        fprintf(fichero, "Edad: %d\n", edad);
        fprintf(fichero, "Altura: %.2f\n", altura);

        // Cerrar el fichero
        fclose(fichero);

        // Informar al usuario que los datos han sido guardados
        printf("Los datos han sido guardados en el fichero.\n");

        // Preguntar al usuario si quiere imprimir los datos
        printf("Quieres imprimir los datos? (s/n): ");
        scanf(" %c", &respuesta);

        // Verificar la respuesta del usuario
        if (respuesta == 's' || respuesta == 'S') {
            // Abrir el fichero en modo de lectura
            fichero = fopen("datos.txt", "r");

            // Verificar si el fichero se ha abierto correctamente
            if (fichero == NULL) {
                printf("Error al abrir el fichero para leer.\n");
                return 1;  // Salir del programa con código de error
            }

            // Leer y mostrar los datos del fichero
            char caracter;
            while ((caracter = fgetc(fichero)) != EOF) { //No se entiende ni el pijo Guarrada
                //Correccion: El bucle a lo largo Esta en la pizarra probablemente habra una foto en el grupo
                printf("%c", caracter);
            }

            // Cerrar el fichero
            fclose(fichero);
        }

        // Preguntar al usuario si desea repetir el proceso
        printf("Quieres ingresar nuevos datos? (s/n): ");
        scanf(" %c", &respuesta);

    } while (respuesta == 's' || respuesta == 'S');

    return 0;  // Salir del programa con éxito
}


