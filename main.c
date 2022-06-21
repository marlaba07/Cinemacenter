#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "login.h"
#include <string.h>
#include <conio.h>
#include <stdbool.h>

int main()
{
    leerUsuario();

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

    bool sesion;

    switch(opcion)
    {
    case 1:
        crearUsuario(opcion);
        notificacion("");
        welcome();
        break;
    case 2:
        sesion = iniciarSesion(opcion);
        if(sesion)
        {
            menuPrincipal();
        }
        else
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
        puts("ERROR 404\n");
        puts("Debe ingresar una opcion valida");
        puts("Redireccionando...");
        sleep(3);
        system("cls");
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


