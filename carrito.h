#ifndef CARRITO_H_INCLUDED
#define CARRITO_H_INCLUDED
#endif

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "admin.h"
#include "struct.h"

void guardarTicket(Ticket ticket);
void leerTicket();
void crearTicket(Pelicula peliculaSeleccionada, Cine cineSeleccionado);
Ticket validarIDTicket(int opcion);
int contarRegistroTicket(char nombre[50]);
