#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>

#include "pila.h"
#include "login.h"
#include "admin.h"
#include "combos.h"
#include "carrito.h"
#include "struct.h"

int opcionesMenuPrincipal();

int opcionesWelcome();
void validacionWelcome(Usuario usuarioIncicial);
Usuario usuarioPrincipal();

int main()
{
    welcome();
    return 0;
}

void welcome()
{
    int opcion = opcionesWelcome();
    system("cls");

    int sesion;
    Usuario usuarioInicial = usuarioPrincipal();

    switch(opcion)
    {
    case 1:
        crearUsuario();
        notificacion("");
        welcome();
        break;
    case 2:
        usuarioInicial = iniciarSesion(usuarioInicial);
        validacionWelcome(usuarioInicial);
        break;
    default:
        notificacion("Opcion invalida.");
        welcome();
    }
}

void menuPrincipal(Usuario sesion)
{
    int opcion = opcionesMenuPrincipal();
    Pelicula peliculaSeleccionada;
    Ticket ticketSeleccionado;
    bool validarTicket;
    bool validarPelicula;

    system("cls");

    switch(opcion)
    {
    case 1:
        validarPelicula = leerPeliculas();
        if(validarPelicula)
        {
            gestionarTicket(opcion, sesion);
        }
        else
        {
            notificacion("No se encontraron peliculas disponibles.");
            menuPrincipal(sesion);
        }
        break;

    case 2:
        validarTicket = leerTicket(sesion);

        if(validarTicket)
        {
            transaccionTicket(opcion);
            system("pause");
            notificacion("");
            menuPrincipal(sesion);
        }
        else
        {
            notificacion("No se encontraron tickets en tu carrito");
            menuPrincipal(sesion);
        }

        break;
    case 3:
        ingresarCombos();
        break;
    case 4:
        welcome();
        break;
    default:
        notificacion("Debe ingresar una opcion valida");
        menuPrincipal(sesion);
    }
}

void notificacion(char mensaje[30])
{
    puts(mensaje);
    puts("Redireccionando...");
    sleep(2);
    system("cls");
}

// ------------ | FUNCIONES DEL WELCOME | --------------

int opcionesWelcome()
{
    printf("---- [ Bienvenidos a CINEMACENTER ] ---- ");
    printf("\n");

    int eleccion;

    printf("\n[1] ---- Opcion 1 [Registrarme]");
    printf("\n[2] ---- Opcion 2 [Iniciar sesion]");

    printf("\n\nOpcion = ");
    fflush(stdin);
    scanf("%d", &eleccion);

    return eleccion;

}

void validacionWelcome(Usuario usuarioInicial)
{

    if(usuarioInicial.id != 0 && usuarioInicial.id != -1)
    {
        notificacion("\n\nIniciando sesion...");
        menuPrincipal(usuarioInicial);
    }
    if(usuarioInicial.id == 0)
    {
        notificacion("\n\nIngresara a la seccion de administrador");
        menuAdmin();
    }
    if(usuarioInicial.id == -1)
    {
        notificacion("\n\nUsuario y/o contraseña no coinciden.");
        welcome();
    }
}

Usuario usuarioPrincipal()
{
    Usuario usuarioInicial = {   .id = -1,
                                 .nombreUsuario = "",
                                 .password = "",
                                 .ubicacion = "",
                             };

    return usuarioInicial;
}


// ------------ | FUNCIONES MENU PRINCIPAL | --------------

int opcionesMenuPrincipal()
{
    printf("---- [ Opciones ] ---- ");
    printf("\n");

    srand(time(NULL));
    int eleccion;

    printf("\n[1] ---- Opcion 1 [Ver peliculas disponibles]");
    printf("\n[2] ---- Opcion 2 [Ver mi carrito]");
    printf("\n[3] ---- Opcion 3 [Ver supercombos cinemacenter]");
    printf("\n[4] ---- Opcion 4 [Cerrar sesion]");

    printf("\n\nOpcion = ");
    fflush(stdin);
    scanf("%d", &eleccion);

    return eleccion;
}
