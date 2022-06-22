#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"

void menuAdmin()
{
    printf("---- [ MENU PARA ADMINISTRADORES ] ---- ");
    printf("\n");

    int opcion;

    printf("\n[1] ---- [Crear peliculas]");

    puts("\n");
    printf("Elegir una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    switch(opcion)
    {
    case 1:
        gestionarPeliculas();
        break;
    default:
        printf("Error");
    }
}

void guardarPeliculas(Pelicula arregloPelicula[])
{
    printf("---- [ Crear peliculas ] ---- ");
    printf("\n");

    FILE * archivo;

    archivo = fopen("peliculas.bin","ab");

    if (archivo != NULL )
    {
        for(int i = 0; i < )
        fwrite(&arregloPelicula,sizeof(Pelicula),1,archivo);
    }

    fclose(archivo);
}

void leerPeliculas()
{
    Pelicula a;
    FILE * archivo;

    archivo = fopen("peliculas.bin", "rb");
    if(archivo != NULL)
    {
        while(fread(&a,sizeof(Pelicula),1,archivo)>0)
        {
            printf("Ingresar nombre de la pelicula: %s\n", a.nombrePelicula);
            printf("Ingresar fecha: %s\n", a.fechaEstreno);
            printf("Ingresar genero: %s\n", a.genero);
            printf("Ingresar precio: %f\n", a.precio);

            printf("\n");
        }
    }
}

Pelicula formularioPelicula()
{
    Pelicula pelicula;

    printf("\nIngresar nombre de la pelicula: ");
    fflush(stdin);
    scanf("%s", &pelicula.nombrePelicula);

    printf("Ingresar fecha: ");
    fflush(stdin);
    scanf("%s", &pelicula.fechaEstreno);

    printf("Ingresar genero: ");
    fflush(stdin);
    scanf("%s", &pelicula.genero);

    printf("Ingresar precio: ");
    fflush(stdin);
    scanf("%f", &pelicula.precio);

    return pelicula;
}

void gestionarPeliculas()
{
    char condicion = 's';
    int i = 0;
    Pelicula arregloPelicula[30];
    while(condicion == 's')
    {
        Pelicula peliculaCreada = formularioPelicula();
        arregloPelicula[i] = peliculaCreada;
        guardarPeliculas(arregloPelicula);
        i++;
        printf("Desea continuar agregando (s/n): ");
        fflush(stdin);
        scanf("%c", &condicion);
    }
    leerPeliculas();
}

