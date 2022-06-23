#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "combos.h"

void ingresarCombos()
{
    srand(time(NULL));

    printf("---- [ Opciones ] ---- ");
    printf("\n");

    int opcombo;
    char seleccion;

    printf("[1] --- Opcion 1 [Ver combo de comidas] \n");
    printf("[2] --- Opcion 2 [Ver combo entradas] \n");
    printf("[3] --- Opcion 3 [Volver al menu] \n");

    fflush(stdin);
    puts("\n");
    printf("Ingresar una opción: ");
    scanf("%d",&opcombo);

    switch(opcombo)
    {
    case 1:
        printf("\nCOMBO FAMILAR:");
        printf("2 Baldes Gigantes de Pochoclos + 4 Gaseosas \n");
        printf("COMBO DUO:");
        printf("1 Balde Gigante de Pochoclos + 2 Gaseosas \n");
        printf("\nATENCION ! llevando un 'combo familiar' obtendras un BASO DE PELICULA de regalo \n");

        printf("\n Ingrese el COMBO que desea seleccionar (duo/familiar)\n");
        fflush(stdin);
        scanf("%s",&seleccion);
        system("cls");
        puts("SU COMBO SE GUARDO CORRECTAMENTE ! \n");

        ingresarCombos();

        break;
    case 2:
        printf("--DESCUENTOS DISPONILBES \n");
        puts("\n CUPON SOLO HOY! 2x1 en salas 2D - 20% de descuento en salas 3D \n");

        printf("CUPON JUBILADOS! ");
        puts("30% de descuento en salas 3D - 50% de descuento en salas 2D \n");
        puts("Que Descuento Desea Solicitar? (solo hoy/jubilados)");
        fflush(stdin);
        scanf("%s",&seleccion);
        system("cls");
        printf("CUPON generado correctamente |%d| \n \n",rand());
        ingresarCombos();
        break;
    case 3:
        system("cls");
        menuPrincipal();
        break;
    default:
        system("cls");
        puts("ERROR:seleccion incorrecta!\n");
        ingresarCombos();
    }

}
