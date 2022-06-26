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

    int validos;
    int cantidad;

    Cine arregloCine[] = {};


    switch(opcion)
    {
    case 1:
        validos = gestionarPeliculas();
        notificacion("");
        menuAdmin();
        break;
    case 2:
        validos = gestionarCines();
        notificacion("");
        menuAdmin();
        break;
    case 3:
        system("cls");
        cantidad = contarRegistroPelicula("peliculas.bin");
        printf("Cantidad de peliculas: %d \n", cantidad);
        leerPeliculas();
        system("pause");
        system("cls");
        menuAdmin();
        break;
    case 4:
        system("cls");
        cantidad = contarRegistroCine("cines.bin");
        printf("Cantidad de cines: %d \n", cantidad);
        leerCines();
        system("pause");
        system("cls");
        menuAdmin();
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
            printf("ID: %d\n", a.id);
            printf("Nombre de la pelicula: %s\n", a.nombrePelicula);
            printf("Fecha: %s\n", a.fechaEstreno);
            printf("Horario: %s\n", a.horario);
            printf("Genero: %s\n", a.genero);
            printf("-----------------------------------------------------\n");

            printf("\n");
        }
    }
}

Pelicula formularioPelicula()
{
    Pelicula pelicula;
    pelicula.id = contarRegistroPelicula("peliculas.bin") + 1;

    printf("\nIngresar nombre de la pelicula: ");
    fflush(stdin);
    gets(pelicula.nombrePelicula);

    printf("Ingresar fecha: ");
    fflush(stdin);
    scanf("%s", &pelicula.fechaEstreno);

    printf("Ingresar horario: ");
    fflush(stdin);
    scanf("%s", &pelicula.horario);

    printf("Ingresar genero: ");
    fflush(stdin);
    scanf("%s", &pelicula.genero);

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
int contarRegistroPelicula(char nombre[50])
{
    int cantidad = 0;
    long tam = 0;

    FILE * archi = fopen(nombre,"rb");
    if (archi !=NULL)
    {
        fseek(archi,0,SEEK_END);
        tam = ftell(archi);
        cantidad = tam / sizeof(Pelicula);
    }

    fclose(archi);
    return cantidad;
}



/// CINES

Cine formularioCine()
{
    Cine cine;
    cine.id = contarRegistroCine("cines.bin") + 1;

    printf("\nIngresar nombre del cine: ");
    fflush(stdin);
    gets(cine.nombreCine);

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
            printf("ID: %d\n", a.id);
            printf("Nombre del cine: %s\n", a.nombreCine);
            printf("Sala nro: %d\n", a.numeroSala);
            printf("------------------------------------------------------\n");

            printf("\n");
        }
    }
}

int contarRegistroCine(char nombre[50])
{
    int cantidad = 0;
    long tam = 0;

    FILE * archi = fopen(nombre,"rb");
    if (archi !=NULL)
    {
        fseek(archi,0,SEEK_END);
        tam = ftell(archi);
        cantidad = tam / sizeof(Cine);
    }

    fclose(archi);
    return cantidad;
}

Pelicula validarIDPelicula(int opcion)
{
    Pelicula a;

    FILE * archivo;

    archivo = fopen("peliculas.bin", "rb");
    if(archivo != NULL)
    {
        while(fread(&a,sizeof(Pelicula),1,archivo)>0)
        {
            if(a.id == opcion)
            {
                return a;
            }
        }
    }

    fclose(archivo);

    return a;
}

Cine validarIDCine(int opcion)
{
    Cine a;

    FILE * archivo;

    archivo = fopen("cines.bin", "rb");
    if(archivo != NULL)
    {
        while(fread(&a,sizeof(Cine),1,archivo)>0)
        {
            if(a.id == opcion)
            {
                return a;
            }
        }
    }

    fclose(archivo);

    return a;
}



