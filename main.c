#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#include "pila.h"
#include "login.h"
#include "admin.h"

int main()
{
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
            menuPrincipal();
        }
        if(sesion == 2){
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

    system("cls");

    switch(opcion)
    {
    case 1:
        puts("Se ha pulsado una a.");
        break;
    case 2:
        puts("Se ha pulsado una a.");
        break;
    case 3:
        puts("Se ha pulsado una a.");
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
    sleep(3);
    system("cls");
}


