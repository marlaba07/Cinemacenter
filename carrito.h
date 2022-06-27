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
bool leerTicket(Usuario sesion);
void crearTicket(Usuario usuarioSeleccionado, Pelicula peliculaSeleccionada, Cine cineSeleccionado);
Ticket validarIDTicket(int opcion);
int contarRegistroTicket(char nombre[50]);
void gestionarTicket(int opcion, Usuario sesion);
void transaccionTicket(int opcion);
