#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "struct.h"

void menuAdmin();

void guardarPeliculas(Pelicula pelicula);
int gestionarPeliculas();
Pelicula formularioPelicula();
bool leerPeliculas();

Cine formularioCine();
int gestionarCines();
void guardarCines(Cine cine);
void leerCines();

int contarRegistroPelicula(char nombre[50]);
int contarRegistroCine(char nombre[50]);

Pelicula validarIDPelicula(int opcion);
Cine validarIDCine(int opcion);



