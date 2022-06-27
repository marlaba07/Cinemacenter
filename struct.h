#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct
{
    int id;
    char nombreUsuario[50];
    char password[50];
    char ubicacion[50];

} Usuario;

typedef struct
{
    int id;
    char nombreCine[50];
    int numeroSala;

} Cine;

typedef struct
{
    int id;
    char nombrePelicula[20];
    char fechaEstreno[20];
    char horario[30];
    char genero[10];

} Pelicula;

typedef struct
{
    int id;
    int precio;
    int cantidadEntradas;
    Usuario usuario;
    Cine cine;
    Pelicula pelicula;

} Ticket;



#endif
