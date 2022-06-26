#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "struct.h"

Usuario formularioUsuario(int opcion);
int iniciarSesion(int opcion);
void leerUsuario();
bool validarUsername(Usuario usuarioCreado);
void crearUsuario(int opcion);

