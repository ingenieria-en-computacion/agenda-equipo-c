#include <stdio.h>
#include <string.h>
#include "agenda.h"

int main() {
    Agenda agenda;
    agenda.cantidad = 0;

    int opcion;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Agregar contacto\n");
        printf("2. Imprimir contactos\n");
        printf("3. Buscar por nombre\n");
        printf("4. Buscar por telefono\n");
        printf("5. Ordenar A-Z\n");
        printf("6. Ordenar Z-A\n");
        printf("7. Guardar agenda\n");
        printf("8. Cargar agenda\n");
        printf("9. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            agregar_contacto(&agenda);
        }
        else if (opcion == 2) {
            imprimir_contactos(agenda);
        }
        else if (opcion == 3) {
            char nombre[30];
            printf("Nombre a buscar: ");
            scanf("%s", nombre);
            buscar_por_nombre(agenda, nombre);
        }
        else if (opcion == 4) {
            char telefono[20];
            printf("Telefono a buscar: ");
            scanf("%s", telefono);
            buscar_por_telefono(agenda, telefono);
        }
        else if (opcion == 5) {
            ordenar_contactos(&agenda, 1);
            printf("Ordenado A-Z.\n");
        }
        else if (opcion == 6) {
            ordenar_contactos(&agenda, 0);
            printf("Ordenado Z-A.\n");
        }
        else if (opcion == 7) {
            guardar_agenda(agenda, "agenda.txt");
        }
        else if (opcion == 8) {
            cargar_agenda(&agenda, "agenda.txt");
        }

    } while (opcion != 9);

    return 0;
}
