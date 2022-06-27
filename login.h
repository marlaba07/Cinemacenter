#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "struct.h"

Usuario formularioUsuario();
Usuario formularioLogin();
Usuario iniciarSesion(Usuario usuarioInicial);
void leerUsuario();
bool validarUsername(Usuario usuarioCreado);
void crearUsuario();
int contarRegistroUsuario(char nombre[50]);
