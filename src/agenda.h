#ifndef AGENDA_H
#define AGENDA_H

typedef struct {
    char nombre[30];
    char apellido[30];
    int dia;
    int mes;
    char telefono[20];
    char tipo[20];
} Contacto;

typedef struct {
    Contacto contactos[100];
    int cantidad;
} Agenda;

// PROTOTIPOS
void agregar_contacto(Agenda *a);
void imprimir_contactos(Agenda a);
void buscar_por_nombre(Agenda a, const char *nombre);
void buscar_por_telefono(Agenda a, const char *telefono);
void ordenar_contactos(Agenda *a, int asc);
void guardar_agenda(Agenda a, const char *archivo);
void cargar_agenda(Agenda *a, const char *archivo);

#endif
