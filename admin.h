#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char nombrePelicula[50];
    char fechaEstreno[20];
    char genero[10];
    float precio;

} Pelicula;

void menuAdmin();
void guardarPeliculas(Pelicula arregloPelicula[]);
void gestionarPeliculas();
Pelicula formularioPelicula();
void leerPeliculas();



