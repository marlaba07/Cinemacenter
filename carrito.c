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

bool leerTicket(Usuario sesion)
{
    Ticket a;
    FILE * archivo;
    bool flag = false;
    archivo = fopen("ticket.bin", "rb");
    if(archivo != NULL)
    {
        while(fread(&a,sizeof(Ticket),1,archivo)>0)
        {
            if(a.usuario.id == sesion.id)
            {
                printf("------------------------------------------------------\n");
                printf("ID: %d\n", a.id);
                printf("Nombre de la pelicula: %s\n", a.pelicula.nombrePelicula);
                printf("Cantidad de personas: %d\n", a.cantidadEntradas);
                printf("Precio total de la entrada: $%d\n", a.precio);
                printf("Fecha: %s\n", a.pelicula.fechaEstreno);
                printf("Nombre de cine: %s\n", a.cine.nombreCine);
                printf("Numero de sala: %d\n", a.cine.numeroSala);
                printf("Horario: %s hs\n", a.pelicula.horario);
                printf("Genero: %s\n", a.pelicula.genero);
                printf("-----------------------------------------------------\n");
                flag = true;
                printf("\n");
            }
        }
    }
    return flag;
}

void crearTicket(Usuario usuarioSeleccionado, Pelicula peliculaSeleccionada, Cine cineSeleccionado)
{
    Ticket entrada;
    entrada.id = contarRegistroTicket("ticket.bin") + 1;

    entrada.pelicula = peliculaSeleccionada;
    entrada.cine = cineSeleccionado;
    entrada.usuario = usuarioSeleccionado;

    system("cls");
    printf("Ingresar cantidad de entradas: ");
    fflush(stdin);
    scanf("%d", &entrada.cantidadEntradas);
    entrada.precio = PRECIO * entrada.cantidadEntradas;

    guardarTicket(entrada);
    puts("\n");
    notificacion("Ticket creado con exito!");
    menuPrincipal(usuarioSeleccionado);
}


Ticket validarIDTicket(int opcion)
{
    Ticket a;
    Ticket b;
    b.id = 0;
    FILE * archivo;

    archivo = fopen("Ticket.bin", "rb");
    if(archivo != NULL)
    {
        while(fread(&a,sizeof(Ticket),1,archivo)>0)
        {
            if(a.id == opcion)
            {
                return a;
            }
        }
    }

    fclose(archivo);

    return b;
}

int contarRegistroTicket(char nombre[50])
{
    int cantidad = 0;
    long tam = 0;

    FILE * archi = fopen(nombre,"rb");
    if (archi !=NULL)
    {
        fseek(archi,0,SEEK_END);
        tam = ftell(archi);
        cantidad = tam / sizeof(Ticket);
    }

    fclose(archi);
    return cantidad;
}

void gestionarTicket(int opcion, Usuario sesion)
{
    printf("Ingresar ID de la pelicula que desee agregar al carrito:  ");
    fflush(stdin);
    scanf("%d", &opcion);

    Pelicula peliculaSeleccionada = validarIDPelicula(opcion);
    system("cls");

    if(peliculaSeleccionada.id == 0)
    {
        printf("No se encontro la pelicula. ");
        system("pause");
        system("cls");
        menuPrincipal(sesion);
    }

    leerCines();

    printf("Ingresar ID cine que desee agregar al carrito:  ");
    fflush(stdin);
    scanf("%d", &opcion);

    Cine cineSeleccionado = validarIDCine(opcion);
    system("cls");

    if(cineSeleccionado.id == 0)
    {
        printf("No se encontro el cine. ");
        system("pause");
        system("cls");
        menuPrincipal(sesion);

    }
    crearTicket(sesion, peliculaSeleccionada, cineSeleccionado);
}

void transaccionTicket(int opcion)
{
    printf("Elegir ID de ticket que desea abonar: ");
    fflush(stdin);
    scanf("%d", &opcion);

    Ticket ticketSeleccionado = validarIDTicket(opcion);
    if(ticketSeleccionado.id != 0)
    {
        system("cls");
        puts("-------------------------------------------------");
        printf("Operacion realizada con exito.\n");
        printf("Canjear este codigo en el cine |%d| \n ",rand() );
        puts("-------------------------------------------------");
        puts("\n");
    }
}
