#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#include "pila.h"
#include "login.h"
#include "admin.h"
#include "combos.h"
#include "carrito.h"
#include "struct.h"


int main()
{
    // system("color b4");
    // leerUsuario();
    welcome();

    return 0;
}

void welcome()
{
    printf("---- [ Bienvenidos a CINEMACENTER ] ---- ");
    printf("\n");

    int opcion;

    printf("\n[1] ---- Opcion 1 [Registrarme]");
    printf("\n[2] ---- Opcion 2 [Iniciar sesion]");

    printf("\n\nOpcion = ");
    fflush(stdin);
    scanf("%d", &opcion);

    system("cls");

    int sesion;

    switch(opcion)
    {
    case 1:
        crearUsuario(opcion);
        notificacion("");
        welcome();
        break;
    case 2:
        sesion = iniciarSesion(opcion);
        if(sesion == 1)
        {
            notificacion("\n");
            menuPrincipal();
        }
        if(sesion == 2)
        {
            puts("\n");
            notificacion("Ingresara a la seccion de administrador");
            menuAdmin();
        }
        if(sesion == 0)
        {
            notificacion("Usuario y contraseña no coinciden.");
            welcome();
        }

        break;
    default:
        notificacion("Opcion invalida.");
        welcome();
    }
}

void menuPrincipal()
{
    printf("---- [ Opciones ] ---- ");
    printf("\n");

    int opcion;

    printf("\n[1] ---- Opcion 1 [Ver peliculas disponibles]");
    printf("\n[2] ---- Opcion 2 [Ver mi carrito]");
    printf("\n[3] ---- Opcion 3 [Ver supercombos cinemacenter]");
    printf("\n[4] ---- Opcion 4 [Cerrar sesion]");

    printf("\n\nOpcion = ");
    fflush(stdin);
    scanf("%d", &opcion);

    Pelicula peliculaSeleccionada;

    system("cls");

    switch(opcion)
    {
    case 1:
        leerPeliculas();
        printf("Ingresar ID de la pelicula que desee agregar al carrito:  ");
        fflush(stdin);
        scanf("%d", &opcion);
        Pelicula peliculaSeleccionada = validarIDPelicula(opcion);
        printf("PELICULA ID SELECCIONADA: %d \n", peliculaSeleccionada.id);


        leerCines();
        printf("Ingresar ID cine que desee agregar al carrito:  ");
        fflush(stdin);
        scanf("%d", &opcion);
        Cine cineSeleccionado = validarIDCine(opcion);

        system("cls");

        crearTicket(peliculaSeleccionada, cineSeleccionado);

        break;
    case 2:
        leerTicket();
        system("pause");
        menuPrincipal();
        break;
    case 3:
        ingresarCombos();
        break;
    case 4:
        welcome();
        break;
    default:
        notificacion("Debe ingresar una opcion valida");
        menuPrincipal();
    }
}

void notificacion(char mensaje[30])
{
    puts(mensaje);
    puts("Redireccionando...");
    sleep(2);
    system("cls");
}











