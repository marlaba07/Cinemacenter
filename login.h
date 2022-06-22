#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char nombreUsuario[50];
    char password[50];
    char ubicacion[50];

} Usuario;

Usuario formularioUsuario(int opcion);
int iniciarSesion(int opcion);
void leerUsuario();
bool validarUsername(Usuario usuarioCreado);
void crearUsuario(int opcion);

