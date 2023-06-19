#include <stdio.h>
#include <string.h>

struct Persona {
    char nombre[50];
    char apellido[50];
    char dni[9];
    char telefono[20];
    char fecha_cumple[11];
};

int num_personas = 0;
struct Persona agenda[100];

// funcion para agregar personas a la agenda 
void agregar_persona() {
    if (num_personas >= 100) {
        printf("La agenda esta llena.\n");
        return;
    }

    struct Persona nueva_persona;

    printf("Ingrese el nombre: ");
    scanf("%s", nueva_persona.nombre);

    printf("Ingrese el apellido: ");
    scanf("%s", nueva_persona.apellido);

    printf("Ingrese el DNI: ");
    scanf("%s", nueva_persona.dni);

    // verificar si el dni ya existe 
    int i;
    for (i = 0; i < num_personas; i++) {
        if (strcmp(agenda[i].dni, nueva_persona.dni) == 0) {
            printf("El DNI ingresado ya existe en la agenda.\n");
            return;
        }
    }

    printf("Ingrese el telefono: ");
    scanf("%s", nueva_persona.telefono);

    printf("Ingrese la fecha de cumpleanios (DD/MM/AAAA): ");
    scanf("%s", nueva_persona.fecha_cumple);

    agenda[num_personas] = nueva_persona;
    num_personas++;

    printf("Persona agregada a la agenda.\n");
}

// lista de las personas registradas 
void mostrar_listado_general() {
    if (num_personas == 0) {
        printf("La agenda esta vacia!.\n");
        return;
    }

    printf("Listado general de personas:\n");
    int i;
    for (i = 0; i < num_personas; i++) {
        printf("Persona %d:\n", i+1);
        printf("Nombre: %s\n", agenda[i].nombre);
        printf("Apellido: %s\n", agenda[i].apellido);
        printf("DNI: %s\n", agenda[i].dni);
        printf("Telefono: %s\n", agenda[i].telefono);
        printf("Fecha de cumpleanios: %s\n", agenda[i].fecha_cumple);
        printf("\n");
    }
}

// nacidas en un aÃ±o especifico 
void mostrar_personas_por_anio() {
    if (num_personas == 0) {
        printf("La agenda esta vacia!.\n");
        return;
    }

    int anio_buscar;
    printf("Ingrese el anio de nacimiento: ");
    scanf("%d", &anio_buscar);

    printf("Personas nacidas en el anio %d:\n", anio_buscar);
    int i;
    for (i = 0; i < num_personas; i++) {
        int anio_nacimiento;
        sscanf(agenda[i].fecha_cumple, "%*d/%*d/%d", &anio_nacimiento);
        if (anio_nacimiento == anio_buscar) {
            printf("Persona %d:\n", i+1);
            printf("Nombre: %s\n", agenda[i].nombre);
            printf("Apellido: %s\n", agenda[i].apellido);
            printf("DNI: %s\n", agenda[i].dni);
            printf("Telefono: %s\n", agenda[i].telefono);
            printf("Fecha de cumpleanios: %s\n", agenda[i].fecha_cumple);
            printf("\n");
        }
    }
}

// buscar persona mas joven
void encontrar_persona_mas_joven() {
    if (num_personas == 0) {
        printf("La agenda esta vacia!.\n");
        return;
    }

    struct Persona persona_nacimiento_ultimo = agenda[0];
    int i;
    for (i = 1; i < num_personas; i++) {
        int dia_nacimiento_actual, mes_nacimiento_actual, anio_nacimiento_actual;
        int dia_nacimiento_ultimo, mes_nacimiento_ultimo, anio_nacimiento_ultimo;

        sscanf(agenda[i].fecha_cumple, "%d/%d/%d", &dia_nacimiento_actual, &mes_nacimiento_actual, &anio_nacimiento_actual);
        sscanf(persona_nacimiento_ultimo.fecha_cumple, "%d/%d/%d", &dia_nacimiento_ultimo, &mes_nacimiento_ultimo, &anio_nacimiento_ultimo);

        if (anio_nacimiento_actual > anio_nacimiento_ultimo) {
            persona_nacimiento_ultimo = agenda[i];
        } else if (anio_nacimiento_actual == anio_nacimiento_ultimo) {
            if (mes_nacimiento_actual > mes_nacimiento_ultimo) {
                persona_nacimiento_ultimo = agenda[i];
            } else if (mes_nacimiento_actual == mes_nacimiento_ultimo) {
                if (dia_nacimiento_actual > dia_nacimiento_ultimo) {
                    persona_nacimiento_ultimo = agenda[i];
                }
            }
        }
    }

    printf("Persona mas joven:\n");
    printf("Nombre: %s\n", persona_nacimiento_ultimo.nombre);
    printf("Apellido: %s\n", persona_nacimiento_ultimo.apellido);
    printf("DNI: %s\n", persona_nacimiento_ultimo.dni);
    printf("Telefono: %s\n", persona_nacimiento_ultimo.telefono);
    printf("Fecha de cumpleanios: %s\n", persona_nacimiento_ultimo.fecha_cumple);
}

// editar de una persona especifica 
void editar_persona() {
    if (num_personas == 0) {
        printf("La agenda esta vacia!.\n");
        return;
    }

    char dni_editar[9];
    printf("Ingrese el DNI de la persona a editar: ");
    scanf("%s", dni_editar);

    int i;
    for (i = 0; i < num_personas; i++) {
        if (strcmp(agenda[i].dni, dni_editar) == 0) {
            printf("Ingrese los nuevos datos de la persona:\n");
            printf("Nombre: ");
            scanf("%s", agenda[i].nombre);

            printf("Apellido: ");
            scanf("%s", agenda[i].apellido);

            printf("Telefono: ");
            scanf("%s", agenda[i].telefono);

            printf("Fecha de cumpleanios (DD/MM/AAAA): ");
            scanf("%s", agenda[i].fecha_cumple);

            printf("Datos de la persona actualizados.\n");
            return;
        }
    }

    printf("Persona no encontrada en la agenda!.\n");
}

// mostrar datos de una persona especifica 
void mostrar_datos_persona() {
    if (num_personas == 0) {
        printf("La agenda esta vacia!.\n");
        return;
    }

    char dni_buscar[9];
    printf("Ingrese el DNI de la persona: ");
    scanf("%s", dni_buscar);

    int i;
    for (i = 0; i < num_personas; i++) {
        if (strcmp(agenda[i].dni, dni_buscar) == 0) {
            printf("Datos de la persona:\n");
            printf("Nombre: %s\n", agenda[i].nombre);
            printf("Apellido: %s\n", agenda[i].apellido);
            printf("DNI: %s\n", agenda[i].dni);
            printf("Telefono: %s\n", agenda[i].telefono);
            printf("Fecha de cumpleanios: %s\n", agenda[i].fecha_cumple);
            return;
        }
    }

    printf("Persona no encontrada en la agenda.\n");
}

// buscar persona por su dni 
void buscar_persona_por_dni() {
    if (num_personas == 0) {
        printf("La agenda esta vacia!.\n");
        return;
    }

    char dni_buscar[9];
    printf("Ingrese el DNI de la persona: ");
    scanf("%s", dni_buscar);

    int i;
    for (i = 0; i < num_personas; i++) {
        if (strcmp(agenda[i].dni, dni_buscar) == 0) {
            printf("Persona encontrada:\n");
            printf("Nombre: %s\n", agenda[i].nombre);
            printf("Apellido: %s\n", agenda[i].apellido);
            printf("DNI: %s\n", agenda[i].dni);
            printf("Telefono: %s\n", agenda[i].telefono);
            printf("Fecha de cumpleanios: %s\n", agenda[i].fecha_cumple);
            return;
        }
    }

    printf("Persona no encontrada en la agenda.\n");
}

int main() {
    int opcion;

    do {
        printf("---- AGENDA ----\n");
        printf("1. Agregar persona\n");
        printf("2. Mostrar listado general\n");
        printf("3. Mostrar personas por anio de nacimiento\n");
        printf("4. Mostrar persona que nacio mas joven\n");
        printf("5. Editar datos de una persona\n");
        printf("6. Mostrar datos detallados de una persona\n");
        printf("7. Buscar persona por DNI\n");
        printf("8. Salir\n");

        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregar_persona();
                break;
            case 2:
                mostrar_listado_general();
                break;
            case 3:
                mostrar_personas_por_anio();
                break;
            case 4:
                encontrar_persona_mas_joven();
                break;
            case 5:
                editar_persona();
                break;
            case 6:
                mostrar_datos_persona();
                break;
            case 7:
                buscar_persona_por_dni();
                break;
            case 8:
                printf("¡Hasta luego!\n");
                break;
            default:
                printf("Opcion invalida.\n");
                break;
        }

        printf("\n");

    } while (opcion != 8);

    return 0;
}