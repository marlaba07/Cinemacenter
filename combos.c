#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "combos.h"

void ingresarCombos()
{
    srand(time(NULL));

    printf("---- [ Opciones ] ---- ");
    printf("\n\n");

    int opcombo;
    char seleccion;

    printf("[1] --- Opcion 1 [Ver combo de comidas] \n");
    printf("[2] --- Opcion 2 [Ver combo entradas] \n");
    printf("[3] --- Opcion 3 [Volver al menu] \n");

    fflush(stdin);
    puts("\n");
    printf("Ingresar una opcion: ");
    scanf("%d",&opcombo);
    system("cls");

    switch(opcombo)
    {
    case 1:
        printf("---- [ COMBOS DISPONIBLES ] ---- ");

        puts("\n");
        printf("COMBO FAMILAR: ");
        printf("2 Baldes Gigantes de Pochoclos + 4 Gaseosas \n");
        printf("COMBO DUO: ");
        printf("1 Balde Gigante de Pochoclos + 2 Gaseosas \n");
        printf("\nATENCION ! llevando un 'combo familiar' obtendras un VASO DE PELICULA de regalo \n");

        puts("\n");
        printf("Ingresar COMBO de interes (Duo/Familiar): ");
        fflush(stdin);
        scanf("%s",&seleccion);
        system("cls");
        puts("SU ELECCION SE GUARDO CORRECTAMENTE ! \n");

        system("pause");
        system("cls");

        ingresarCombos();

        break;

    case 2:
        printf("---- [ DESCUENTOS DISPONIBLES ] ---- ");
        puts("\n");

        puts("[CUPON SOLO HOY] - 2x1 en salas 2D - 20% de descuento en salas 3D");
        puts("[CUPON PARA JUBILADOS] - 30% de descuento en salas 3D y 2D presentando credencial de jubilacion \n");

        printf("Que descuento desea guardar? (solo hoy/jubilados): ");
        fflush(stdin);
        scanf("%s",&seleccion);

        puts("-------------------------------------------------");
        printf("CUPON generado correctamente |%d| \n \n",rand());
        printf("Usted debera canjearlo en el cine\n");
        puts("-------------------------------------------------");

        system("pause");
        system("cls");
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
