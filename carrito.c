#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carrito.h"
#include "admin.h"
#include "struct.h"
#define PRECIO 400



void guardarTicket(Ticket ticket)
{
    FILE * archivo;

    archivo = fopen("ticket.bin","ab");

    if (archivo != NULL )
    {
        fwrite(&ticket,sizeof(Ticket),1,archivo);
    }

    fclose(archivo);
}

void leerTicket()
{
    Ticket a;
    FILE * archivo;

    archivo = fopen("ticket.bin", "rb");
    if(archivo != NULL)
    {
        while(fread(&a,sizeof(Ticket),1,archivo)>0)
        {
            printf("------------------------------------------------------\n");
            printf("Nombre de la pelicula: %s\n", a.pelicula.nombrePelicula);
            printf("Cantidad de personas: %d\n", a.cantidadEntradas);
            printf("Precio total de la entrada: $%d\n", a.precio);
            printf("Fecha: %s\n", a.pelicula.fechaEstreno);
            printf("Nombre de cine: %s\n", a.cine.nombreCine);
            printf("Numero de sala: %d\n", a.cine.numeroSala);
            printf("Horario: %s hs\n", a.pelicula.horario);
            printf("Genero: %s\n", a.pelicula.genero);
            printf("-----------------------------------------------------\n");

            printf("\n");
        }
    }
}

void crearTicket(Pelicula peliculaSeleccionada, Cine cineSeleccionado)
{
    if(peliculaSeleccionada.id != NULL || cineSeleccionado.id != NULL)
    {
        Ticket entrada;
        entrada.pelicula = peliculaSeleccionada;
        entrada.cine = cineSeleccionado;
        printf("Ingresar cantidad de entradas: ");
        fflush(stdin);
        scanf("%d", &entrada.cantidadEntradas);
        entrada.precio = PRECIO * entrada.cantidadEntradas;

        guardarTicket(entrada);
        system("pause");
        menuPrincipal();
    }
    else
    {
        notificacion("El ID de la pelicula o cine no existe. ");
        menuPrincipal();
    }
}
