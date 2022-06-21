#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct
{
    char nombreUsuario[50];
    char password[50];
    char ubicacion[50];

} Usuario;

typedef struct
{
    char nombrePelicula[50];
    int fecha;
    int precio;

} Pelicula;

Usuario formulario(int opcion);
bool iniciarSesion(int opcion);
void leerUsuario();
bool validarUsername(Usuario usuarioCreado);
void crearUsuario(int opcion);

