#include <stdio.h>
#include <string.h>
#include "agenda.h"

void agregar_contacto(Agenda *a) {
    if (a->cantidad >= 100) {
        printf("Agenda llena.\n");
        return;
    }

    Contacto c;
    printf("Nombre: ");
    scanf("%s", c.nombre);
    printf("Apellido: ");
    scanf("%s", c.apellido);
    printf("Día de cumpleaños: ");
    scanf("%d", &c.dia);
    printf("Mes de cumpleaños: ");
    scanf("%d", &c.mes);
    printf("Teléfono: ");
    scanf("%s", c.telefono);
    printf("Tipo (amigo, familiar, etc.): ");
    scanf("%s", c.tipo);

    a->contactos[a->cantidad] = c;
    a->cantidad++;

    printf("Contacto agregado correctamente.\n");
}

void imprimir_contactos(Agenda a) {
    if (a.cantidad == 0) {
        printf("No hay contactos.\n");
        return;
    }

    for (int i = 0; i < a.cantidad; i++) {
        printf("\n--- CONTACTO %d ---\n", i + 1);
        printf("Nombre: %s %s\n", a.contactos[i].nombre, a.contactos[i].apellido);
        printf("Cumpleaños: %d/%d\n", a.contactos[i].dia, a.contactos[i].mes);
        printf("Teléfono: %s\n", a.contactos[i].telefono);
        printf("Tipo: %s\n", a.contactos[i].tipo);
    }
}

void buscar_por_nombre(Agenda a, const char *nombre) {
    int encontrado = 0;
    for (int i = 0; i < a.cantidad; i++) {
        if (strcmp(a.contactos[i].nombre, nombre) == 0) {
            encontrado = 1;
            printf("\nEncontrado:\n");
            printf("Nombre: %s %s\n", a.contactos[i].nombre, a.contactos[i].apellido);
            printf("Cumpleaños: %d/%d\n", a.contactos[i].dia, a.contactos[i].mes);
            printf("Teléfono: %s\n", a.contactos[i].telefono);
            printf("Tipo: %s\n", a.contactos[i].tipo);
        }
    }
    if (!encontrado)
        printf("No se encontró el nombre.\n");
}

void buscar_por_telefono(Agenda a, const char *telefono) {
    int encontrado = 0;
    for (int i = 0; i < a.cantidad; i++) {
        if (strcmp(a.contactos[i].telefono, telefono) == 0) {
            encontrado = 1;
            printf("\nEncontrado:\n");
            printf("Nombre: %s %s\n", a.contactos[i].nombre, a.contactos[i].apellido);
            printf("Cumpleaños: %d/%d\n", a.contactos[i].dia, a.contactos[i].mes);
            printf("Teléfono: %s\n", a.contactos[i].telefono);
            printf("Tipo: %s\n", a.contactos[i].tipo);
        }
    }
    if (!encontrado)
        printf("No se encontró el teléfono.\n");
}

void ordenar_contactos(Agenda *a, int asc) {
    for (int i = 0; i < a->cantidad - 1; i++) {
        for (int j = i + 1; j < a->cantidad; j++) {

            int cmp = strcmp(a->contactos[i].nombre, a->contactos[j].nombre);

            if ((asc && cmp > 0) || (!asc && cmp < 0)) {
                Contacto temp = a->contactos[i];
                a->contactos[i] = a->contactos[j];
                a->contactos[j] = temp;
            }
        }
    }
    printf("Contactos ordenados.\n");
}

void guardar_agenda(Agenda a, const char *archivo) {
    FILE *f = fopen(archivo, "w");
    if (!f) {
        printf("Error al guardar.\n");
        return;
    }

    fprintf(f, "%d\n", a.cantidad);

    for (int i = 0; i < a.cantidad; i++) {
        fprintf(f, "%s %s %d %d %s %s\n",
                a.contactos[i].nombre,
                a.contactos[i].apellido,
                a.contactos[i].dia,
                a.contactos[i].mes,
                a.contactos[i].telefono,
                a.contactos[i].tipo);
    }

    fclose(f);
    printf("Agenda guardada.\n");
}

void cargar_agenda(Agenda *a, const char *archivo) {
    FILE *f = fopen(archivo, "r");
    if (!f) {
        printf("No existe el archivo.\n");
        return;
    }

    fscanf(f, "%d", &a->cantidad);

    for (int i = 0; i < a->cantidad; i++) {
        fscanf(f, "%s %s %d %d %s %s",
               a->contactos[i].nombre,
               a->contactos[i].apellido,
               &a->contactos[i].dia,
               &a->contactos[i].mes,
               a->contactos[i].telefono,
               a->contactos[i].tipo);
    }

    fclose(f);
    printf("Agenda cargada.\n");
}
