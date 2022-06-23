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
    printf("\n[2] ---- [Crear cines]");
    printf("\n[3] ---- [Ver peliculas agregadas]");
    printf("\n[4] ---- [Ver cines agregados]");
    printf("\n[5] ---- [Cerrar sesion]");

    puts("\n");
    printf("Elegir una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    int validosPelicula;
    int validosCine;

    Cine arregloCine[] = {};

    switch(opcion)
    {
    case 1:
        validosPelicula = gestionarPeliculas();
        notificacion("");
        menuAdmin();
        break;
    case 2:
        validosCine = gestionarCines();
        notificacion("");
        menuAdmin();
        break;
    case 3:
        system("cls");
        leerPeliculas();
        break;
    case 4:
        system("cls");
        leerCines();
        break;
    case 5:
        notificacion("");
        welcome();
        break;
    default:
        printf("Error");
    }
}


/// PELICULAS

void guardarPeliculas(Pelicula pelicula)
{
    FILE * archivo;

    archivo = fopen("peliculas.bin","ab");

    if (archivo != NULL )
    {
        fwrite(&pelicula,sizeof(Pelicula),1,archivo);
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
            printf("------------------------------------------------------\n");
            printf("Nombre de la pelicula: %s\n", a.nombrePelicula);
            printf("Fecha: %s\n", a.fechaEstreno);
            printf("Genero: %s\n", a.genero);
            printf("Precio: %f\n", a.precio);
            printf("-----------------------------------------------------\n");

            printf("\n");
        }
    }
}

Pelicula formularioPelicula()
{
    Pelicula pelicula;
    int i = 0;
    char condicion = 's';

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


int gestionarPeliculas()
{
    char condicion = 's';
    int i = 0;

    while(condicion == 's')
    {
        Pelicula peliculaCreada = formularioPelicula();
        guardarPeliculas(peliculaCreada);

        i++;
        printf("Desea continuar agregando (s/n): ");
        fflush(stdin);
        scanf("%c", &condicion);
    }

    return i;
}



/// CINES

Cine formularioCine()
{
    Cine cine;
    int i = 0;
    char condicion = 's';

    printf("\nIngresar nombre del cine: ");
    fflush(stdin);
    scanf("%s", &cine.nombreCine);

    printf("Ingresar numero de sala: ");
    fflush(stdin);
    scanf("%d", &cine.numeroSala);

    return cine;
}


int gestionarCines()
{
    char condicion = 's';
    int i = 0;

    while(condicion == 's')
    {
        Cine cineCreado = formularioCine();
        guardarCines(cineCreado);

        i++;
        printf("Desea continuar agregando (s/n): ");
        fflush(stdin);
        scanf("%c", &condicion);
    }

    return i;
}


void guardarCines(Cine cine)
{
    FILE * archivo;

    archivo = fopen("cines.bin","ab");

    if (archivo != NULL )
    {
        fwrite(&cine,sizeof(Cine),1,archivo);
    }

    fclose(archivo);
}

void leerCines()
{
    Cine a;
    FILE * archivo;

    archivo = fopen("cines.bin", "rb");
    if(archivo != NULL)
    {
        while(fread(&a,sizeof(Cine),1,archivo)>0)
        {
            printf("------------------------------------------------------\n");
            printf("Nombre del cine: %s\n", a.nombreCine);
            printf("Sala nro: %s\n", a.numeroSala);
            printf("------------------------------------------------------\n");

            printf("\n");
        }
    }
}


// Acomodar tema espacios
// Ajustar seccion cines como la de las peliculas
// Agregar opción admin para que vean los cines y peliculas agregadas

