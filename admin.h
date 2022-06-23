#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char nombreCine[50];
    int numeroSala;

} Cine;

typedef struct
{
    char nombrePelicula[20];
    char fechaEstreno[20];
    char genero[10];
    float precio;

} Pelicula;

void menuAdmin();

void guardarPeliculas(Pelicula pelicula);
int gestionarPeliculas();
Pelicula formularioPelicula();
void leerPeliculas();

Cine formularioCine();
int gestionarCines();
void guardarCines(Cine cine);
void leerCines();



